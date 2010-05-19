/* EchoServerStub.h
   Generated by gSOAP 2.7.9l from EchoServer.h
   Copyright(C) 2000-2007, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef EchoServerStub_H
#define EchoServerStub_H
#ifndef WITH_NONAMESPACES
#define WITH_NONAMESPACES
#endif
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not redeclare */

#endif

#ifndef SOAP_TYPE_EchoServer__ToUpperResponse
#define SOAP_TYPE_EchoServer__ToUpperResponse (10)
/* EchoServer:ToUpperResponse */
struct EchoServer__ToUpperResponse
{
public:
	std::string Result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__ToUpper
#define SOAP_TYPE_EchoServer__ToUpper (11)
/* EchoServer:ToUpper */
struct EchoServer__ToUpper
{
public:
	std::string S;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__ToLowerResponse
#define SOAP_TYPE_EchoServer__ToLowerResponse (13)
/* EchoServer:ToLowerResponse */
struct EchoServer__ToLowerResponse
{
public:
	std::string Result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__ToLower
#define SOAP_TYPE_EchoServer__ToLower (14)
/* EchoServer:ToLower */
struct EchoServer__ToLower
{
public:
	std::string S;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__EchoResponse
#define SOAP_TYPE_EchoServer__EchoResponse (16)
/* EchoServer:EchoResponse */
struct EchoServer__EchoResponse
{
public:
	std::string Result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__Echo
#define SOAP_TYPE_EchoServer__Echo (17)
/* EchoServer:Echo */
struct EchoServer__Echo
{
public:
	std::string S;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__EchoWithSessionDataResponse
#define SOAP_TYPE_EchoServer__EchoWithSessionDataResponse (19)
/* EchoServer:EchoWithSessionDataResponse */
struct EchoServer__EchoWithSessionDataResponse
{
public:
	std::string Result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__EchoWithSessionData
#define SOAP_TYPE_EchoServer__EchoWithSessionData (20)
/* EchoServer:EchoWithSessionData */
struct EchoServer__EchoWithSessionData
{
public:
	std::string S;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__EchoWithApplicationDataResponse
#define SOAP_TYPE_EchoServer__EchoWithApplicationDataResponse (22)
/* EchoServer:EchoWithApplicationDataResponse */
struct EchoServer__EchoWithApplicationDataResponse
{
public:
	std::string Result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_EchoServer__EchoWithApplicationData
#define SOAP_TYPE_EchoServer__EchoWithApplicationData (23)
/* EchoServer:EchoWithApplicationData */
struct EchoServer__EchoWithApplicationData
{
public:
	std::string S;	/* required element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (24)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (25)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (27)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (30)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (31)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (4)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE_xsd__string
#define SOAP_TYPE_xsd__string (7)
typedef std::string xsd__string;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operations                                                         *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 EchoServer__ToUpper(struct soap*, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 EchoServer__ToLower(struct soap*, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 EchoServer__Echo(struct soap*, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 EchoServer__EchoWithSessionData(struct soap*, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 EchoServer__EchoWithApplicationData(struct soap*, std::string S, std::string &Result);

/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_EchoServer__ToUpper(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_EchoServer__ToLower(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_EchoServer__Echo(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_EchoServer__EchoWithSessionData(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string S, std::string &Result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_EchoServer__EchoWithApplicationData(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string S, std::string &Result);

/******************************************************************************\
 *                                                                            *
 * Skeletons                                                                  *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 EchoServer_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 EchoServer_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__ToUpper(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__ToLower(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__Echo(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__EchoWithSessionData(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_EchoServer__EchoWithApplicationData(struct soap*);

#endif

/* End of EchoServerStub.h */
