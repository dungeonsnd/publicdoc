#!/bin/sh

cd ./src

g++ -Wall -g zdt1_fork_exec.cpp -o zdt1_fork_exec
mv ./zdt1_fork_exec ../bin/zdt1_fork_exec

g++ -Wall -g zdt2_transmit_fd.cpp -o zdt2_transmit_fd
mv ./zdt2_transmit_fd ../bin/zdt2_transmit_fd

cd ../

