#!/bin/sh

CF_PATH=../../../cppfastdevelop-master/cppfoundation/include
NETSERVER_PATH=../../../cppfastdevelop-master/cpplibrary/netserver/include

cd src
#build tcp_server
g++ -Wall -g tcp_server.cpp -o tcp_server -lrt \
-I$CF_PATH -lcfclass_d \
-I$NETSERVER_PATH -lclnetserver_d 

#build tcp_client
g++ -Wall -g tcp_client.cpp -o tcp_client -lrt \
-I$CF_PATH -lcfclass_d 

#build db_proxy_server
g++ -Wall -g db_proxy_server.cpp db_access_api.cpp -o db_proxy_server -lrt \
-I$CF_PATH -lcfclass_d \
-I$NETSERVER_PATH -lclnetserver_d \
-I/usr/local/mysql/include \
-L/usr/local/mysql/lib \
-lmysqlclient_r

cd ../
mv ./src/tcp_server ./bin
mv ./src/tcp_client ./bin
mv ./src/db_proxy_server ./bin
