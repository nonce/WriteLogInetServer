/* C1Server.cpp
   Generated by gSOAP 2.8.32 for ContestQsos.h

gSOAP XML Web services tools
Copyright (C) 2000-2016, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "C1H.h"

namespace C1 {

SOAP_SOURCE_STAMP("@(#) C1Server.cpp ver 2.8.32 2016-05-13 01:07:37 GMT")
SOAP_FMAC5 int SOAP_FMAC6 C1_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (C1::C1_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 C1_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "contest3:GetSessionId"))
		return soap_serve_contest3__GetSessionId(soap);
	if (!soap_match_tag(soap, soap->tag, "contest3:AddAndGetLogSummary"))
		return soap_serve_contest3__AddAndGetLogSummary(soap);
	if (!soap_match_tag(soap, soap->tag, "contest3:addAndGetQsos"))
		return soap_serve_contest3__addAndGetQsos(soap);
	if (!soap_match_tag(soap, soap->tag, "contest3:getQsosByKeyArray"))
		return soap_serve_contest3__getQsosByKeyArray(soap);
	if (!soap_match_tag(soap, soap->tag, "contest3:ColumnNamesToIndices"))
		return soap_serve_contest3__ColumnNamesToIndices(soap);
	if (!soap_match_tag(soap, soap->tag, "contest3:ExchangeFrequencies"))
		return soap_serve_contest3__ExchangeFrequencies(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_contest3__GetSessionId(struct soap *soap)
{	struct contest3__GetSessionId soap_tmp_contest3__GetSessionId;
	struct contest3__GetSessionIdResponse soap_tmp_contest3__GetSessionIdResponse;
	soap_default_contest3__GetSessionIdResponse(soap, &soap_tmp_contest3__GetSessionIdResponse);
	soap_default_contest3__GetSessionId(soap, &soap_tmp_contest3__GetSessionId);
	if (!soap_get_contest3__GetSessionId(soap, &soap_tmp_contest3__GetSessionId, "contest3:GetSessionId", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = contest3__GetSessionId(soap, soap_tmp_contest3__GetSessionIdResponse.response);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_contest3__GetSessionIdResponse(soap, &soap_tmp_contest3__GetSessionIdResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_contest3__GetSessionIdResponse(soap, &soap_tmp_contest3__GetSessionIdResponse, "contest3:GetSessionIdResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_contest3__GetSessionIdResponse(soap, &soap_tmp_contest3__GetSessionIdResponse, "contest3:GetSessionIdResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_contest3__AddAndGetLogSummary(struct soap *soap)
{	struct contest3__AddAndGetLogSummary soap_tmp_contest3__AddAndGetLogSummary;
	struct contest3__AddAndGetLogSummaryResponse _param_1;
	soap_default_contest3__AddAndGetLogSummaryResponse(soap, &_param_1);
	soap_default_contest3__AddAndGetLogSummary(soap, &soap_tmp_contest3__AddAndGetLogSummary);
	if (!soap_get_contest3__AddAndGetLogSummary(soap, &soap_tmp_contest3__AddAndGetLogSummary, "contest3:AddAndGetLogSummary", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = contest3__AddAndGetLogSummary(soap, soap_tmp_contest3__AddAndGetLogSummary._SessionId, soap_tmp_contest3__AddAndGetLogSummary._QsoAddArray, soap_tmp_contest3__AddAndGetLogSummary._OldState, soap_tmp_contest3__AddAndGetLogSummary._MaxRequested, _param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_contest3__AddAndGetLogSummaryResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_contest3__AddAndGetLogSummaryResponse(soap, &_param_1, "contest3:AddAndGetLogSummaryResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_contest3__AddAndGetLogSummaryResponse(soap, &_param_1, "contest3:AddAndGetLogSummaryResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_contest3__addAndGetQsos(struct soap *soap)
{	struct contest3__addAndGetQsos soap_tmp_contest3__addAndGetQsos;
	struct contest3__addAndGetQsosResponse _param_1;
	soap_default_contest3__addAndGetQsosResponse(soap, &_param_1);
	soap_default_contest3__addAndGetQsos(soap, &soap_tmp_contest3__addAndGetQsos);
	if (!soap_get_contest3__addAndGetQsos(soap, &soap_tmp_contest3__addAndGetQsos, "contest3:addAndGetQsos", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = contest3__addAndGetQsos(soap, soap_tmp_contest3__addAndGetQsos._SessionId, soap_tmp_contest3__addAndGetQsos._QsoAddArray, soap_tmp_contest3__addAndGetQsos._OldState, soap_tmp_contest3__addAndGetQsos._MaxRequested, _param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_contest3__addAndGetQsosResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_contest3__addAndGetQsosResponse(soap, &_param_1, "contest3:addAndGetQsosResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_contest3__addAndGetQsosResponse(soap, &_param_1, "contest3:addAndGetQsosResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_contest3__getQsosByKeyArray(struct soap *soap)
{	struct contest3__getQsosByKeyArray soap_tmp_contest3__getQsosByKeyArray;
	struct contest3__getQsosByKeyArrayResponse _param_1;
	soap_default_contest3__getQsosByKeyArrayResponse(soap, &_param_1);
	soap_default_contest3__getQsosByKeyArray(soap, &soap_tmp_contest3__getQsosByKeyArray);
	if (!soap_get_contest3__getQsosByKeyArray(soap, &soap_tmp_contest3__getQsosByKeyArray, "contest3:getQsosByKeyArray", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = contest3__getQsosByKeyArray(soap, soap_tmp_contest3__getQsosByKeyArray._SessionId, soap_tmp_contest3__getQsosByKeyArray._QsoKeyArray, _param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_contest3__getQsosByKeyArrayResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_contest3__getQsosByKeyArrayResponse(soap, &_param_1, "contest3:getQsosByKeyArrayResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_contest3__getQsosByKeyArrayResponse(soap, &_param_1, "contest3:getQsosByKeyArrayResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_contest3__ColumnNamesToIndices(struct soap *soap)
{	struct contest3__ColumnNamesToIndices soap_tmp_contest3__ColumnNamesToIndices;
	struct contest3__ColumnNamesToIndicesResponse _param_1;
	soap_default_contest3__ColumnNamesToIndicesResponse(soap, &_param_1);
	soap_default_contest3__ColumnNamesToIndices(soap, &soap_tmp_contest3__ColumnNamesToIndices);
	if (!soap_get_contest3__ColumnNamesToIndices(soap, &soap_tmp_contest3__ColumnNamesToIndices, "contest3:ColumnNamesToIndices", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = contest3__ColumnNamesToIndices(soap, soap_tmp_contest3__ColumnNamesToIndices._SessionId, soap_tmp_contest3__ColumnNamesToIndices._ColumnNames, _param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_contest3__ColumnNamesToIndicesResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_contest3__ColumnNamesToIndicesResponse(soap, &_param_1, "contest3:ColumnNamesToIndicesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_contest3__ColumnNamesToIndicesResponse(soap, &_param_1, "contest3:ColumnNamesToIndicesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_contest3__ExchangeFrequencies(struct soap *soap)
{	struct contest3__ExchangeFrequencies soap_tmp_contest3__ExchangeFrequencies;
	struct contest3__ExchangeFrequenciesResponse _param_1;
	soap_default_contest3__ExchangeFrequenciesResponse(soap, &_param_1);
	soap_default_contest3__ExchangeFrequencies(soap, &soap_tmp_contest3__ExchangeFrequencies);
	if (!soap_get_contest3__ExchangeFrequencies(soap, &soap_tmp_contest3__ExchangeFrequencies, "contest3:ExchangeFrequencies", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = contest3__ExchangeFrequencies(soap, soap_tmp_contest3__ExchangeFrequencies._IncomingFreqs, _param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_contest3__ExchangeFrequenciesResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_contest3__ExchangeFrequenciesResponse(soap, &_param_1, "contest3:ExchangeFrequenciesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_contest3__ExchangeFrequenciesResponse(soap, &_param_1, "contest3:ExchangeFrequenciesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

} // namespace C1


#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of C1Server.cpp */
