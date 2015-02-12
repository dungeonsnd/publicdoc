#ifndef _HEADER_FILE_SERIALIZE_H_
#define _HEADER_FILE_SERIALIZE_H_

#include <thrift/config.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TTransportUtils.h>

template<typename ThriftStruct>
bool ThriftToString(const ThriftStruct& ts, std::string & output) 
{
  using namespace apache::thrift::transport;
  using namespace apache::thrift::protocol;
  boost::shared_ptr<TMemoryBuffer> membuffer(new TMemoryBuffer());
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(membuffer));
  ts.write(protocol.get());
  uint8_t* buf;
  uint32_t size;
  membuffer->getBuffer(&buf, &size);
  output.assign((char*)(buf), size_t(size));
  return true;
}

template<typename ThriftStruct>
bool StringToThrift(ThriftStruct & ts, const char * buf, int bufLen) 
{
  using namespace apache::thrift::transport;
  using namespace apache::thrift::protocol;
  TMemoryBuffer* pmembuffer = new TMemoryBuffer;
  pmembuffer->write((const uint8_t*)buf, size_t(bufLen));
  boost::shared_ptr<TMemoryBuffer> membuffer(pmembuffer);
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(membuffer));
  ts.read(protocol.get());
  return true;
}

#endif  // _HEADER_FILE_SERIALIZE_H_
