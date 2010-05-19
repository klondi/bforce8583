/* soapStub.h
   Generated by gSOAP 2.7.9l from dime.h
   Copyright(C) 2000-2007, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
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




#ifndef SOAP_TYPE_ns__Data
#define SOAP_TYPE_ns__Data (6)
/* Base64 schema type: */
class SOAP_CMAC ns__Data
{
public:
	unsigned char *__ptr;
	int __size;
	char *id;	/* optional element of type xsd:string */
	char *type;	/* optional element of type xsd:string */
	char *options;	/* optional element of type xsd:string */
	ns__Data();	/* transient */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 6; } /* = unique id SOAP_TYPE_ns__Data */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	virtual ~ns__Data() { }
};
#endif

#ifndef SOAP_TYPE_arrayOfData
#define SOAP_TYPE_arrayOfData (15)
/* SOAP encoded array of ns:Data schema type: */
class SOAP_CMAC arrayOfData
{
public:
	ns__Data *__ptr;
	int __size;
	arrayOfData();	/* transient */
	arrayOfData(struct soap *_param_1, int _param_2);	/* transient */
	virtual ~arrayOfData();	/* transient */
	int size();	/* transient */
	void resize(int _param_3);	/* transient */
	ns__Data &operator[](int _param_4) const;	/* transient */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE_arrayOfData */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
};
#endif

#ifndef SOAP_TYPE_arrayOfName
#define SOAP_TYPE_arrayOfName (26)
/* SOAP encoded array of xsd:string schema type: */
class SOAP_CMAC arrayOfName
{
public:
	char **__ptr;
	int __size;
	arrayOfName();	/* transient */
	arrayOfName(struct soap *_param_5, int _param_6);	/* transient */
	virtual ~arrayOfName();	/* transient */
	int size();	/* transient */
	void resize(int _param_7);	/* transient */
	char *&operator[](int _param_8) const;	/* transient */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 26; } /* = unique id SOAP_TYPE_arrayOfName */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
};
#endif

#ifndef SOAP_TYPE_ns__putDataResponse
#define SOAP_TYPE_ns__putDataResponse (38)
/* ns:putDataResponse */
struct ns__putDataResponse
{
public:
	arrayOfName *names;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfstring */
};
#endif

#ifndef SOAP_TYPE_ns__putData
#define SOAP_TYPE_ns__putData (39)
/* ns:putData */
struct ns__putData
{
public:
	arrayOfData *data;	/* optional element of type ArrayOfData */
};
#endif

#ifndef SOAP_TYPE_ns__getDataResponse
#define SOAP_TYPE_ns__getDataResponse (41)
/* ns:getDataResponse */
struct ns__getDataResponse
{
public:
	arrayOfData *data;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ArrayOfData */
};
#endif

#ifndef SOAP_TYPE_ns__getData
#define SOAP_TYPE_ns__getData (42)
/* ns:getData */
struct ns__getData
{
public:
	arrayOfName *names;	/* optional element of type ArrayOfstring */
};
#endif

#ifndef SOAP_TYPE_ns__getImageResponse
#define SOAP_TYPE_ns__getImageResponse (44)
/* ns:getImageResponse */
struct ns__getImageResponse
{
public:
	ns__Data image;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type ns:Data */
};
#endif

#ifndef SOAP_TYPE_ns__getImage
#define SOAP_TYPE_ns__getImage (45)
/* ns:getImage */
struct ns__getImage
{
public:
	char *name;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (46)
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
#define SOAP_TYPE_SOAP_ENV__Code (47)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (49)
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
#define SOAP_TYPE_SOAP_ENV__Reason (51)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (52)
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


SOAP_FMAC5 int SOAP_FMAC6 ns__putData(struct soap*, arrayOfData *data, arrayOfName *names);

SOAP_FMAC5 int SOAP_FMAC6 ns__getData(struct soap*, arrayOfName *names, arrayOfData *data);

SOAP_FMAC5 int SOAP_FMAC6 ns__getImage(struct soap*, char *name, ns__Data &image);

/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__putData(struct soap *soap, const char *soap_endpoint, const char *soap_action, arrayOfData *data, arrayOfName *names);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getData(struct soap *soap, const char *soap_endpoint, const char *soap_action, arrayOfName *names, arrayOfData *data);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__getImage(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *name, ns__Data &image);

/******************************************************************************\
 *                                                                            *
 * Skeletons                                                                  *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__putData(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__getData(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__getImage(struct soap*);

#endif

/* End of soapStub.h */
