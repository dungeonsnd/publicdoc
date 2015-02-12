#!/bin/sh

EXE=/usr/local/thrift-0.9.0/bin/
$EXE/thrift -r --gen cpp message.thrift

