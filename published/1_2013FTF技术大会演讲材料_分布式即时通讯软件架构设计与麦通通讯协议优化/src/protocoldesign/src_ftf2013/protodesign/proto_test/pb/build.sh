#!/bin/bash

EXEC=/usr/local/protobuf-2.5.0/bin/protoc

$EXEC -I=./ --cpp_out=../src ./message.proto

