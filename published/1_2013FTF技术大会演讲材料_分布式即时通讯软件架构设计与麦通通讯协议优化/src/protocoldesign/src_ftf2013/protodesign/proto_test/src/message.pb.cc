// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* FriendMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  FriendMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_message_2eproto() {
  protobuf_AddDesc_message_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "message.proto");
  GOOGLE_CHECK(file != NULL);
  FriendMessage_descriptor_ = file->message_type(0);
  static const int FriendMessage_offsets_[13] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, fromuid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, touid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, servermessageid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, clientmessageid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, servertime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, clienttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, messagetype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, content_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, fontdefault_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, fontface_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, fontsize_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, fontcolor_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, fontflag_),
  };
  FriendMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      FriendMessage_descriptor_,
      FriendMessage::default_instance_,
      FriendMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(FriendMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(FriendMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_message_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    FriendMessage_descriptor_, &FriendMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_message_2eproto() {
  delete FriendMessage::default_instance_;
  delete FriendMessage_reflection_;
}

void protobuf_AddDesc_message_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\rmessage.proto\"\215\002\n\rFriendMessage\022\017\n\007fro"
    "muid\030\001 \002(\r\022\r\n\005touid\030\002 \002(\r\022\027\n\017servermessa"
    "geid\030\003 \002(\r\022\027\n\017clientmessageid\030\004 \002(\r\022\022\n\ns"
    "ervertime\030\005 \002(\r\022\022\n\nclienttime\030\006 \002(\r\022\023\n\013m"
    "essagetype\030\007 \002(\r\022\017\n\007content\030\010 \001(\t\022\023\n\013fon"
    "tdefault\030\t \001(\r\022\020\n\010fontface\030\n \001(\t\022\020\n\010font"
    "size\030\013 \001(\r\022\021\n\tfontcolor\030\014 \001(\r\022\020\n\010fontfla"
    "g\030\r \001(\r", 287);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "message.proto", &protobuf_RegisterTypes);
  FriendMessage::default_instance_ = new FriendMessage();
  FriendMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_message_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_message_2eproto {
  StaticDescriptorInitializer_message_2eproto() {
    protobuf_AddDesc_message_2eproto();
  }
} static_descriptor_initializer_message_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int FriendMessage::kFromuidFieldNumber;
const int FriendMessage::kTouidFieldNumber;
const int FriendMessage::kServermessageidFieldNumber;
const int FriendMessage::kClientmessageidFieldNumber;
const int FriendMessage::kServertimeFieldNumber;
const int FriendMessage::kClienttimeFieldNumber;
const int FriendMessage::kMessagetypeFieldNumber;
const int FriendMessage::kContentFieldNumber;
const int FriendMessage::kFontdefaultFieldNumber;
const int FriendMessage::kFontfaceFieldNumber;
const int FriendMessage::kFontsizeFieldNumber;
const int FriendMessage::kFontcolorFieldNumber;
const int FriendMessage::kFontflagFieldNumber;
#endif  // !_MSC_VER

FriendMessage::FriendMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void FriendMessage::InitAsDefaultInstance() {
}

FriendMessage::FriendMessage(const FriendMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void FriendMessage::SharedCtor() {
  _cached_size_ = 0;
  fromuid_ = 0u;
  touid_ = 0u;
  servermessageid_ = 0u;
  clientmessageid_ = 0u;
  servertime_ = 0u;
  clienttime_ = 0u;
  messagetype_ = 0u;
  content_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  fontdefault_ = 0u;
  fontface_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  fontsize_ = 0u;
  fontcolor_ = 0u;
  fontflag_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

FriendMessage::~FriendMessage() {
  SharedDtor();
}

void FriendMessage::SharedDtor() {
  if (content_ != &::google::protobuf::internal::kEmptyString) {
    delete content_;
  }
  if (fontface_ != &::google::protobuf::internal::kEmptyString) {
    delete fontface_;
  }
  if (this != default_instance_) {
  }
}

void FriendMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* FriendMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FriendMessage_descriptor_;
}

const FriendMessage& FriendMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_message_2eproto();
  return *default_instance_;
}

FriendMessage* FriendMessage::default_instance_ = NULL;

FriendMessage* FriendMessage::New() const {
  return new FriendMessage;
}

void FriendMessage::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    fromuid_ = 0u;
    touid_ = 0u;
    servermessageid_ = 0u;
    clientmessageid_ = 0u;
    servertime_ = 0u;
    clienttime_ = 0u;
    messagetype_ = 0u;
    if (has_content()) {
      if (content_ != &::google::protobuf::internal::kEmptyString) {
        content_->clear();
      }
    }
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    fontdefault_ = 0u;
    if (has_fontface()) {
      if (fontface_ != &::google::protobuf::internal::kEmptyString) {
        fontface_->clear();
      }
    }
    fontsize_ = 0u;
    fontcolor_ = 0u;
    fontflag_ = 0u;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool FriendMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 fromuid = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fromuid_)));
          set_has_fromuid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_touid;
        break;
      }

      // required uint32 touid = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_touid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &touid_)));
          set_has_touid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_servermessageid;
        break;
      }

      // required uint32 servermessageid = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_servermessageid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &servermessageid_)));
          set_has_servermessageid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_clientmessageid;
        break;
      }

      // required uint32 clientmessageid = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_clientmessageid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &clientmessageid_)));
          set_has_clientmessageid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_servertime;
        break;
      }

      // required uint32 servertime = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_servertime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &servertime_)));
          set_has_servertime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_clienttime;
        break;
      }

      // required uint32 clienttime = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_clienttime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &clienttime_)));
          set_has_clienttime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_messagetype;
        break;
      }

      // required uint32 messagetype = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_messagetype:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &messagetype_)));
          set_has_messagetype();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(66)) goto parse_content;
        break;
      }

      // optional string content = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_content:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_content()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->content().data(), this->content().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_fontdefault;
        break;
      }

      // optional uint32 fontdefault = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fontdefault:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fontdefault_)));
          set_has_fontdefault();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(82)) goto parse_fontface;
        break;
      }

      // optional string fontface = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_fontface:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_fontface()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->fontface().data(), this->fontface().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_fontsize;
        break;
      }

      // optional uint32 fontsize = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fontsize:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fontsize_)));
          set_has_fontsize();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_fontcolor;
        break;
      }

      // optional uint32 fontcolor = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fontcolor:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fontcolor_)));
          set_has_fontcolor();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(104)) goto parse_fontflag;
        break;
      }

      // optional uint32 fontflag = 13;
      case 13: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_fontflag:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &fontflag_)));
          set_has_fontflag();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void FriendMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 fromuid = 1;
  if (has_fromuid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->fromuid(), output);
  }

  // required uint32 touid = 2;
  if (has_touid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->touid(), output);
  }

  // required uint32 servermessageid = 3;
  if (has_servermessageid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(3, this->servermessageid(), output);
  }

  // required uint32 clientmessageid = 4;
  if (has_clientmessageid()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(4, this->clientmessageid(), output);
  }

  // required uint32 servertime = 5;
  if (has_servertime()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(5, this->servertime(), output);
  }

  // required uint32 clienttime = 6;
  if (has_clienttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(6, this->clienttime(), output);
  }

  // required uint32 messagetype = 7;
  if (has_messagetype()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(7, this->messagetype(), output);
  }

  // optional string content = 8;
  if (has_content()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->content().data(), this->content().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      8, this->content(), output);
  }

  // optional uint32 fontdefault = 9;
  if (has_fontdefault()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(9, this->fontdefault(), output);
  }

  // optional string fontface = 10;
  if (has_fontface()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->fontface().data(), this->fontface().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      10, this->fontface(), output);
  }

  // optional uint32 fontsize = 11;
  if (has_fontsize()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(11, this->fontsize(), output);
  }

  // optional uint32 fontcolor = 12;
  if (has_fontcolor()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(12, this->fontcolor(), output);
  }

  // optional uint32 fontflag = 13;
  if (has_fontflag()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(13, this->fontflag(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* FriendMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 fromuid = 1;
  if (has_fromuid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->fromuid(), target);
  }

  // required uint32 touid = 2;
  if (has_touid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->touid(), target);
  }

  // required uint32 servermessageid = 3;
  if (has_servermessageid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(3, this->servermessageid(), target);
  }

  // required uint32 clientmessageid = 4;
  if (has_clientmessageid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(4, this->clientmessageid(), target);
  }

  // required uint32 servertime = 5;
  if (has_servertime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(5, this->servertime(), target);
  }

  // required uint32 clienttime = 6;
  if (has_clienttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(6, this->clienttime(), target);
  }

  // required uint32 messagetype = 7;
  if (has_messagetype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(7, this->messagetype(), target);
  }

  // optional string content = 8;
  if (has_content()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->content().data(), this->content().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->content(), target);
  }

  // optional uint32 fontdefault = 9;
  if (has_fontdefault()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(9, this->fontdefault(), target);
  }

  // optional string fontface = 10;
  if (has_fontface()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->fontface().data(), this->fontface().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        10, this->fontface(), target);
  }

  // optional uint32 fontsize = 11;
  if (has_fontsize()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(11, this->fontsize(), target);
  }

  // optional uint32 fontcolor = 12;
  if (has_fontcolor()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(12, this->fontcolor(), target);
  }

  // optional uint32 fontflag = 13;
  if (has_fontflag()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(13, this->fontflag(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int FriendMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 fromuid = 1;
    if (has_fromuid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fromuid());
    }

    // required uint32 touid = 2;
    if (has_touid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->touid());
    }

    // required uint32 servermessageid = 3;
    if (has_servermessageid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->servermessageid());
    }

    // required uint32 clientmessageid = 4;
    if (has_clientmessageid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->clientmessageid());
    }

    // required uint32 servertime = 5;
    if (has_servertime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->servertime());
    }

    // required uint32 clienttime = 6;
    if (has_clienttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->clienttime());
    }

    // required uint32 messagetype = 7;
    if (has_messagetype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->messagetype());
    }

    // optional string content = 8;
    if (has_content()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->content());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional uint32 fontdefault = 9;
    if (has_fontdefault()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fontdefault());
    }

    // optional string fontface = 10;
    if (has_fontface()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->fontface());
    }

    // optional uint32 fontsize = 11;
    if (has_fontsize()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fontsize());
    }

    // optional uint32 fontcolor = 12;
    if (has_fontcolor()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fontcolor());
    }

    // optional uint32 fontflag = 13;
    if (has_fontflag()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->fontflag());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void FriendMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const FriendMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const FriendMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void FriendMessage::MergeFrom(const FriendMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_fromuid()) {
      set_fromuid(from.fromuid());
    }
    if (from.has_touid()) {
      set_touid(from.touid());
    }
    if (from.has_servermessageid()) {
      set_servermessageid(from.servermessageid());
    }
    if (from.has_clientmessageid()) {
      set_clientmessageid(from.clientmessageid());
    }
    if (from.has_servertime()) {
      set_servertime(from.servertime());
    }
    if (from.has_clienttime()) {
      set_clienttime(from.clienttime());
    }
    if (from.has_messagetype()) {
      set_messagetype(from.messagetype());
    }
    if (from.has_content()) {
      set_content(from.content());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_fontdefault()) {
      set_fontdefault(from.fontdefault());
    }
    if (from.has_fontface()) {
      set_fontface(from.fontface());
    }
    if (from.has_fontsize()) {
      set_fontsize(from.fontsize());
    }
    if (from.has_fontcolor()) {
      set_fontcolor(from.fontcolor());
    }
    if (from.has_fontflag()) {
      set_fontflag(from.fontflag());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void FriendMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void FriendMessage::CopyFrom(const FriendMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool FriendMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000007f) != 0x0000007f) return false;

  return true;
}

void FriendMessage::Swap(FriendMessage* other) {
  if (other != this) {
    std::swap(fromuid_, other->fromuid_);
    std::swap(touid_, other->touid_);
    std::swap(servermessageid_, other->servermessageid_);
    std::swap(clientmessageid_, other->clientmessageid_);
    std::swap(servertime_, other->servertime_);
    std::swap(clienttime_, other->clienttime_);
    std::swap(messagetype_, other->messagetype_);
    std::swap(content_, other->content_);
    std::swap(fontdefault_, other->fontdefault_);
    std::swap(fontface_, other->fontface_);
    std::swap(fontsize_, other->fontsize_);
    std::swap(fontcolor_, other->fontcolor_);
    std::swap(fontflag_, other->fontflag_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata FriendMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = FriendMessage_descriptor_;
  metadata.reflection = FriendMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
