#!/bin/sh
# the next line restarts using wish \
exec wish "$0" "$@"
# HTML�饤�֥����ɤ߹���
source [file dirname [info script]]/html_library.tcl

# �������
proc Init {} {
    global w
    set w(size) 0
    set w(indent) 1.2
#    set w(home) [ file dirname [ info script ] ]/index.html
    set w(home) http://cosmo.ulis.ac.jp/~yuka/wkappa/index.html
    set w(url) $w(home)
    set w(message) "";
}
# ʸ����ɤ߹���
proc LoadFile {} {
    global w
    set ftypes {
        {"Text File"    {.htm .html} }
        {"All files"    *}
    }
    set fname [tk_getOpenFile -filetypes $ftypes -parent .]
    if {$fname == ""} {
        return
    } else {
	Disp_Html $fname
    }
}
# ��˥塼�С�
proc MakeMenu {} {
    global w
    # ��˥塼�С��ѥե졼��
    set w(menu) .menu
    frame $w(menu) -borderwidth 2 -relief raised 
    pack $w(menu) -side top -fill x
    # ��˥塼
    set w(file) $w(menu).file
    menubutton $w(file) -text "�ե�����" -menu $w(file).m
    pack $w(file) -side left
    # �ե�����
    menu $w(file).m -tearoff no
    $w(file).m add command -label "�ե��������ꤷ�Ƴ���" -command LoadFile
    $w(file).m add separator
    $w(file).m add command -label "��λ" -command exit
} 
# ����ȥ�
proc MakeEntry {} {
    global w
    # ����ȥ�Υե졼��
    set w(sub1) .fra1
    frame $w(sub1) -borderwidth 2 -relief ridge
    pack $w(sub1) -side top -fill x -expand no
    # ����ȥ�
    set w(label) $w(sub1).lab
    label $w(label) -text "URL"
    set w(ent) $w(sub1).ent
    entry $w(ent) -textvariable w(url) -bg white
    pack $w(label) -side left 
    pack $w(ent) -side left -fill x -expand yes
    bind $w(ent) <Key-Return> {
	HMlink_callback $w(text) $w(url)
    }
}
# �ƥ�����
proc MakeText {} {
    global w
    # �ƥ����ȤΥե졼��
    set w(main) .fra2
    frame $w(main) -borderwidth 2 -relief sunken
    pack $w(main) -side top -fill both -expand yes
    # �ƥ����Ȥȥ�������С�
    set w(text) $w(main).txt
    text $w(text) -cursor hand2 -yscrollcommand "$w(main).scrl set"
    scrollbar $w(main).scrl -command "$w(text) yview"
    pack $w(main).scrl -side right -fill y
    pack $w(text) -side left -fill both -expand yes
}
# ��å�����
proc MakeMessage {} {
    global w
    # ��å������Υե졼��
    set w(sub2) .fra3
    frame $w(sub2) -borderwidth 2 -relief ridge
    pack $w(sub2) -side top -fill both -expand no
    set w(mes) $w(sub2).mes
    label $w(mes) -textvariable w(message)
    pack $w(mes) -side left -fill both -expand yes
}
# HTML ʸ���ɽ��
proc Disp_Html { file } {
    global w HM.text
    $w(text) config -state normal
    set fragment ""
    regexp {([^#]*)#(.+)} $file dummy file fragment
    if { $file == "" && $fragment != "" } {
	HMgoto $w(text) $fragment
	$w(text) config -state disabled
	return
    }
    HMreset_win $w(text)
    set w(message) "$file ��ɽ�����Ƥ��ޤ���"
    update idletasks
    if { $fragment != "" } {
	HMgoto $w(text) $fragment
    }
    set w(url) $file
    HMparse_html [ Load_Html $file ] "HMrender $w(text)"
    HMset_state $w(text) -stop 1
    set w(message) ""
    $w(text) config -state disabled
}
# HTML �ե�������ɤ߹���
proc Load_Html { file } {
    global w

    if {[ string match http://* $file ]} {
	# file is HTTP-accessible on network.
	package require http
	puts "Retrieving $file ..."
	set token [::http::geturl $file]
	::http::wait $token
	puts "done"
	return [::http::data $token]
    }
    if { [ catch { set fileid [ open $file ] } msg ] } {
	return "
	<title>$file �Ϸ������ְ�äƤ��ޤ���</title>
	<h1>$file ���ɤ߹��ߥ��顼�Ǥ���</h1><p>
	$msg<hr>
	<a href=$w(home)>Go home</a>
	"
    }
    set result [ read $fileid ]
    close $fileid
    return $result
}
# �����ذ�ư
proc HMlink_callback { win href } {
    global w
    if { [ string match http://* $href ] } {
	# puts "HTTP Protocol Not support !!"
	# exit
	set w(url) $href
	update
	Disp_Html $w(url)
	return
    }
    if { [string match z39.50s://* $href] } {
	exec kappa $href &
	return
    }
    if { [ string match #* $href ] } {
	Disp_Html $href
	return
    }
    if { [ string match /* $href ] } {
	set w(url) $href
    } else {
	set w(url) [ file dirname $w(url) ]/$href
    }
    update
    Disp_Html $w(url)
}
# ���᡼���ν���
proc HMset_image {win handle src} {
    global w
    if { [ string match /* $src ] } {
	set image $src
    } else {
	set image [ file dirname $w(url) ]/$src
    }
    set w(message) "���᡼�� $image ���ɤ߹���Ǥ��ޤ���"
    update
    if { [string first " $image " " [image names] " ] >= 0 } {
	HMgot_image $handle $image
    } else {
	set type photo
	if { [ file extension $image ] == ".bmp" } { set type bitmap }
	catch { image create $type $image -file $image } image
	HMgot_image $handle $image
    }
}
# --------
#  �ᥤ��
# --------
Init
MakeMenu
MakeEntry
MakeText
MakeMessage
#
HMinit_win $w(text)
HMset_state $w(text) -size $w(size)
HMset_indent $w(text) $w(indent)
Disp_Html $w(home)
# 
