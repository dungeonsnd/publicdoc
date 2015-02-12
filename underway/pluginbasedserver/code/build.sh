#!/bin/sh

cd ./src

g++ -Wall -g -fPIC -shared plugins/plug_a.cpp -olibplug_a.so -I./
mv ./libplug_a.so ../bin/plugins
g++ -Wall -g -fPIC -shared plugins/plug_b.cpp -olibplug_b.so -I./
mv ./libplug_b.so ../bin/plugins
g++ -Wall -g -fPIC -shared plugins/plug_c.cpp -olibplug_c.so -I./
mv ./libplug_c.so ../bin/plugins
g++ -Wall -g -fPIC -shared plugins/plug_c1.cpp -olibplug_c1.so -I./
mv ./libplug_c1.so ../bin/plugins
g++ -Wall -g -fPIC -shared plugins/plug_c2.cpp -olibplug_c2.so -I./
mv ./libplug_c2.so ../bin/plugins

g++ -Wall -g server_main.cpp plugin_mgr.cpp -o server_main -ldl
mv ./server_main ../bin

cd ../

