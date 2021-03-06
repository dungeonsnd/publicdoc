/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef message_TYPES_H
#define message_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>





typedef struct _FriendMessage__isset {
  _FriendMessage__isset() : fromuid(false), touid(false), servermessageid(false), clientmessageid(false), servertime(false), clienttime(false), messagetype(false), content(false), fontdefault(false), fontface(false), fontsize(false), fontcolor(false), fontflag(false) {}
  bool fromuid;
  bool touid;
  bool servermessageid;
  bool clientmessageid;
  bool servertime;
  bool clienttime;
  bool messagetype;
  bool content;
  bool fontdefault;
  bool fontface;
  bool fontsize;
  bool fontcolor;
  bool fontflag;
} _FriendMessage__isset;

class FriendMessage {
 public:

  static const char* ascii_fingerprint; // = "DAD4FCEC9A3CBDC65DE17E5AF1F16AE1";
  static const uint8_t binary_fingerprint[16]; // = {0xDA,0xD4,0xFC,0xEC,0x9A,0x3C,0xBD,0xC6,0x5D,0xE1,0x7E,0x5A,0xF1,0xF1,0x6A,0xE1};

  FriendMessage() : fromuid(0), touid(0), servermessageid(0), clientmessageid(0), servertime(0), clienttime(0), messagetype(0), content(), fontdefault(0), fontface(), fontsize(0), fontcolor(0), fontflag(0) {
  }

  virtual ~FriendMessage() throw() {}

  int32_t fromuid;
  int32_t touid;
  int32_t servermessageid;
  int32_t clientmessageid;
  int32_t servertime;
  int32_t clienttime;
  int32_t messagetype;
  std::string content;
  int32_t fontdefault;
  std::string fontface;
  int32_t fontsize;
  int32_t fontcolor;
  int32_t fontflag;

  _FriendMessage__isset __isset;

  void __set_fromuid(const int32_t val) {
    fromuid = val;
  }

  void __set_touid(const int32_t val) {
    touid = val;
  }

  void __set_servermessageid(const int32_t val) {
    servermessageid = val;
  }

  void __set_clientmessageid(const int32_t val) {
    clientmessageid = val;
  }

  void __set_servertime(const int32_t val) {
    servertime = val;
  }

  void __set_clienttime(const int32_t val) {
    clienttime = val;
  }

  void __set_messagetype(const int32_t val) {
    messagetype = val;
  }

  void __set_content(const std::string& val) {
    content = val;
  }

  void __set_fontdefault(const int32_t val) {
    fontdefault = val;
  }

  void __set_fontface(const std::string& val) {
    fontface = val;
  }

  void __set_fontsize(const int32_t val) {
    fontsize = val;
  }

  void __set_fontcolor(const int32_t val) {
    fontcolor = val;
  }

  void __set_fontflag(const int32_t val) {
    fontflag = val;
  }

  bool operator == (const FriendMessage & rhs) const
  {
    if (!(fromuid == rhs.fromuid))
      return false;
    if (!(touid == rhs.touid))
      return false;
    if (!(servermessageid == rhs.servermessageid))
      return false;
    if (!(clientmessageid == rhs.clientmessageid))
      return false;
    if (!(servertime == rhs.servertime))
      return false;
    if (!(clienttime == rhs.clienttime))
      return false;
    if (!(messagetype == rhs.messagetype))
      return false;
    if (!(content == rhs.content))
      return false;
    if (!(fontdefault == rhs.fontdefault))
      return false;
    if (!(fontface == rhs.fontface))
      return false;
    if (!(fontsize == rhs.fontsize))
      return false;
    if (!(fontcolor == rhs.fontcolor))
      return false;
    if (!(fontflag == rhs.fontflag))
      return false;
    return true;
  }
  bool operator != (const FriendMessage &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FriendMessage & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(FriendMessage &a, FriendMessage &b);



#endif
