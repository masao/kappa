# 1999.3.27 file��˥塼�� quit �� Exit ���Ѥ���
# 1999.3.27 ��³������ɥ���help��˥塼�� ��help�פ��ɲ� ���ƤϤޤ�������
# 1999.3.27 ��³������ɥ���help��˥塼�� ��Query Example�פ��ɲ�
# 1999.3.27 ��³������ɥ���file��˥塼�ˡ�New Window�פ��ɲ�
#
# 2.�ܥ���ο����Ѥ��� �ǥե���Ȥ� #C000DF00FF00
# -fg black -bg #C000DF00FF00 

# ���λ���
set DFfgcolor black
set DFbgcolor "#C000DF00FF00"
set HLfgcolor white
set HLbgcolor blue


# C����ȡ����ޥ�ɤ���Ȥꤷ�Ƥ���ؿ� ---------------------------------
. configure -bg #C000DF00FF00
proc Searchproc {cmd entry} {
    puts $cmd
    puts $entry
    set TclComandName $cmd
    set TclEntryArg $entry
    TclClientCommand
}

# ���ꤵ�줿�ե�����򥪡��ץ󤷤ơ����ꤵ�줿�ꥹ�ȥܥå����˽񤭹���ؿ�---
proc recordToListbox {filename listboxname} {
    set fd [open $filename r]
    while { [gets $fd line] >= 0 } { $listboxname insert end $line }
    close $fd
}

# ���顼��å�������Ф��� �����ץ󥦥���ɥ���Ф� �ؿ�
proc errWin_open {str} {
    toplevel .err1

    frame .err1.f -bg #C000DF00FF00
    label .err1.f.text -bg #C000DF00FF00 -fg black -text $str -relief ridge
    label .err1.f.errorimage -bg #C000DF00FF00 -fg black  -bitmap error
    pack .err1.f.text .err1.f.errorimage -in .err1.f -side left

    button .err1.fin -fg black -bg #C000DF00FF00  -text " OK ? " -command {
        destroy .err1
        #wm deiconify .topen
        popUpOpenCmd
    }
    pack .err1.f .err1.fin
}

# ���顼��å�������Ф� �ؿ�
proc errWin {str} {
    toplevel .err1

    frame .err1.f -bg #C000DF00FF00
    label .err1.f.text -bg #C000DF00FF00 -fg black -text $str -relief ridge
    label .err1.f.errorimage -bg #C000DF00FF00 -fg black  -bitmap error
    pack .err1.f.text .err1.f.errorimage -in .err1.f -side left
    
    button .err1.fin -fg black -bg #C000DF00FF00  -text " OK ? " -command {
	destroy .err1
    }
    pack .err1.f .err1.fin    
} 

proc inputShowEntry {setnum beginnum endnum} {
    .showEnter.setno delete 0 end
    .showEnter.beginno delete 0 end
    .showEnter.endno delete 0 end
    .showEnter.setno insert 0 $setnum
    .showEnter.beginno insert 0 $beginnum
    .showEnter.endno insert 0 $endnum
}

# �ۥ���̾�ʤɤξ����������롣
proc getDBInfo {filename} {
    global host
    global port
    global dbname
    global format
    global comment
    set host(default) ""
    set port(default) "210"
    set dbname(default) "Default"
    set format(default) "USMARC"
    set comment(default) ""

    set infile [ open "$filename" r ]
    set id 0
    while { [ gets $infile line ] >= 0 } {
	if { [ regexp {^z39.50s://([^/:]*):?([0-9]*)/([^#]*)#([^#]*)#?(.*)?$} $line match host($id) port($id) dbname($id) comment($id) format($id) ]} {
	    #puts "$host($id) $port($id) $dbname($id)"
	} else {
	    continue
	}
	if { ! [ string compare $port($id) "" ] } {
	    set port($id) $port(default)
	}
	incr id
    }
    close $infile
    #    puts [ parray host ] [ parray port ]
}

proc inputOpenEntry {host port DBname} {
    .topen.e0 delete 0 end
    .topen.e1 delete 0 end
    .topen.e2 delete 0 end
    .topen.e0 insert 0 $host
    .topen.e1 insert 0 $port
    .topen.e2 insert 0 $DBname
}

# ��³������ɥ������
proc popUpOpenCmd {} {
    # ���λ���
    set DFfgcolor black
    set DFbgcolor "#C000DF00FF00"
    set HLfgcolor white
    set HLbgcolor blue
    
    toplevel .topen
    wm withdraw .
    .topen configure -bg #C000DF00FF00   

    # ��˥塼�С������
    frame .topen.menubar -bg $DFbgcolor
    foreach i {file help} {
	menubutton  .topen.menubar.$i -ind true -relief flat -under 0 \
		-indicatoron false -fg $DFfgcolor -bg $DFbgcolor \
		-text $i -menu .topen.menubar.$i.menu
	# -font $fontsize
    }

    menu .topen.menubar.file.menu -fg $DFfgcolor -bg $DFbgcolor 
    # -font $fontsize
    .topen.menubar.file.menu add command -label "Exit" -command {
	destroy .
    }
    menu .topen.menubar.help.menu -fg $DFfgcolor -bg $DFbgcolor 
    # -font $fontsize
    .topen.menubar.help.menu add command -label "help" -command {
	toplevel .inithelp
	message .inithelp.textmessage -width 500 -padx 1c -pady 1c -text {������
    }

    button .inithelp.fin -text " Close Help " -command {destroy .inithelp}

    pack .inithelp.textmessage  .inithelp.fin
}
pack .topen.menubar.file -side left
pack .topen.menubar.help -side right

label .topen.l0 -fg black -bg #C000DF00FF00  \
	-relief groove -text "Host"
label .topen.l1 -fg black -bg #C000DF00FF00  \
	-relief groove -text "Port"
label .topen.l2 -fg black -bg #C000DF00FF00  \
	-relief groove -text "DataBase Name"

entry .topen.e0 -fg black -bg #C000DF00FF00  \
	-width 24 -relief sunken -textvariable openhostdata
entry .topen.e1 -fg black -bg #C000DF00FF00  \
	-width 7 -relief sunken -textvariable openportdata
entry .topen.e2 -fg black -bg #C000DF00FF00  \
	-width 16 -relief sunken -textvariable openbasedata
    
button .topen.button -fg black -bg #C000DF00FF00  \
	-bg blue -fg white -text "connect" -command {
    set openentdata "tcp:${openhostdata}:${openportdata}"
    
    destroy .topen
    #wm withdraw .topen
    wm title . ${openhostdata}:${openbasedata}
    Searchproc "open" $openentdata
    
    Searchproc "base" $openbasedata
    wm deiconify .
    focus .entEnter.inputentry
}
# ------  �ꥹ�ȥܥå������äƤ�����ʬ (2��) --------------

listbox .topen.li0 -fg black -bg #C000DF00FF00  \
	-relief groove -width 60 -height 17 \
	-yscrollcommand ".topen.s1 set" -xscrollcommand ".topen.s2 set"
global host
global port
global dbname
global format
global comment
set basedir [ file dirname [ info script ] ]
getDBInfo "$basedir/opensite"
# puts [parray comment]
set size [ array size comment ]
set i "0"
while { $i < $size-1 } {
    .topen.li0 insert end "$comment($i)"
    incr i
}

bind .topen.li0 <ButtonRelease-1> {
    set id [ .topen.li0 curselection ]
    inputOpenEntry "$host($id)" "$port($id)" "$dbname($id)"
    if { [ string compare $format($id) "" ] } {
	Searchproc "format" $format($id)
	.showEnter.recordSyntax configure -text "$format($id)"
    }
}
#.topen.li0 insert 0 "aladdin (zwais)"
#.topen.li0 insert 1 "AGRICOLA"
#.topen.li0 insert 2 "dranet"
#.topen.li0 insert 3 "Univercity of Wisconsin-madison"

    scrollbar .topen.s1 -bg #C000DF00FF00 \
	    -orient vertical  -command ".topen.li0 yview"
    scrollbar .topen.s2 -bg #C000DF00FF00 \
	    -orient horizontal  -command ".topen.li0 xview"
    # -orient ��������С��θ���  vertical ��  horizontal ��
    
#    button .topen.fin -fg black -bg #C000DF00FF00 \
#	    -text "exit " -command {destroy .}
#    .topen.fin conf -font "-*-*-*-*-*-24-*"
    message .topen.m -fg black -bg #C000DF00FF00 -relief sunken -text ""
    #    pack .topen.aladdin .topen.agricora .entEnter .topen.fin .topen.m

    grid .topen.menubar -row 0 -column 0 -columnspan 4 -sticky ew

    grid .topen.l0 -row 1 -column 1 -sticky ew
    grid .topen.l1 -row 1 -column 2 -sticky ew
    grid .topen.l2 -row 1 -column 3 -sticky ew
   
    grid .topen.button -row 2 -column 0 -sticky ew
    grid .topen.e0 -row 2 -column 1 -sticky ew
    grid .topen.e1 -row 2 -column 2 -sticky ew
    grid .topen.e2 -row 2 -column 3 -sticky ew


    grid .topen.li0 -row 3 -column 0 -columnspan 4 -sticky nsew
    grid .topen.s1 -row 3 -column 4 -sticky ns

    grid .topen.s2 -row 4 -column 0 -columnspan 4 -sticky ew

    #�ꥹ�ȥܥå����Τ���Ԥ�
    #�ʥ�����ɥ��򹭤������˥ꥹ�ȥܥå������礭���������礭�����뤿���
    grid rowconfigure .topen 3 -weight 100
    #�ꥹ�ȥܥå����Τ�����ˡʾ�ιԤ�Ʊ��ͳ��
    grid columnconfigure .topen 0 -weight 100
    grid columnconfigure .topen 1 -weight 100
    grid columnconfigure .topen 2 -weight 100
    grid columnconfigure .topen 3 -weight 100   
    
    #grid .topen.fin -row 4 -column 0 -columnspan 4 -sticky ew
    #grid .topen.m -row 5 -column 0 -sticky ew
    #button .topen.debag -text " show search window (�ǥХå���) " -command {
	#destroy .topen
	#wm deiconify .
	#}
	#grid .topen.debag -row 4 -column 0 -columnspan 4 -sticky ew
	
}

# ------ entry �ե졼���������Ƥ���Ȥ��� --------------------------------- 
#set entdata ""
frame .entEnter -bg #C000DF00FF00
label .entEnter.inputlabel -fg black -bg #C000DF00FF00 -text " Query:" 
#.entEnter.inputlabel conf -font "-*-*-*-*-*-20-*" 
entry .entEnter.inputentry -fg white -bg blue \
	-width 40 -relief sunken -textvariable entdata 
#.entEnter.inputentry conf -font "-*-*-*-*-*-20-*"
#-fg black -bg #C000DF00FF00
button .entEnter.clear -fg black -bg #C000DF00FF00 -text clear -command {
    .entEnter.inputentry delete 0 end
}
pack .entEnter.inputlabel .entEnter.inputentry  .entEnter.clear -in .entEnter -side left

frame .showEnter -bg #C000DF00FF00
label .showEnter.label1 -fg black -bg #C000DF00FF00  -text "\["
label .showEnter.label2 -fg black -bg #C000DF00FF00  -text "\] No"
label .showEnter.label3 -fg black -bg #C000DF00FF00  -text "�� No"
label .showEnter.label4 -fg black -bg #C000DF00FF00  -text "  "
entry .showEnter.setno -fg black -bg #C000DF00FF00 \
	-width 4 -relief sunken -textvariable setnodata
entry  .showEnter.beginno -fg black -bg #C000DF00FF00  \
	-width 6 -relief sunken -textvariable beginnodata
entry .showEnter.endno -fg black -bg #C000DF00FF00  \
	-width 6 -relief sunken -textvariable endnodata

#menubutton  .showEnter.recordSyntax -ind true -relief raised\
#        -text "usmarc" -menu .showEnter.recordSyntax.menu \
#        -fg $DFfgcolor -bg $DFbgcolor 
#        # -font $fontsize
#menu .showEnter.recordSyntax.menu -fg $DFfgcolor -bg $DFbgcolor
## -font $fontsize
#foreach i {usmarc sutrs danmarc ukmarc grs1 soif summary explain} {
#    .showEnter.recordSyntax.menu add command -label $i -command {
#        .showEnter.recordSyntax configure -text $i
#        Searchproc "format" $i
#    }
#}

menubutton  .showEnter.recordSyntax -ind true -relief raised\
	-text "USMARC" -menu .showEnter.recordSyntax.menu -fg black -bg #C000DF00FF00
menu .showEnter.recordSyntax.menu -fg black -bg #C000DF00FF00
.showEnter.recordSyntax.menu add command -label "USMARC" -command {
    .showEnter.recordSyntax configure -text "USMARC"
    Searchproc "format" "usmarc"
}
.showEnter.recordSyntax.menu add command -label "SUTRS" -command {
    .showEnter.recordSyntax configure -text "SUTRS"
    Searchproc "format" "sutrs"
}
.showEnter.recordSyntax.menu add command -label "DANMARC" -command {
    .showEnter.recordSyntax configure -text "DANMARC"
    Searchproc "format" "danmarc"
}
.showEnter.recordSyntax.menu add command -label "UKMARC" -command {
    .showEnter.recordSyntax configure -text "UKMARC"
    Searchproc "format" "ukmarc"
}
.showEnter.recordSyntax.menu add command -label "GRS1" -command {
    .showEnter.recordSyntax configure -text "GRS1"
    Searchproc "format" "grs1"
}     
.showEnter.recordSyntax.menu add command -label "SOIF" -command {
    .showEnter.recordSyntax configure -text "SOIF"
    Searchproc "format" "soif"
}
.showEnter.recordSyntax.menu add command -label "Summary" -command {
    .showEnter.recordSyntax configure -text "Summary"
    Searchproc "format" "summary"
}
.showEnter.recordSyntax.menu add command -label "Explain" -command {
    .showEnter.recordSyntax configure -text "Explain"
    Searchproc "format" "explain"
}
set element F
radiobutton .showEnter.full -text "Full" -value F -variable element \
	-bg #C000DF00FF00
radiobutton .showEnter.burief -text "Brief" -value B  -variable element \
	-bg #C000DF00FF00
pack  .showEnter.label1  .showEnter.setno  .showEnter.label2 \
	.showEnter.beginno  .showEnter.label3  .showEnter.endno \
	.showEnter.label4 \
	.showEnter.full .showEnter.burief .showEnter.recordSyntax -side left

# -------------------- entry �ե졼������ ����--------------------------

# -------------------- �ܥ����������Ƥ���Ȥ��� -----------------------
button .open -fg white -bg blue -text connect -command {popUpOpenCmd}
button .find -fg black -bg #C000DF00FF00 -text search -command {
    .find configure -fg black -bg #C000DF00FF00
    .entEnter.inputentry configure -fg black -bg #C000DF00FF00
    .show configure -fg white -bg blue
    set lastline0 [.l0 index end]
    Searchproc "find" $entdata
    .l0 yview $lastline0
    #Searchproc "find" [toYazSyntax $entdata]
    #.entEnter.inputentry delete 0 end
}


bind .entEnter.inputentry <KeyPress> {
    .find configure -fg white -bg blue
    .entEnter.inputentry configure -fg white -bg blue
    .show configure -fg black -bg #C000DF00FF00
}

bind .entEnter.inputentry <Key-Return> {
    .find configure -fg black -bg #C000DF00FF00
    .entEnter.inputentry configure -fg black -bg #C000DF00FF00
    .show configure -fg white -bg blue
    set lastline0 [.l0 index end]
    Searchproc "find" $entdata
    #.entEnter.inputentry delete 0 end
    .l0 yview $lastline0
}
#button .show -fg black -bg #C000DF00FF00 -text show -command {popUpShowCmd}
button .show  -fg black -bg #C000DF00FF00 -text show -command {
    .show configure -fg black -bg #C000DF00FF00
    .find configure -fg black -bg #C000DF00FF00
    .entEnter.inputentry configure -fg white -bg blue
    set lastline1 [.l1 index end]
    set count [expr ${endnodata}-${beginnodata}+1]
    Searchproc "elements" $element
    Searchproc "show" "${beginnodata}+${count}@${setnodata}"
    .l1 yview $lastline1
}
#��˥塼�С������ 
frame .menubar -bg $DFbgcolor
foreach i {file connect help} {
        menubutton  .menubar.$i -ind true -relief flat -under 0 \
        -indicatoron false -fg $DFfgcolor -bg $DFbgcolor \
	-text $i -menu .menubar.$i.menu
        # -font $fontsize
}
pack .menubar.file .menubar.connect -side left
pack .menubar.help -side right
# ��˥塼�С������ �����ޤ�

# �������� �ƥ�˥塼�����
# file ��˥塼�����
menu .menubar.file.menu -fg black -bg #C000DF00FF00
# �ʲ� 3�ԤΥ����ȥ����Ȥ򳰤��ȡ�
# ��������³������ɥ�����³���ڤ餺�˽ФƤ���
.menubar.file.menu add command -label "New Window" -command {
     exec ./kappa &
}
.menubar.file.menu add command -label "Exit" -command {
    Searchproc "quit" ""
}

# connect ��˥塼
menu .menubar.connect.menu -fg black -bg #C000DF00FF00
.menubar.connect.menu add command -label "Disconnect" -command {
    Searchproc "close" ""
}
# help ��˥塼
menu .menubar.help.menu -fg black -bg #C000DF00FF00
.menubar.help.menu add command -label "Query Example " -command {

toplevel .queryexample

message .queryexample.textmessage -width 500 -padx 1c -pady 1c -text {
�ֿ޽�פ򸡺�
      �޽�

�ֽ�̾�˥��饹�פ򸡺�
      ti="���饹"

������̾�����ڡפ򸡺�
      au="����"

1���ܤ�2���ܤθ�����̽����AND����
      set=1 and set=2

}

button .queryexample.fin -text " Close Query Example " -command {destroy .queryexample}

pack .queryexample.textmessage  .queryexample.fin


}
#button .quit -fg black -bg #C000DF00FF00 \
#	-text quit -command {Searchproc "quit" $entdata}



#menubutton  .view_mb -ind true -relief flat -under 0  -indicatoron false\
#	-text "view" -menu .view_mb.menu -fg black -bg #C000DF00FF00
#menu .view_mb.menu -fg black -bg #C000DF00FF00
#.view_mb.menu add command -label "Larg Font" -command {
#.entEnter.inputlabel conf -font "-*-*-*-*-*-20-*" 
#.entEnter.inputentry conf -font "-*-*-*-*-*-20-*"
#}
#.view_mb.menu add command -label "Normal Font" -command {
#.entEnter.inputlabel conf -font "-user-medium-r-normal-m*-*-*-*-*-*-*-*-*"
#.entEnter.inputentry conf -font "-*-*-*-*-*-14-*"
#}
# -------------------�ܥ�������� ����--------------------------

# ------  �ꥹ�ȥܥå������äƤ�����ʬ (2��) --------------

listbox .l0 -bg #C000DF00FF00 -fg black  \
	-relief groove -width 60 -height 5 \
	-yscrollcommand ".s1 set" -xscrollcommand ".s2 set"
scrollbar .s1 -bg #C000DF00FF00 \
	-orient vertical  -command ".l0 yview"
scrollbar .s2 -bg #C000DF00FF00 \
	-orient horizontal  -command ".l0 xview"
# -orient ��������С��θ���  vertical ��  horizontal ��

# �ꥹ�Ȥǻ��ꤹ��ȡ����ꤷ���Ȥ���� show �����򸡺����Ǥ���
# ���ꤷ���Ȥ��� "@set number" ������������ȥ꡼�����Ϥ���� (add 12/10)
bind .l0 <ButtonRelease-1> {
# show ����ȥ꡼�� 
    set setnum [expr [.l0 curselection] + 1]
    set liststr [.l0 get [.l0 curselection]]
    set flagb [expr [string last ":" $liststr] + 1]
    set flage [expr [string last "\n" $liststr] -1]
    set endnumber [string range $liststr $flagb $flage]
    if { $endnumber > 30} {
	set endnumber 30
    }
    inputShowEntry $setnum 1 $endnumber

# �طʿ����ѹ�
    .find configure -fg black -bg #C000DF00FF00
    .entEnter.inputentry configure -fg black -bg #C000DF00FF00
    .show configure -fg white -bg blue
}

bind .l0 <ButtonRelease-3> {
    set setnum [expr [.l0 curselection] + 1]
# ��������ȥ꡼��
    set buf " set="
    set queryterm $buf$setnum
    .entEnter.inputentry insert insert $queryterm

# �طʿ����ѹ�
    .show configure -fg black -bg #C000DF00FF00
    .entEnter.inputentry configure -fg white -bg blue
    .find configure -fg white -bg blue

}

listbox .l1 -fg black -bg #C000DF00FF00 \
	-relief groove -width 60 -height 14 \
	-yscrollcommand ".s3 set" -xscrollcommand ".s4 set"
scrollbar .s3 -bg #C000DF00FF00 \
	-orient vertical  -command ".l1 yview"
scrollbar .s4 -bg #C000DF00FF00 \
	-orient horizontal  -command ".l1 xview"

# ------  �ꥹ�ȥܥå��� ���� -------------------------

# ------  ��å����� ----------------------------------
message .m -fg black -bg #C000DF00FF00  -relief sunken -text ""
# ------  ��å����� ���� ----------------------------------
#----------------  ����   ----------------------
#grid .open -row 0 -column 0 -columnspan 3 -sticky ew
grid .menubar -row 0 -column 0 -columnspan 3 -sticky ew
grid .find -row 1 -column 0 -columnspan 2 -sticky ew
grid .entEnter -row 1 -column 2 -columnspan 2 -sticky ew
#grid .clear -row 1 -column 3 -columnspan 1 -sticky ew
grid .show -row 2 -column 0 -columnspan 2 -sticky ew
grid .showEnter -row 2 -column 2 -columnspan 2 -sticky ew

grid .l0 -row 3 -column 0 -columnspan 3 -sticky nsew
grid .s1 -row 3 -column 3 -sticky ns
grid .s2 -row 4 -column 0 -columnspan 3 -sticky ew
grid .l1 -row 5 -column 0 -columnspan 3 -sticky nsew
grid .s3 -row 5 -column 3 -sticky ns
grid .s4 -row 6 -column 0 -columnspan 3 -sticky ew

#�ꥹ�ȥܥå����Τ���Ԥ�
#�ʥ�����ɥ��򹭤������˥ꥹ�ȥܥå������礭���������礭�����뤿���
grid rowconfigure . 3 -weight 100
grid rowconfigure . 5 -weight 100
#�ꥹ�ȥܥå����Τ�����ˡʾ�ιԤ�Ʊ��ͳ��
grid columnconfigure . 0 -weight 100
grid columnconfigure . 1 -weight 100
grid columnconfigure . 2 -weight 100

popUpOpenCmd

# �ǥ��Ѥ˥�����ɥ��Υ����������֤���ꤹ�롣
#    set mywidth [winfo width .topen]
#    set myheight [winfo height .topen]
#    puts [winfo geometry .]
#    puts [winfo geometry .topen]
wm geometry . 681x607+200+100
wm geometry .topen 633x518+220+120
#-------------------  ���ֽ��� -------------------
