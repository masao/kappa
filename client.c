/*
 *  1999.3.27
 *  ヒットした件数が30件以上だったら showエントリには30を入力するように変更 
 *  
 *   1997.10.14
 *  Usmarc は、リストボックスに表示できるように
 *  
 *
 */

/*
 * Copyright (c) 1995-1998, Index Data.
 * See the file LICENSE for details.
 * Sebastian Hammer, Adam Dickmeiss
 *
 * $Log$
 * Revision 1.60  1998/01/29 14:08:52  adam
 * Better sort diagnostics.
 *
 * Revision 1.59  1998/01/29 13:17:56  adam
 * Added sort.
 *
 * Revision 1.58  1998/01/07 13:51:45  adam
 * Minor change.
 *
 * Revision 1.57  1998/01/07 12:58:22  adam
 * Using fgets instead of gets.
 *
 * Revision 1.56  1997/11/05 09:18:31  adam
 * The client handles records with no associated syntax.
 *
 * Revision 1.55  1997/10/31 12:20:08  adam
 * Improved memory debugging for xmalloc/nmem.c. References to NMEM
 * instead of ODR in n ESPEC-1 handling in source d1_espec.c.
 * Bug fix: missing fclose in data1_read_espec1.
 *
 * Revision 1.54  1997/10/27 13:52:46  adam
 * Header yaz-util includes all YAZ utility header files.
 *
 * Revision 1.53  1997/09/29 13:18:59  adam
 * Added function, oid_ent_to_oid, to replace the function
 * oid_getoidbyent, which is not thread safe.
 *
 * Revision 1.52  1997/09/29 07:20:31  adam
 * Client code uses nmem_init.
 *
 * Revision 1.51  1997/09/26 09:41:55  adam
 * Updated client to handle multiple diagnostics.
 *
 * Revision 1.50  1997/09/17 12:10:29  adam
 * YAZ version 1.4.
 *
 * Revision 1.49  1997/09/04 13:45:17  adam
 * Added UNImarc to list of available syntaxes.
 *
 * Revision 1.48  1997/09/01 08:48:44  adam
 * New windows NT/95 port using MSV5.0. Only a few changes made
 * to avoid warnings. Sub project created: client.dsp.
 *
 * Revision 1.47  1997/07/01 13:49:56  adam
 * Take care of case when invalid target is specified on command line.
 *
 * Revision 1.46  1997/06/23 10:30:18  adam
 * Added call to ccl_rpn_delete in search. Added ODR stream "out"
 * as parameter to ccl_rpn_query to release RPN query.
 *
 * Revision 1.45  1997/05/14 06:53:29  adam
 * C++ support.
 *
 * Revision 1.44  1997/05/05 11:20:35  adam
 * Client uses "options" utility and marc dump filename may be specified
 * as an option (-m <file>).
 *
 * Revision 1.43  1996/11/08 11:03:26  adam
 * Client accepts multiple database names.
 *
 * Revision 1.42  1996/10/08 10:44:57  quinn
 * Resolved conflicts.
 *
 * Revision 1.41  1996/10/07  15:29:03  quinn
 * Work
 *
 * Revision 1.40  1996/08/29  14:19:34  quinn
 * Fixed conflict (CVS)
 *
 * Revision 1.39  1996/08/27  10:43:22  quinn
 * Made select() optional
 *
 * Revision 1.38  1996/08/12  14:09:11  adam
 * Default prefix query attribute set defined by using p_query_attset.
 *
 * Revision 1.37  1996/07/06  19:58:29  quinn
 * System headerfiles gathered in yconfig
 *
 * Revision 1.36  1996/06/10  08:53:47  quinn
 * Added Summary
 *
 * Revision 1.35  1996/06/03  09:45:50  quinn
 * Added display of OIDs in the GRS routine.
 *
 * Revision 1.34  1996/05/09  07:26:49  quinn
 * *** empty log message ***
 *
 * Revision 1.33  1996/05/09  07:25:22  quinn
 * Small
 *
 * Revision 1.32  1996/03/15  11:05:33  adam
 * The user can set the preferred query type (prefix, ccl, ..) with the
 * querytype command.
 *
 * Revision 1.31  1996/02/20  12:51:54  quinn
 * Fixed problems with EXTERNAL.
 *
 * Revision 1.30  1996/02/12  18:18:09  quinn
 * Fidgeting.
 *
 * Revision 1.29  1996/01/02  08:57:25  quinn
 * Changed enums in the ASN.1 .h files to #defines. Changed oident.class to oclass
 *
 * Revision 1.28  1995/12/14  11:09:31  quinn
 * Added Explain record syntax to the format command.
 *
 * Revision 1.27  1995/12/12  16:37:02  quinn
 * Added destroy element to data1_node.
 *
 * Revision 1.26  1995/12/12  14:11:00  quinn
 * Minimal.
 *
 * Revision 1.25  1995/11/13  09:27:22  quinn
 * Fiddling with the variant stuff.
 *
 * Revision 1.24  1995/10/30  12:41:13  quinn
 * Added hostname lookup for server.
 *
 * Revision 1.23  1995/10/18  16:12:30  quinn
 * Better diagnostics.
 *
 * Revision 1.22  1995/10/11  14:49:12  quinn
 * Smallish.
 *
 * Revision 1.21  1995/09/29  17:01:47  quinn
 * More Windows work
 *
 * Revision 1.20  1995/08/29  14:24:13  quinn
 * Added second half of close-handshake
 *
 * Revision 1.19  1995/08/29  11:17:28  quinn
 * Added code to receive close
 *
 * Revision 1.18  1995/08/28  12:21:27  quinn
 * Client can now ask for simple element set names.
 *
 * Revision 1.17  1995/08/17  12:45:02  quinn
 * Fixed minor problems with GRS-1. Added support in c&s.
 *
 * Revision 1.16  1995/08/15  12:00:04  quinn
 * Updated External
 *
 * Revision 1.15  1995/06/22  09:28:03  quinn
 * Fixed bug in SUTRS processing.
 *
 * Revision 1.14  1995/06/19  12:37:41  quinn
 * Added BER dumper.
 *
 * Revision 1.13  1995/06/16  10:29:11  quinn
 * *** empty log message ***
 *
 * Revision 1.12  1995/06/15  07:44:57  quinn
 * Moving to v3.
 *
 * Revision 1.11  1995/06/14  15:26:40  quinn
 * *** empty log message ***
 *
 * Revision 1.10  1995/06/06  14:56:58  quinn
 * Better diagnostics.
 *
 * Revision 1.9  1995/06/06  08:15:19  quinn
 * Cosmetic.
 *
 * Revision 1.8  1995/06/05  10:52:22  quinn
 * Added SCAN.
 *
 * Revision 1.7  1995/06/02  09:50:09  quinn
 * Smallish.
 *
 * Revision 1.6  1995/05/31  08:29:21  quinn
 * Nothing significant.
 *
 * Revision 1.5  1995/05/29  08:10:47  quinn
 * Moved oid.c to util.
 *
 * Revision 1.4  1995/05/22  15:30:13  adam
 * Client uses prefix query notation.
 *
 * Revision 1.3  1995/05/22  15:06:53  quinn
 * *** empty log message ***
 *
 * Revision 1.2  1995/05/22  14:56:40  quinn
 * *** empty log message ***
 *
 * Revision 1.1  1995/05/22  11:30:31  quinn
 * Added prettier client.
 *
 *
 */

/*
 * This is the obligatory little toy client, whose primary purpose is
 * to illustrate the use of the YAZ service-level API.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include <yaz-util.h>

#include <comstack.h>
#include <tcpip.h>
#ifdef USE_XTIMOSI
#include <xmosi.h>
#endif

#include <proto.h>
#include <marcdisp.h>
#include <diagbib1.h>

#include <pquery.h>

#if CCL2RPN
#include <yaz-ccl.h>
#endif

/* TclTk */
#include <tcl.h>
#include <tk.h>
#include <stdarg.h>

#include "version.h"

#define TMPDIR "/tmp"
#define PROGNAME "kappa"

/* TclTk */
static char *TclCmdName = "TclClientCommand";
static int tclCommandCallback( ClientData cd, 
			int argc, char *argv[]);

static int tclPrintf(char *str,int lnum);
void reverse(char s[]);
void itoa(int n,char s[]);
Tcl_Interp *interp;
FILE *tcldump;
char tcldumpfilename[30];
static int show_start_position;
int buf_setnumber; /* show の時に必要 */

static ODR out, in, print;              /* encoding and decoding streams */
static COMSTACK conn = 0;               /* our z-association */
static Z_IdAuthentication *auth = 0;    /* our current auth definition */
static char *databaseNames[128];
static int num_databaseNames = 0;
static int setnumber = 0;               /* current result set number */
static int smallSetUpperBound = 0;
static int largeSetLowerBound = 1;
static int mediumSetPresentNumber = 0;
static Z_ElementSetNames *elementSetNames = 0; 
static int setno = 1;                   /* current set offset */
static int protocol = PROTO_Z3950;      /* current app protocol */
static int recordsyntax = VAL_USMARC;
static int sent_close = 0;
static ODR_MEM session_mem;             /* memory handle for init-response */
static Z_InitResponse *session = 0;     /* session parameters */
static char last_scan[512] = "0";
static char last_cmd[100] = "?";
static FILE *marcdump = 0;

typedef enum {
    QueryType_Prefix,
    QueryType_CCL,
    QueryType_CCL2RPN
} QueryType;

/* static QueryType queryType = QueryType_Prefix; */
static QueryType queryType =  QueryType_CCL2RPN;

#if CCL2RPN
static CCL_bibset bibset;               /* CCL bibset handle */
#endif

static void send_apdu(Z_APDU *a)
{
    char *buf;
    int len;
    
    if (!z_APDU(out, &a, 0)) {
        odr_perror(out, "Encoding APDU");
        exit(1);
    }
    buf = odr_getbuf(out, &len, 0);
    odr_reset(out); /* release the APDU structure  */
    if (cs_put(conn, buf, len) < 0) {
        fprintf(stderr, "cs_put: %s", cs_errmsg(cs_errno(conn)));
        exit(1);
    }
}

/* INIT SERVICE ------------------------------- */

static void send_initRequest()
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_initRequest);
    Z_InitRequest *req = apdu->u.initRequest;

    ODR_MASK_SET(req->options, Z_Options_search);
    ODR_MASK_SET(req->options, Z_Options_present);
    ODR_MASK_SET(req->options, Z_Options_namedResultSets);
    ODR_MASK_SET(req->options, Z_Options_triggerResourceCtrl);
    ODR_MASK_SET(req->options, Z_Options_scan);
    ODR_MASK_SET(req->options, Z_Options_sort);

    ODR_MASK_SET(req->protocolVersion, Z_ProtocolVersion_1);
    ODR_MASK_SET(req->protocolVersion, Z_ProtocolVersion_2);
    ODR_MASK_SET(req->protocolVersion, Z_ProtocolVersion_3);

    *req->maximumRecordSize = 1024*1024;
    
    req->implementationName = CLIENT_NAME;
    req->implementationVersion = CLIENT_VERSION;

    req->idAuthentication = auth;

    send_apdu(apdu);
    printf("Sent initrequest.\n");
}

static int process_initResponse(Z_InitResponse *res)
{
    /* save session parameters for later use */
    session_mem = odr_extract_mem(in);
    session = res;

    if (!*res->result)
        printf("Connection rejected by target.\n");
    else
        printf("Connection accepted by target.\n");
    if (res->implementationId)
        printf("ID     : %s\n", res->implementationId);
    if (res->implementationName)
        printf("Name   : %s\n", res->implementationName);
    if (res->implementationVersion)
        printf("Version: %s\n", res->implementationVersion);
    if (res->userInformationField) {
        printf("UserInformationfield:\n");
        if (!z_External(print, (Z_External**)&res-> userInformationField, 0)) {
            odr_perror(print, "Printing userinfo\n");
            odr_reset(print);
        }
        if (res->userInformationField->which == Z_External_octet) {
            printf("Guessing visiblestring:\n");
            printf("'%s'\n", res->userInformationField->u. octet_aligned->buf);
        }
    }
    return 0;
}

int cmd_open(char *arg)
{
    void *add;
    char type[100], addr[100];
    CS_TYPE t;
    char tcl_buf[100];

    if (conn) {
	/* printf("Already connected.\n");*/
	tclPrintf("Already connected.",4);
        return 0;
    }
    if (!*arg || sscanf(arg, "%[^:]:%s", type, addr) < 2) {
        /*fprintf(stderr, "Usage: open (osi|tcp) ':' [tsel '/']host[':'port]\n");*/
	tclPrintf("Usage: open (osi|tcp) ':' [tsel '/']host[':'port]",4);
        return 0;
    }
    if (!strcmp(type, "tcp")) {
	t = tcpip_type;
	protocol = PROTO_Z3950;
    }
    else
#ifdef USE_XTIMOSI
    if (!strcmp(type, "osi")) {
        t = mosi_type;
        protocol = PROTO_SR;
    }
    else
#endif
    {
        sprintf(tcl_buf, "Bad type: %s\n", type);
	tclPrintf(tcl_buf,4);
	return 0;
    }
    if (!(conn = cs_create(t, 1, protocol))) {
        perror("cs_create");
	tclPrintf("Cannot connect",4);
        return 0;
    }
    if (!(add = cs_straddr(conn, addr))) {
	perror(arg);
	tclPrintf("cannot open",4);
	return 0;
    }
    printf("Connecting...");
    fflush(stdout);
    if (cs_connect(conn, add) < 0) {
        perror("connect");
	tclPrintf("connection error occured",4);
        cs_close(conn);
        conn = 0;
        return 0;
    }
    printf("Ok.\n");
    send_initRequest();
    return 2;
}

int cmd_authentication(char *arg)
{
    static Z_IdAuthentication au;
    static char open[256];

    if (!*arg) {
        printf("Auth field set to null\n");
        auth = 0;
        return 1;
    }
    auth = &au;
    au.which = Z_IdAuthentication_open;
    au.u.open = open;
    strcpy(open, arg);
    return 1;
}

/* SEARCH SERVICE ------------------------------ */

static void display_variant(Z_Variant *v, int level, FILE *fp)
{
    int i;

    for (i = 0; i < v->num_triples; i++) {
        fprintf(fp,"%*sclass=%d,type=%d", level * 4, "",
		*v->triples[i]->zclass,
		*v->triples[i]->type);
	if (v->triples[i]->which == Z_Triple_internationalString)
	    fprintf(fp,",value=%s\n",v->triples[i]->value.internationalString);
	else
	    fprintf(fp,"\n");
    }
}

static void display_grs1(Z_GenericRecord *r, int level, FILE *fp)
{
    int i;
    
    if (!r)
        return;
    for (i = 0; i < r->num_elements; i++) {
        Z_TaggedElement *t;
	
        fprintf(fp,"%*s", level * 4, "");
        t = r->elements[i];
        fprintf(fp,"(");
        if (t->tagType)
            fprintf(fp,"%d,", *t->tagType);
        else
            fprintf(fp,"?,");
        if (t->tagValue->which == Z_StringOrNumeric_numeric)
            fprintf(fp,"%d) ", *t->tagValue->u.numeric);
        else
            fprintf(fp,"%s) ", t->tagValue->u.string);
        if (t->content->which == Z_ElementData_subtree) {
            fprintf(fp,"\n");
            display_grs1(t->content->u.subtree, level+1,fp);
        }
        else if (t->content->which == Z_ElementData_string)
            fprintf(fp,"%s\n", t->content->u.string);
        else if (t->content->which == Z_ElementData_numeric)
	    fprintf(fp,"%d\n", *t->content->u.numeric);
	else if (t->content->which == Z_ElementData_oid) {
	    int *ip = t->content->u.oid;
	    oident *oent;
	    
	    if ((oent = oid_getentbyoid(t->content->u.oid)))
		fprintf(fp,"OID: %s\n", oent->desc);
	    else {
		fprintf(fp,"{");
		while (ip && *ip >= 0)
		    fprintf(fp," %d", *(ip++));
		fprintf(fp," }\n");
	    }
	}
	else if (t->content->which == Z_ElementData_noDataRequested)
	    fprintf(fp,"[No data requested]\n");
	else if (t->content->which == Z_ElementData_elementEmpty)
	    fprintf(fp,"[Element empty]\n");
	else if (t->content->which == Z_ElementData_elementNotThere)
	    fprintf(fp,"[Element not there]\n");
	else
            fprintf(fp,"??????\n");
	if (t->appliedVariant)
	    display_variant(t->appliedVariant, level+1,fp);
	if (t->metaData && t->metaData->supportedVariants) {
	    int c;
	    
	    fprintf(fp,"%*s---- variant list\n", (level+1)*4, "");
	    for (c = 0; c < t->metaData->num_supportedVariants; c++) {
		fprintf(fp,"%*svariant #%d\n", (level+1)*4, "", c);
		display_variant(t->metaData->supportedVariants[c], level + 2,fp);
	    }
	}
    }
}

static void display_record(Z_DatabaseRecord *p)
{
    Z_External *r = (Z_External*) p;
    oident *ent = oid_getentbyoid(r->direct_reference);
    
    /*
     * Tell the user what we got.
     */
    if (r->direct_reference) {
        /* printf("Record type: ");*/
	fprintf(tcldump,"Record type:");
	if (ent)
	    /*printf("%s\n", ent->desc);*/
	    fprintf(tcldump,"%s\n--\n", ent->desc);
        else if (!odr_oid(print, &r->direct_reference, 0)) {
            odr_perror(print, "print oid");
            odr_reset(print);
        }
    }
    /* Check if this is a known, ASN.1 type tucked away in an octet string */
    if (ent && r->which == Z_External_octet) {
	Z_ext_typeent *type = z_ext_getentbyref(ent->value);
	void *rr;
	
	if (type) {
	    /*
	     * Call the given decoder to process the record.
	     */
	    odr_setbuf(in, (char*)p->u.octet_aligned->buf,
		       p->u.octet_aligned->len, 0);
	    if (!(*type->fun)(in, &rr, 0)) {
		odr_perror(in, "Decoding constructed record.");
		fprintf(stderr, "[Near %d]\n", odr_offset(in));
		fprintf(stderr, "Packet dump:\n---------\n");
		odr_dumpBER(stderr, (char*)p->u.octet_aligned->buf,
			    p->u.octet_aligned->len);
		fprintf(stderr, "---------\n");
		exit(1);
	    }
	    /*
	     * Note: we throw away the original, BER-encoded record here.
	     * Do something else with it if you want to keep it.
	     */
	    r->u.sutrs = rr;    /* we don't actually check the type here. */
	    r->which = type->what;
	}
    }
    if (ent && ent->value == VAL_SOIF)
        printf("%.*s", r->u.octet_aligned->len, r->u.octet_aligned->buf);
    else if (r->which == Z_External_octet && p->u.octet_aligned->len) {
        const char *marc_buf = (char*)p->u.octet_aligned->buf;
        marc_display (marc_buf, tcldump);
        if (marcdump)
            fwrite(marc_buf, strlen (marc_buf), 1, marcdump);
    }
    else if (ent && ent->value == VAL_SUTRS) {
        if (r->which != Z_External_sutrs) {
            printf("Expecting single SUTRS type for SUTRS.\n");
            return;
        }
	fprintf(tcldump,"%.*s\n",r->u.sutrs->len, r->u.sutrs->buf);
    }
    else if (ent && ent->value == VAL_GRS1) {
        if (r->which != Z_External_grs1) {
            printf("Expecting single GRS type for GRS.\n");
            return;
        }
        display_grs1(r->u.grs1, 0,tcldump);
    }
    else {
        printf("Unknown record representation.\n");
        if (!z_External(print, &r, 0)) {
            odr_perror(print, "Printing external");
            odr_reset(print);
        }
    }
}

static void display_diagrecs(Z_DiagRec **pp, int num)
{
    int i;
    oident *ent;
    Z_DefaultDiagFormat *r;

    printf("Diagnostic message(s) from database:\n");
    for (i = 0; i<num; i++) {
	Z_DiagRec *p = pp[i];
	if (p->which != Z_DiagRec_defaultFormat) {
	    printf("Diagnostic record not in default format.\n");
	    return;
	} else {
	    r = p->u.defaultFormat;
	}
	if (!(ent = oid_getentbyoid(r->diagnosticSetId)) ||
	    ent->oclass != CLASS_DIAGSET || ent->value != VAL_BIB1)
	    printf("Missing or unknown diagset\n");
	printf("    [%d] %s", *r->condition, diagbib1_str(*r->condition));
	if (r->addinfo && *r->addinfo)
	    printf(" -- '%s'\n", r->addinfo);
	else
	    printf("\n");
    }
}

static void display_nameplusrecord(Z_NamePlusRecord *p)
{  
    if (p->databaseName)
	fprintf(tcldump,"DBname:%s \t,", p->databaseName);
    if (p->which == Z_NamePlusRecord_surrogateDiagnostic)
        display_diagrecs(&p->u.surrogateDiagnostic, 1);
    else
        display_record(p->u.databaseRecord);
}

static void display_records(Z_Records *p)
{
    int i;
    char buf[1024];
    char nkf_command[40];

    if (p->which == Z_Records_NSD)
	display_diagrecs (&p->u.nonSurrogateDiagnostic, 1);
    else if (p->which == Z_Records_multipleNSD)
	display_diagrecs (p->u.multipleNonSurDiagnostics->diagRecs,
			  p->u.multipleNonSurDiagnostics->num_diagRecs);
    else {
	tcldump = fopen(tcldumpfilename, "w");
	
	fprintf(tcldump,"************************************************************ \n \t%d件のレコードが返ってきました\n", p->u.databaseOrSurDiagnostics->num_records);

        for (i = 0; i < p->u.databaseOrSurDiagnostics->num_records; i++) {
	    fprintf(tcldump,"------------------------------------------------------------------- \n[%d] No%d \t ",buf_setnumber,show_start_position++);
            display_nameplusrecord(p->u.databaseOrSurDiagnostics->records[i]);
	}
    }
    fclose(tcldump);
    sprintf(nkf_command, "nkf -e %s > %s_EUC" ,tcldumpfilename ,tcldumpfilename);
    system(nkf_command);
    sprintf(buf,"recordToListbox %s_EUC .l1" ,tcldumpfilename);
    Tcl_Eval(interp, buf);
}

static int send_searchRequest(char *arg)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_searchRequest);
    Z_SearchRequest *req = apdu->u.searchRequest;
    Z_Query query;
    int oid[OID_SIZE];
#if CCL2RPN
    struct ccl_rpn_node *rpn;
    int error, pos;
    oident bib1;
#endif
    char setstring[100];
    Z_RPNQuery *RPNquery;
    Odr_oct ccl_query;
    char err_buf[256];
    
#if CCL2RPN
    if (queryType == QueryType_CCL2RPN) {
        rpn = ccl_find_str(bibset, arg, &error, &pos);
        if (error) {
            sprintf(err_buf, "CCL ERROR: %s\n", ccl_err_msg(error));
	    tclPrintf(err_buf, 2);
            return 0;
        }
    }
#endif

    if (!strcmp(arg, "@big")) { /* strictly for troublemaking */
        static unsigned char big[2100];
        static Odr_oct bigo;

        /* send a very big referenceid to test transport stack etc. */
        memset(big, 'A', 2100);
        bigo.len = bigo.size = 2100;
        bigo.buf = big;
        req->referenceId = &bigo;
    }

    if (setnumber >= 0) {
        sprintf(setstring, "%d", ++setnumber);
        req->resultSetName = setstring;
    }
    *req->smallSetUpperBound = smallSetUpperBound;
    *req->largeSetLowerBound = largeSetLowerBound;
    *req->mediumSetPresentNumber = mediumSetPresentNumber;
    if (smallSetUpperBound > 0 ||
	(largeSetLowerBound > 1 && mediumSetPresentNumber > 0)) {

	oident prefsyn;

        prefsyn.proto = protocol;
        prefsyn.oclass = CLASS_RECSYN;
        prefsyn.value = recordsyntax;
        req->preferredRecordSyntax =
	    odr_oiddup(out, oid_ent_to_oid(&prefsyn, oid));
        req->smallSetElementSetNames = req->mediumSetElementSetNames = elementSetNames;
    }
    req->num_databaseNames = num_databaseNames;
    req->databaseNames = databaseNames;

    req->query = &query;

    switch (queryType) {
    case QueryType_Prefix:
        query.which = Z_Query_type_1;
        RPNquery = p_query_rpn (out, protocol, arg);
        if (!RPNquery) {
            tclPrintf("Prefix query error\n", 2);
            return 0;
        }
        query.u.type_1 = RPNquery;
        break;
    case QueryType_CCL:
        query.which = Z_Query_type_2;
        query.u.type_2 = &ccl_query;
        ccl_query.buf = (unsigned char*) arg;
        ccl_query.len = strlen(arg);
        break;
#if CCL2RPN
    case QueryType_CCL2RPN:
        query.which = Z_Query_type_1;
        assert((RPNquery = ccl_rpn_query(out, rpn)));
        bib1.proto = protocol;
        bib1.oclass = CLASS_ATTSET;
        bib1.value = VAL_BIB1;
        RPNquery->attributeSetId = oid_ent_to_oid(&bib1, oid);
        query.u.type_1 = RPNquery;
        break;
#endif
    default:
        tclPrintf ("Unsupported query type\n", 2);
        return 0;
    }
    send_apdu(apdu);
    setno = 1;
    printf("Sent searchRequest.\n");
    return 2;
}

static int process_searchResponse(Z_SearchResponse *res)
{
    if (*res->searchStatus)
        printf("Search was a success.\n");
    else
        printf("Search was a bloomin' failure.\n");
/* 10.12 process_searchResponse() */
    {
/* リストボックスに、検索式とヒットした件数を表示し */
/* show のためのエントリウィジットにその値を挿入 */
	char buf[1000];
	sprintf(buf,"[%3d]  検索式:%s  ヒットした件数:%d\n", setnumber,
		Tcl_GetVar(interp,"TclEntryArg",0), *res->resultCount);
	tclPrintf(buf,0);
	Tcl_Eval(interp,".showEnter.setno delete 0 end" );
	Tcl_Eval(interp,".showEnter.beginno delete 0 end" );
	Tcl_Eval(interp,".showEnter.endno delete 0 end" );
	itoa(setnumber,buf);
	Tcl_SetVar(interp,"Csetnodata", buf,0);
	Tcl_Eval(interp,".showEnter.setno insert 0 $Csetnodata" );
	Tcl_Eval(interp,".showEnter.beginno insert 0 1" );

	/* ヒットした件数が30件以上だったら showエントリには30を入力  */
	if( *res->resultCount > 30) {
	    strcpy(buf, "30");
	}
	else {
	    itoa(*res->resultCount,buf);
	}
	Tcl_SetVar(interp,"Cendnodata",buf ,0);
	Tcl_Eval(interp,".showEnter.endno insert 0 $Cendnodata" );
    }
    
    printf("records returned: %d\n", *res->numberOfRecordsReturned);
    setno += *res->numberOfRecordsReturned;
    if (res->records)
        display_records(res->records);
    return 0;
}

static int cmd_find(char *arg)
{
    if (!*arg) {
        tclPrintf("Find what?\n", 2);
        return 0;
    }
    if (!conn) {
        printf("Not connected yet\n");
        return 0;
    }
    if (!send_searchRequest(arg))
        return 0;
    return 2;
}

static int cmd_ssub(char *arg)
{
    if (!(smallSetUpperBound = atoi(arg)))
        return 0;
    return 1;
}

static int cmd_lslb(char *arg)
{
    if (!(largeSetLowerBound = atoi(arg)))
        return 0;
    return 1;
}

static int cmd_mspn(char *arg)
{
    if (!(mediumSetPresentNumber = atoi(arg)))
        return 0;
    return 1;
}

static int cmd_status(char *arg)
{
    printf("smallSetUpperBound: %d\n", smallSetUpperBound);
    printf("largeSetLowerBound: %d\n", largeSetLowerBound);
    printf("mediumSetPresentNumber: %d\n", mediumSetPresentNumber);
    return 1;
}

static int cmd_base(char *arg)
{
    int i;
    char *cp;

    if (!*arg) {
        printf("Usage: base <database> <database> ...\n");
        return 0;
    }
    for (i = 0; i<num_databaseNames; i++)
        xfree (databaseNames[i]);
    num_databaseNames = 0;
    while (1) {
        if (!(cp = strchr(arg, ' ')))
            cp = arg + strlen(arg);
        if (cp - arg < 1)
            break;
        databaseNames[num_databaseNames] = xmalloc (1 + cp - arg);
        memcpy (databaseNames[num_databaseNames], arg, cp - arg);
        databaseNames[num_databaseNames++][cp - arg] = '\0';
        if (!*cp)
            break;
        arg = cp+1;
    }
    return 1;
}

static int cmd_setnames(char *arg)
{
    if (setnumber < 0) {
        printf("Set numbering enabled.\n");
        setnumber = 0;
    }
    else {
        printf("Set numbering disabled.\n");
        setnumber = -1;
    }
    return 1;
}

/* PRESENT SERVICE ----------------------------- */

static int send_presentRequest(char *arg)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_presentRequest);
    Z_PresentRequest *req = apdu->u.presentRequest;
    Z_RecordComposition compo;
    oident prefsyn;
    int nos = 1;
    int oid[OID_SIZE];
    char *p;
    char setstring[100];

    /* *** input 1997.9.9 send_presentRequest() */
    char buf[100],*p2;
     
  
    if((p2 = strchr(arg, '@'))) {
	buf_setnumber = atoi(p2 + 1);
	printf("%d\n",buf_setnumber);
	*p2 = 0;
    } else {
	buf_setnumber = setnumber;
    }
    /* *** end input 1997.9.9  */

    if ((p = strchr(arg, '+'))) {
        nos = atoi(p + 1);
        *p = 0;
    }
    
    if (*arg) {
        setno = atoi(arg);
	show_start_position = setno;
    }

    if (p && (p=strchr(p+1, '+'))) {
        strcpy (setstring, p+1);
        req->resultSetId = setstring;
    } else if (setnumber >= 0) {
	/* *** input 1997.9.9 send_presentRequest() */
	
	sprintf(setstring, "%d", buf_setnumber);
	/* *** end input 1997.9.9 */
 
        req->resultSetId = setstring;
    }
#if 0
    if (1)
	static Z_Range range;
    static Z_Range *rangep = &range;
    req->num_ranges = 1;
#endif
    req->resultSetStartPoint = &setno;
    req->numberOfRecordsRequested = &nos;
    prefsyn.proto = protocol;
    prefsyn.oclass = CLASS_RECSYN;
    prefsyn.value = recordsyntax;
    req->preferredRecordSyntax = oid_ent_to_oid(&prefsyn, oid);

    if (elementSetNames) {
        req->recordComposition = &compo;
        compo.which = Z_RecordComp_simple;
        compo.u.simple = elementSetNames;
    }

    send_apdu(apdu);

    printf("Sent presentRequest (%d+%d).\n", setno, nos);
    return 2;
}

void process_close(Z_Close *req)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_close);
    Z_Close *res = apdu->u.close;

    static char *reasons[] = {
        "finished",
        "shutdown",
        "system problem",
        "cost limit reached",
        "resources",
        "security violation",
        "protocolError",
        "lack of activity",
        "peer abort",
        "unspecified"
    };

    printf("Reason: %s, message: %s\n", reasons[*req->closeReason],
	   req->diagnosticInformation ? req->diagnosticInformation : "NULL");
    if (sent_close) {
	printf("Goodbye.\n");
	unlink(tcldumpfilename);
	exit(1);
    }
    
    *res->closeReason = Z_Close_finished;
    send_apdu(apdu);
    printf("Sent response.\n");
    sent_close = 1;
}

static int cmd_show(char *arg)
{
    if (!session) {
        printf("Session not initialized yet\n");
        return 0;
    }
    if (!send_presentRequest(arg)) {
        return 0;
    }
    return 2;
}

int cmd_quit(char *arg)
{
    printf("See you later, alligator.\n");
    unlink(tcldumpfilename);
    exit(0);
    return 0;
}

int cmd_cancel(char *arg)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_triggerResourceControlRequest);
    Z_TriggerResourceControlRequest *req =
        apdu->u.triggerResourceControlRequest;
    bool_t rfalse = 0;
    
    if (!session) {
        printf("Session not initialized yet\n");
        return 0;
    }
    if (!ODR_MASK_GET(session->options, Z_Options_triggerResourceCtrl)) {
        printf("Target doesn't support cancel (trigger resource ctrl)\n");
        return 0;
    }
    *req->requestedAction = Z_TriggerResourceCtrl_cancel;
    req->resultSetWanted = &rfalse;

    send_apdu(apdu);
    printf("Sent cancel request\n");
    return 2;
}

int send_scanrequest(char *string, int pp, int num)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_scanRequest);
    Z_ScanRequest *req = apdu->u.scanRequest;

    req->num_databaseNames = num_databaseNames;
    req->databaseNames = databaseNames;
    req->termListAndStartPoint = p_query_scan(out, protocol,
					      &req->attributeSet, string);
    req->numberOfTermsRequested = &num;
    req->preferredPositionInResponse = &pp;
    send_apdu(apdu);
    return 2;
}

int send_sortrequest(char *arg, int newset)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_sortRequest);
    Z_SortRequest *req = apdu->u.sortRequest;
    Z_SortKeySpecList *sksl = odr_malloc (out, sizeof(*sksl));
    char setstring[32];
    char sort_string[32], sort_flags[32];
    int off;
    int oid[OID_SIZE];
    oident bib1;

    if (setnumber >= 0)
	sprintf (setstring, "%d", setnumber);
    else
	sprintf (setstring, "default");

    req->inputResultSetNames =
	odr_malloc (out, sizeof(*req->inputResultSetNames));
    req->inputResultSetNames->num_strings = 1;
    req->inputResultSetNames->strings =
	odr_malloc (out, sizeof(*req->inputResultSetNames->strings));
    req->inputResultSetNames->strings[0] =
	odr_malloc (out, strlen(setstring)+1);
    strcpy (req->inputResultSetNames->strings[0], setstring);

    if (newset && setnumber >= 0)
	sprintf (setstring, "%d", ++setnumber);

    req->sortedResultSetName = odr_malloc (out, strlen(setstring)+1);
    strcpy (req->sortedResultSetName, setstring);

    req->sortSequence = sksl;
    sksl->num_specs = 0;
    sksl->specs = odr_malloc (out, sizeof(sksl->specs) * 20);
    
    bib1.proto = protocol;
    bib1.oclass = CLASS_ATTSET;
    bib1.value = VAL_BIB1;
    while ((sscanf (arg, "%31s %31s%n", sort_string, sort_flags, &off)) == 2
	   && off > 1) {
	int i;
	char *sort_string_sep;
	Z_SortKeySpec *sks = odr_malloc (out, sizeof(*sks));
	Z_SortKey *sk = odr_malloc (out, sizeof(*sk));

	arg += off;
	sksl->specs[sksl->num_specs++] = sks;
	sks->sortElement = odr_malloc (out, sizeof(*sks->sortElement));
	sks->sortElement->which = Z_SortElement_generic;
	sks->sortElement->u.generic = sk;
	
	if ((sort_string_sep = strchr (sort_string, '='))) {
	    Z_AttributeElement *el = odr_malloc (out, sizeof(*el));
	    sk->which = Z_SortKey_sortAttributes;
	    sk->u.sortAttributes =
		odr_malloc (out, sizeof(*sk->u.sortAttributes));
	    sk->u.sortAttributes->id = oid_ent_to_oid(&bib1, oid);
	    sk->u.sortAttributes->list =
		odr_malloc (out, sizeof(*sk->u.sortAttributes->list));
	    sk->u.sortAttributes->list->num_attributes = 1;
	    sk->u.sortAttributes->list->attributes =
		odr_malloc (out,
			    sizeof(*sk->u.sortAttributes->list->attributes));
	    sk->u.sortAttributes->list->attributes[0] = el;
	    el->attributeSet = 0;
	    el->attributeType = odr_malloc (out, sizeof(*el->attributeType));
	    *el->attributeType = atoi (sort_string);
	    el->which = Z_AttributeValue_numeric;
	    el->value.numeric = odr_malloc (out, sizeof(*el->value.numeric));
	    *el->value.numeric = atoi (sort_string_sep + 1);
	} else {
	    sk->which = Z_SortKey_sortField;
	    sk->u.sortField = odr_malloc (out, strlen(sort_string)+1);
	    strcpy (sk->u.sortField, sort_string);
	}
	sks->sortRelation = odr_malloc (out, sizeof(*sks->sortRelation));
	*sks->sortRelation = Z_SortRelation_ascending;
	sks->caseSensitivity = odr_malloc (out, sizeof(*sks->caseSensitivity));
	*sks->caseSensitivity = Z_SortCase_caseSensitive;

	sks->missingValueAction = NULL;

	for (i = 0; sort_flags[i]; i++) {
	    switch (sort_flags[i]) {
	    case 'a':
	    case 'A':
	    case '>':
		*sks->sortRelation = Z_SortRelation_ascending;
		break;
	    case 'd':
	    case 'D':
	    case '<':
		*sks->sortRelation = Z_SortRelation_descending;
		break;
	    case 'i':
	    case 'I':
		*sks->caseSensitivity = Z_SortCase_caseInsensitive;
		break;
	    case 'S':
	    case 's':
		*sks->caseSensitivity = Z_SortCase_caseSensitive;
		break;
	    }
	}
    }
    if (!sksl->num_specs) {
        printf ("Missing sort specifications\n");
	return -1;
    }
    send_apdu(apdu);
    return 2;
}

void display_term(Z_TermInfo *t)
{
    if (t->term->which == Z_Term_general) {
        printf("%.*s (%d)\n", t->term->u.general->len, t->term->u.general->buf,
	       t->globalOccurrences ? *t->globalOccurrences : -1);
        sprintf(last_scan, "%.*s", t->term->u.general->len,
		t->term->u.general->buf);
    } else {
        printf("Term type not general.\n");
    }
}

void process_scanResponse(Z_ScanResponse *res)
{
    int i;

    printf("SCAN: %d entries, position=%d\n", *res->numberOfEntriesReturned,
	   *res->positionOfTerm);
    if (*res->scanStatus != Z_Scan_success)
        printf("Scan returned code %d\n", *res->scanStatus);
    if (!res->entries)
        return;
    if (res->entries->which == Z_ListEntries_entries) {
        Z_Entries *ent = res->entries->u.entries;

        for (i = 0; i < ent->num_entries; i++)
            if (ent->entries[i]->which == Z_Entry_termInfo) {
                printf("%c ", i + 1 == *res->positionOfTerm ? '*' : ' ');
                display_term(ent->entries[i]->u.termInfo);
            } else
                display_diagrecs(&ent->entries[i]->u.surrogateDiagnostic, 1);
    }
    else
        display_diagrecs(&res->entries->
			 u.nonSurrogateDiagnostics->diagRecs[0], 1);
}

void process_sortResponse(Z_SortResponse *res)
{
    printf("Sort: status=");
    switch (*res->sortStatus) {
    case Z_SortStatus_success:
	printf ("success"); break;
    case Z_SortStatus_partial_1:
	printf ("partial"); break;
    case Z_SortStatus_failure:
	printf ("failure"); break;
    default:
	printf ("unknown (%d)", *res->sortStatus);
    }
    printf ("\n");
    if (res->diagnostics)
        display_diagrecs(res->diagnostics->diagRecs,
			 res->diagnostics->num_diagRecs);
}

int cmd_sort_generic(char *arg, int newset)
{
    if (!session) {
        printf("Session not initialized yet\n");
        return 0;
    }
    if (!ODR_MASK_GET(session->options, Z_Options_sort)) {
        printf("Target doesn't support sort\n");
        return 0;
    }
    if (*arg) {
        if (send_sortrequest(arg, newset) < 0)
            return 0;
	return 2;
    }
    return 0;
}

int cmd_sort(char *arg)
{
    return cmd_sort_generic (arg, 0);
}

int cmd_sort_newset (char *arg)
{
    return cmd_sort_generic (arg, 1);
}

int cmd_scan(char *arg)
{
    if (!session) {
        printf("Session not initialized yet\n");
        return 0;
    }
    if (!ODR_MASK_GET(session->options, Z_Options_scan)) {
        printf("Target doesn't support scan\n");
        return 0;
    }
    if (*arg) {
        if (send_scanrequest(arg, 5, 20) < 0)
            return 0;
    } else if (send_scanrequest(last_scan, 1, 20) < 0) {
	return 0;
    }
    return 2;
}

int cmd_format(char *arg)
{
    if (!arg || !*arg) {
        printf("Usage: format <recordsyntax>\n");
        return 0;
    }
    recordsyntax = oid_getvalbyname (arg);
    if (recordsyntax == VAL_NONE) {
        printf ("unknown record syntax\n");
        return 0;
    }
    return 1;
}

int cmd_elements(char *arg)
{
    static Z_ElementSetNames esn;
    static char what[100];

    if (!arg || !*arg) {
        printf("Usage: elements <esn>\n");
        return 0;
    }
    strcpy(what, arg);
    esn.which = Z_ElementSetNames_generic;
    esn.u.generic = what;
    elementSetNames = &esn;
    return 1;
}

int cmd_attributeset(char *arg)
{
    char what[100];

    if (!arg || !*arg) {
	printf("Usage: attributeset <setname>\n");
	return 0;
    }
    sscanf(arg, "%s", what);
    if (p_query_attset (what)) {
	printf("Unknown attribute set name\n");
	return 0;
    }
    return 1;
}

int cmd_querytype (char *arg)
{
    if (!strcmp (arg, "ccl"))
        queryType = QueryType_CCL;
    else if (!strcmp (arg, "prefix"))
        queryType = QueryType_Prefix;
#if CCL2RPN
    else if (!strcmp (arg, "ccl2rpn") || !strcmp (arg, "cclrpn"))
        queryType = QueryType_CCL2RPN;
#endif
    else {
        printf ("Querytype must be one of:\n");
        printf (" prefix         - Prefix query\n");
        printf (" ccl            - CCL query\n");
#if CCL2RPN
        printf (" ccl2rpn        - CCL query converted to RPN\n");
#endif
        return 0;
    }
    return 1;
}

int cmd_close(char *arg)
{
    Z_APDU *apdu = zget_APDU(out, Z_APDU_close);
    Z_Close *req = apdu->u.close;

    *req->closeReason = Z_Close_finished;
    send_apdu(apdu);
    printf("Sent close request.\n");
    sent_close = 1;
    return 2;
}

static void initialize(void)
{
#if CCL2RPN
    FILE *inf;
#endif
    nmem_init();
    if (!(out = odr_createmem(ODR_ENCODE)) ||
        !(in = odr_createmem(ODR_DECODE)) ||
        !(print = odr_createmem(ODR_PRINT))) {
        fprintf(stderr, "failed to allocate ODR streams\n");
        exit(1);
    }
    setvbuf(stdout, 0, _IONBF, 0);

#if CCL2RPN
    bibset = ccl_qual_mk (); 
    inf = fopen ("default.bib", "r");
    if (inf) {
        ccl_qual_file (bibset, inf);
        fclose (inf);
    }
#endif
}

static int client(char *binary_path)
{
    Tk_Window	toplevel;
    char inTclFilename[30];
    strcpy(inTclFilename, dirname(binary_path));
    strcat(inTclFilename, "/client.tcl");

    /* extracts from Tk_Main below */

    /* Initialize Tcl interpreter */
    Tcl_FindExecutable(binary_path);
    interp = Tcl_CreateInterp();

    /* parse options here if needed */

#if TCL_MAJOR_VERSION < 8
    if (Tcl_Init(interp) != TCL_OK) {
	fprintf(stderr, "Tcl_Init failed: %s\n", interp->result);
    }
#endif

    /* Initialize Tk */
    /* application name/class determined from "argv0" (not set here)*/
    if (Tk_Init(interp) != TCL_OK) {
	fprintf(stderr, "Tk_Init failed: %s\n", interp->result);
    }
    toplevel = Tk_MainWindow(interp);

    /* Create commands & widgets */
    Tcl_CreateCommand(interp, TclCmdName, tclCommandCallback,
		      (ClientData)NULL, (Tcl_CmdDeleteProc*)NULL );

    if (Tcl_EvalFile(interp, inTclFilename) != TCL_OK) {
	fprintf(stderr, "Tcl_EvalFile: %s: %s", inTclFilename, interp->result);
	exit(1);
    }

    /* Main Loop */
    Tk_MainLoop();

    Tcl_DeleteInterp(interp);
    Tcl_Exit(0);

    /*NOTREACHED*/
    return 0;
}
static int
tclCommandCallback( ClientData cd,int argc, char *argv[])
{
    int wait;
        
    static struct {
        char *cmd;
        int (*fun)(char *arg);
        char *ad;
    } cmd[] = {
        {"open", cmd_open, "('tcp'|'osi')':'[<tsel>'/']<host>[':'<port>]"},
        {"quit", cmd_quit, ""},
        {"find", cmd_find, "<query>"},
        {"base", cmd_base, "<base-name>"},
        {"show", cmd_show, "<rec#>['+'<#recs>['+'<setname>]]"},
        {"scan", cmd_scan, "<term>"},
	{"sort", cmd_sort, "<sortkey> <flag> <sortkey> <flag> ..."},
	{"sort+", cmd_sort_newset, "<sortkey> <flag> <sortkey> <flag> ..."},
        {"authentication", cmd_authentication, "<acctstring>"},
        {"lslb", cmd_lslb, "<largeSetLowerBound>"},
        {"ssub", cmd_ssub, "<smallSetUpperBound>"},
        {"mspn", cmd_mspn, "<mediumSetPresentNumber>"},
        {"status", cmd_status, ""},
        {"setnames", cmd_setnames, ""},
        {"cancel", cmd_cancel, ""},
        {"format", cmd_format, "<recordsyntax>"},
        {"elements", cmd_elements, "<elementSetName>"},
        {"close", cmd_close, ""},
	{"attributeset", cmd_attributeset, "<attrset>"},
        {"querytype", cmd_querytype, "<type>"},
        {0,0}
    };
    char *netbuffer= 0;
    int netbufferlen = 0;
    int i;
    Z_APDU *apdu;
    char line[1024], word[1024], arg[1024];

    /* while (1) */
    {
        int res;

	char line[1024], word[1024], arg[1024];       
         
	char tcl_cmdName[20];
	char tcl_entryName[100];
         
	strcpy(tcl_cmdName,Tcl_GetVar(interp,"TclComandName",0));
	strcpy(tcl_entryName,Tcl_GetVar(interp,"TclEntryArg",0));
         
	printf("\nコマンド名 ： %s\n", Tcl_GetVar(interp,"TclComandName",0));
	printf("入力文字列 ： %s\n", Tcl_GetVar(interp,"TclEntryArg",0));

#ifdef USE_SELECT
        fd_set input;
#endif
	
#ifdef USE_SELECT
        FD_ZERO(&input);
        FD_SET(0, &input);
        if (conn)
            FD_SET(cs_fileno(conn), &input);
        if ((res = select(20, &input, 0, 0, 0)) < 0) {
            perror("select");
            exit(1);
        }
        if (!res)
            continue;
        if (!wait && FD_ISSET(0, &input))
#else
	 /* この */ wait = 0;
	if (!wait)
#endif
	{
	    strcpy(word, Tcl_GetVar(interp,"TclComandName",0));
	    strcpy(arg, Tcl_GetVar(interp,"TclEntryArg",0));

	    for (i = 0; cmd[i].cmd; i++)
		if (!strncmp(cmd[i].cmd, word, strlen(word))) {
                    res = (*cmd[i].fun)(arg);
                    break;
		}
	    if (res < 2) {
		return 0;
	    }
	}
#ifdef USE_SELECT
        if (conn && FD_ISSET(cs_fileno(conn), &input))
#endif
        {
            do {
                if ((res = cs_get(conn, &netbuffer, &netbufferlen)) < 0) {
                    perror("cs_get");
                    exit(1);
                }
                if (!res) {
                    printf("Target closed connection.\n");
		    unlink(tcldumpfilename);
                    exit(1);
                }
                odr_reset(in); /* release APDU from last round */
                odr_setbuf(in, netbuffer, res, 0);
                if (!z_APDU(in, &apdu, 0)) {
                    odr_perror(in, "Decoding incoming APDU");
		    fprintf(stderr, "[Near %d]\n", odr_offset(in));
                    fprintf(stderr, "Packet dump:\n---------\n");
                    odr_dumpBER(stderr, netbuffer, res);
                    fprintf(stderr, "---------\n");
                    exit(1);
                }
#if 0
                if (!z_APDU(print, &apdu, 0)) {
                    odr_perror(print, "Failed to print incoming APDU");
                    odr_reset(print);
                    continue;
                }
#endif
                switch(apdu->which) {
		case Z_APDU_initResponse:
		    process_initResponse(apdu->u.initResponse);
		    break;
		case Z_APDU_searchResponse:
		    process_searchResponse(apdu->u.searchResponse);
		    break;
		case Z_APDU_scanResponse:
		    process_scanResponse(apdu->u.scanResponse);
		    break;
		case Z_APDU_presentResponse:
		    setno += *apdu->u.presentResponse->numberOfRecordsReturned;
		    if (apdu->u.presentResponse->records)
			display_records(apdu->u.presentResponse->records);
		    else
			printf("No records.\n");
		    break;
		case Z_APDU_sortResponse:
		    process_sortResponse(apdu->u.sortResponse);
		    break;
		case Z_APDU_close:
		    printf("Target has closed the association.\n");
		    process_close(apdu->u.close);
		    break;
		default:
		    printf("Received unknown APDU type (%d).\n", 
			   apdu->which);
		    exit(1);
                }
		printf("setNo[%d]>>",setnumber + 1);
                fflush(stdout);
            } while (cs_more(conn));
        }
	wait = 0;
    }
    return TCL_OK;
}

int main(int argc, char **argv)
{
    char *prog = *argv;
    char *arg;
    int ret;
    int opened = 0;

    initialize();
    sprintf(tcldumpfilename, "%s/%s%d", TMPDIR, PROGNAME, getpid());
    cmd_base("Default");
    printf("setNo[%d]>>",setnumber + 1);

    return client(argv[0]);
}

/* reverse: 文字列 s を逆順にする */
void reverse(char s[])
{
     int c, i, j;
     
     for(i = 0,j = strlen(s) -1;i < j; i++, j--) {
	 c = s[i];
	 s[i] = s[j];
	 s[j] = c;
     }
}
/* itoa: n を s 中の文字に変換する */
void itoa(int n,char s[])
{
    int i, sign;
     
    if((sign = n) < 0) /* 符合を記録する */
        n = -n;/* nを正にする */
    i = 0;
    do {
        s[i++] = n % 10 + '0';/* 次の桁をとってくる */
    } while((n /= 10) > 0);/* それを削除する */
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

static int tclPrintf(char *str,int lnum)
{
    Tcl_SetVar(interp,"setdata", str,0);
    if( lnum == 0){
        Tcl_Eval(interp,".l0 insert end $setdata" );
    } else if(lnum == 1){
        Tcl_Eval(interp,".l1 insert end $setdata" ); 
    } else if (lnum == 2) {
	Tcl_Eval(interp, "errWin $setdata");
    }
/*  else if(lnum == 2){
        Tcl_Eval(interp,".m configure -text $setdata");
    }
    else if(lnum == 3){
        Tcl_Eval(interp,".topen.m configure -text $setdata");
        Tcl_Eval(interp,".m configure -text $setdata");
    }
    else if(lnum == 3){
        Tcl_Eval(interp,".topen.m configure -text $setdata");
    } できないみたいなので、他の方法を確認中  */
    else if(lnum == 4){
        Tcl_Eval(interp,"errWin_open $setdata");
    }
    else{
        printf(" tclPrintf() error lnum \n");
        exit(1);
    }
}
