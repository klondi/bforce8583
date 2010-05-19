/*!	\file	*/
// ISO8583FEClientSession.cpp: implementation of the CISO8583FEClientSession class.
//
//////////////////////////////////////////////////////////////////////
/*

MultiX Network Applications Development Toolkit.
Copyright (C) 2007, Moshe Shitrit, Mitug Distributed Systems Ltd., All Rights Reserved.

This file is part of MultiX.

MultiX is free software; you can redistribute it and/or modify it under the terms of the 
GNU General Public License as published by the Free Software Foundation; 
either version 2 of the License, or (at your option) any later version. 

MultiX is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program;
if not, write to the 
Free Software Foundation, Inc., 
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
--------------------------------------------------------------------------------
Author contact information: 
msr@mitug.co.il
--------------------------------------------------------------------------------

*/

#include "ISO8583FE.h"
#include	"ISO8583FEApp.h"
#include "ISO8583FEClientSession.h"
#include	"ISO8583FELink.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//! call the base class constructor,a default session id will be assigned to the session
CISO8583FEClientSession::CISO8583FEClientSession(CISO8583FEApp	&Owner)	:
	CMultiXSession(Owner)
{
}

//! just make sure the m_pLastTpmMsg deleted, if not , we have a bug
CISO8583FEClientSession::~CISO8583FEClientSession()
{
//	DebugPrint("Deleted\n");
}

/*!
\\return	always true, tell the garbage collector that it can delete the object. 

	in any case, this function is called only if we left the session.
*/
bool CISO8583FEClientSession::CanDelete()
{
	return	true;
}

/*!
	this function is called by the associated link. in this case, we reply with error to the last
	message we received from tpm, if there is one, and we set m_LinkID to an empty ID which points
	to no link object.
*/
void CISO8583FEClientSession::OnLinkDisconnected()
{
	DebugPrint(2,"Link Disconnected\n");
	m_LinkID	=	CMultiXLinkID();
}

/*!
\param	pLink	a pointer to the link that created the session object
	The link object that created the session objects, notify us that it is the one that
	handles the connection to the other peer, we keep its ID.
*/
void CISO8583FEClientSession::OnLinkConnected(CISO8583FELink *pLink)
{
	DebugPrint(2,"Link Connected\n");
	m_LinkID	=	pLink->GetID();
}


/*!
\param	PartnerMsg	the message received from the session partner, it is allways a data message.
\return	true

	The associated link notifies us of a newly received message.
*/
bool CISO8583FEClientSession::OnNewPartnerMsg(CISO8583FEMsg &PartnerMsg,int32_t	ForwardingMsgCode)
{
	if(!SendWSRequest(ForwardingMsgCode,"","","","",*PartnerMsg.Data(),CMultiXAppMsg::FlagNotifyAll))
//	if(!Send(ForwardingMsgCode,*PartnerMsg.Data(),CMultiXAppMsg::FlagNotifyAll))
	{
		Throw();
	}
	DebugPrint(2,"Msg Sent to TPM\n");
	return	true;
}

/*!
	see CMultiXSession::OnSendMsgCompleted
	We notify the associated link that the last message received from the POS terminal
	was processed succefuly by the server application.
*/
void	CISO8583FEClientSession::OnSendMsgCompleted(CMultiXAppMsg &OriginalMsg)
{
	DebugPrint(2,"Send Msg Completed\n");
		CISO8583FELink	*pLink	=	GetLink();
	if(pLink)
		pLink->OnSessionSendCompleted(OriginalMsg);
			
}

/*!
	see CMultiXSession::OnSendMsgFailed
	We notify the associated link that the last message received from the POS terminal
	was not processed succefuly by the server application.
*/
void	CISO8583FEClientSession::OnSendMsgFailed(CMultiXAppMsg &OriginalMsg)
{
	DebugPrint(2,"Send Msg Failed\n");
		CISO8583FELink	*pLink	=	GetLink();
	if(pLink)
		pLink->OnSessionSendFailed(OriginalMsg,ErrUnableToForwardMsg);
	}
/*!
	see CMultiXSession::OnSendMsgTimedout
	We notify the associated link that the last message received from the POS terminal
	was not processed succefuly by the server application.
*/
void	CISO8583FEClientSession::OnSendMsgTimedout(CMultiXAppMsg &OriginalMsg)
{
	DebugPrint(2,"Send Msg Timedout\n");
		CISO8583FELink	*pLink	=	GetLink();
	if(pLink)
		pLink->OnSessionSendFailed(OriginalMsg,ErrMsgForwardTimedout);
	
}
/*!
	see	CMultiXSession::OnDataReplyReceived

	this reply is for a message or an ACK previously received from the POS terminal.
*/
void	CISO8583FEClientSession::OnDataReplyReceived(CMultiXAppMsg &ReplyMsg,CMultiXAppMsg &OriginalMsg)
{
	DebugPrint(2,"Data Reply Received\n");
	
		
	CISO8583FELink	*pLink	=	GetLink();
	

	if(!pLink)	//	probably the link was disconnected before the reply was received
	{
		int	Error	=	ErrLinkDisconnected;	
		//	TODO:	Set an application specific error code
		
		ReplyMsg.Reply(Error);
		return;
	}

	if(ReplyMsg.AppDataSize()	==	0)	//	an empty reply from the server application
	{
		if(ReplyMsg.Error()	!=	0)
			pLink->OnSessionSendFailed(OriginalMsg,ReplyMsg.Error());
		else
			pLink->OnSessionSendCompleted(OriginalMsg);
		ReplyMsg.Reply();	//	just reply to the received msg, in case the sender expects a reply
		return;
	}


	// forward the reply to the associated link
	CMultiXBuffer	*Buf	=	Owner()->AllocateBuffer(ReplyMsg.AppData(),ReplyMsg.AppDataSize());

	pLink->OnSessionReply(*Buf,OriginalMsg);
	Buf->ReturnBuffer();
	ReplyMsg.Reply(0);

	}

/*!
	\return a pointer to the associated link based on m_LinkID.
*/
CISO8583FELink * CISO8583FEClientSession::GetLink()
{
	return	(CISO8583FELink *)m_LinkID.GetObject();
}

/*! see CMultiXSession::OnSessionKilled
in our case we just leave the session
*/
void	CISO8583FEClientSession::OnSessionKilled(CMultiXProcess *KillingProcess)
{
//	DebugPrint("Killed\n");
	Leave();
}

/*! see CMultiXSession::CheckStatus
*/
bool	CISO8583FEClientSession::CheckStatus()
{
	if(GetLink()	==	NULL)
		Kill();
	//	by returning true we will disable the deletion of the session based on Idle timer
	return	true;
}
