#!/bin/sh

cd src
g++ -DHAVE_NETINET_IN_H -Wall -g main.cpp ./protocol/gen-cpp/message_types.cpp ./protocol/gen-cpp/message_constants.cpp  -I../../common -I./protocol -I/usr/local/thrift-0.9.0/include  -I/usr/local/zlib-1.2.8/include/ -L/usr/local/thrift-0.9.0/lib -L/usr/local/zlib-1.2.8/lib -lthrift -lz -o thrift090_test
mv thrift090_test ../bin
cd ../
