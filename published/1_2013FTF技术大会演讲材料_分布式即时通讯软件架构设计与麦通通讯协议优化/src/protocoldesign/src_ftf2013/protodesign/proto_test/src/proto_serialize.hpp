#ifndef _HEADER_FILE_PROTO_SERIALIZE_HPP_
#define _HEADER_FILE_PROTO_SERIALIZE_HPP_

#include <string>

template<typename ProtoStruct>
bool ProtoToString(const ProtoStruct & fmsg, std::string & output)
{
	return fmsg.SerializeToString(&output);
}

template<typename ProtoStruct>
bool StringToProto(ProtoStruct & fmsg, const char * buf, int bufLen)
{
	return fmsg.ParseFromArray(buf,bufLen);
}

#endif  // _HEADER_FILE_PROTO_SERIALIZE_HPP_
