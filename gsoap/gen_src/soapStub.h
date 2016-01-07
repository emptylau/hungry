/* soapStub.h
   Generated by gSOAP 2.8.27 from webserver.h

gSOAP XML Web services tools
Copyright (C) 2000-2015, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/


#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"
#if GSOAP_VERSION != 20827
# error "GSOAP VERSION 20827 MISMATCH IN GENERATED CODE VERSUS LIBRARY CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes, Structs, and Unions                                               *
 *                                                                            *
\******************************************************************************/

struct ns__addResponse;	/* webserver.h:42 */
struct ns__add;	/* webserver.h:42 */
struct ns__subResponse;	/* webserver.h:43 */
struct ns__sub;	/* webserver.h:43 */
struct ns__mulResponse;	/* webserver.h:44 */
struct ns__mul;	/* webserver.h:44 */
struct ns__divResponse;	/* webserver.h:45 */
struct ns__div;	/* webserver.h:45 */
struct f__form1;	/* webserver.h:49 */
struct f__formResponse;	/* webserver.h:51 */
struct f__form2;	/* webserver.h:51 */

/* webserver.h:42 */
#ifndef SOAP_TYPE_ns__addResponse
#define SOAP_TYPE_ns__addResponse (10)
/* ns:addResponse complex type: */
struct ns__addResponse
{
public:
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of XSD type xsd:double */
public:
	int soap_type() const { return 10; } /* = unique type id SOAP_TYPE_ns__addResponse */
	         ns__addResponse();
	virtual ~ns__addResponse() { }
	friend ns__addResponse *soap_instantiate_ns__addResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:42 */
#ifndef SOAP_TYPE_ns__add
#define SOAP_TYPE_ns__add (11)
/* ns:add complex type: */
struct ns__add
{
public:
	double a;	/* required element of XSD type xsd:double */
	double b;	/* required element of XSD type xsd:double */
public:
	int soap_type() const { return 11; } /* = unique type id SOAP_TYPE_ns__add */
	         ns__add();
	virtual ~ns__add() { }
	friend ns__add *soap_instantiate_ns__add(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:43 */
#ifndef SOAP_TYPE_ns__subResponse
#define SOAP_TYPE_ns__subResponse (13)
/* ns:subResponse complex type: */
struct ns__subResponse
{
public:
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of XSD type xsd:double */
public:
	int soap_type() const { return 13; } /* = unique type id SOAP_TYPE_ns__subResponse */
	         ns__subResponse();
	virtual ~ns__subResponse() { }
	friend ns__subResponse *soap_instantiate_ns__subResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:43 */
#ifndef SOAP_TYPE_ns__sub
#define SOAP_TYPE_ns__sub (14)
/* ns:sub complex type: */
struct ns__sub
{
public:
	double a;	/* required element of XSD type xsd:double */
	double b;	/* required element of XSD type xsd:double */
public:
	int soap_type() const { return 14; } /* = unique type id SOAP_TYPE_ns__sub */
	         ns__sub();
	virtual ~ns__sub() { }
	friend ns__sub *soap_instantiate_ns__sub(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:44 */
#ifndef SOAP_TYPE_ns__mulResponse
#define SOAP_TYPE_ns__mulResponse (16)
/* ns:mulResponse complex type: */
struct ns__mulResponse
{
public:
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of XSD type xsd:double */
public:
	int soap_type() const { return 16; } /* = unique type id SOAP_TYPE_ns__mulResponse */
	         ns__mulResponse();
	virtual ~ns__mulResponse() { }
	friend ns__mulResponse *soap_instantiate_ns__mulResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:44 */
#ifndef SOAP_TYPE_ns__mul
#define SOAP_TYPE_ns__mul (17)
/* ns:mul complex type: */
struct ns__mul
{
public:
	double a;	/* required element of XSD type xsd:double */
	double b;	/* required element of XSD type xsd:double */
public:
	int soap_type() const { return 17; } /* = unique type id SOAP_TYPE_ns__mul */
	         ns__mul();
	virtual ~ns__mul() { }
	friend ns__mul *soap_instantiate_ns__mul(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:45 */
#ifndef SOAP_TYPE_ns__divResponse
#define SOAP_TYPE_ns__divResponse (19)
/* ns:divResponse complex type: */
struct ns__divResponse
{
public:
	double *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of XSD type xsd:double */
public:
	int soap_type() const { return 19; } /* = unique type id SOAP_TYPE_ns__divResponse */
	         ns__divResponse();
	virtual ~ns__divResponse() { }
	friend ns__divResponse *soap_instantiate_ns__divResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:45 */
#ifndef SOAP_TYPE_ns__div
#define SOAP_TYPE_ns__div (20)
/* ns:div complex type: */
struct ns__div
{
public:
	double a;	/* required element of XSD type xsd:double */
	double b;	/* required element of XSD type xsd:double */
public:
	int soap_type() const { return 20; } /* = unique type id SOAP_TYPE_ns__div */
	         ns__div();
	virtual ~ns__div() { }
	friend ns__div *soap_instantiate_ns__div(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:49 */
#ifndef SOAP_TYPE_f__form1
#define SOAP_TYPE_f__form1 (23)
/* f:form1 complex type: */
struct f__form1
{
public:
	int soap_type() const { return 23; } /* = unique type id SOAP_TYPE_f__form1 */
	         f__form1();
	virtual ~f__form1() { }
	friend f__form1 *soap_instantiate_f__form1(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:51 */
#ifndef SOAP_TYPE_f__formResponse
#define SOAP_TYPE_f__formResponse (24)
/* f:formResponse complex type: */
struct f__formResponse
{
public:
	double result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of XSD type xsd:double */
public:
	int soap_type() const { return 24; } /* = unique type id SOAP_TYPE_f__formResponse */
	         f__formResponse();
	virtual ~f__formResponse() { }
	friend f__formResponse *soap_instantiate_f__formResponse(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:51 */
#ifndef SOAP_TYPE_f__form2
#define SOAP_TYPE_f__form2 (27)
/* f:form2 complex type: */
struct f__form2
{
public:
	int soap_type() const { return 27; } /* = unique type id SOAP_TYPE_f__form2 */
	         f__form2();
	virtual ~f__form2() { }
	friend f__form2 *soap_instantiate_f__form2(struct soap*, int, const char*, const char*, size_t*);
};
#endif

/* webserver.h:53 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (28)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	int soap_type() const { return 28; } /* = unique type id SOAP_TYPE_SOAP_ENV__Header */
	         SOAP_ENV__Header();
	virtual ~SOAP_ENV__Header() { }
	friend SOAP_ENV__Header *soap_instantiate_SOAP_ENV__Header(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* webserver.h:53 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (29)
/* Type SOAP_ENV__Code is a recursive data type (in)directly referencing itself through its (base) class members */
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of XSD type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of XSD type SOAP-ENV:Code */
public:
	int soap_type() const { return 29; } /* = unique type id SOAP_TYPE_SOAP_ENV__Code */
	         SOAP_ENV__Code();
	virtual ~SOAP_ENV__Code() { }
	friend SOAP_ENV__Code *soap_instantiate_SOAP_ENV__Code(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* webserver.h:53 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (31)
/* SOAP-ENV:Detail complex type: */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below)
	   WARNING: do not create a cyclic data structure graph throught this element unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
	void *fault;	/* transient (not serialized) */
public:
	int soap_type() const { return 31; } /* = unique type id SOAP_TYPE_SOAP_ENV__Detail */
	         SOAP_ENV__Detail();
	virtual ~SOAP_ENV__Detail() { }
	friend SOAP_ENV__Detail *soap_instantiate_SOAP_ENV__Detail(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* webserver.h:53 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (33)
/* SOAP-ENV:Reason complex type: */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of XSD type xsd:string */
public:
	int soap_type() const { return 33; } /* = unique type id SOAP_TYPE_SOAP_ENV__Reason */
	         SOAP_ENV__Reason();
	virtual ~SOAP_ENV__Reason() { }
	friend SOAP_ENV__Reason *soap_instantiate_SOAP_ENV__Reason(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/* webserver.h:53 */
#ifndef WITH_NOGLOBAL
#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (34)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of XSD type xsd:QName */
	char *faultstring;	/* optional element of XSD type xsd:string */
	char *faultactor;	/* optional element of XSD type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of XSD type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of XSD type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of XSD type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of XSD type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of XSD type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of XSD type SOAP-ENV:Detail */
public:
	int soap_type() const { return 34; } /* = unique type id SOAP_TYPE_SOAP_ENV__Fault */
	         SOAP_ENV__Fault();
	virtual ~SOAP_ENV__Fault() { }
	friend SOAP_ENV__Fault *soap_instantiate_SOAP_ENV__Fault(struct soap*, int, const char*, const char*, size_t*);
};
#endif
#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/


/* webserver.h:42 */
#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

/* webserver.h:42 */
#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 ns__add(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__sub(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__mul(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__div(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 f__form1(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 f__form2(struct soap*, struct f__formResponse *_param_2);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

extern "C" SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__add(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__sub(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__mul(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__div(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_f__form1(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_f__form2(struct soap*);

#endif

/* End of soapStub.h */
