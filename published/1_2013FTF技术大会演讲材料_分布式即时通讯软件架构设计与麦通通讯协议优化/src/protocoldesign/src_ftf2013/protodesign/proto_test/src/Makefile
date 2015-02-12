#!/bin/sh

COMPER		= g++
LINKER		= g++
COMMINC		= -I. -I../../common -I/usr/local/protobuf-2.5.0/include/ -I/usr/local/zlib-1.2.8/include/
CMPFLAG		= -g -O0 -Wall -c $(COMMINC)
LNKFLAG     =  
LIBDIR	= -L. -L/usr/local/protobuf-2.5.0/lib/ -L/usr/local/zlib-1.2.8/lib
LIB		= $(LIBDIR) -lprotobuf -lz

EXE =  protobuf250_test

all : $(EXE)


OBJ =   \
main.o \
message.pb.o

BINDIR =../bin

clean:
	rm -rf $(OBJ)
	rm -rf $(BINDIR)/$(EXE)

%.o:%.cpp
	$(COMPER) $(CMPFLAG) $<
%.o:%.cc
	$(COMPER) $(CMPFLAG) $<

$(EXE):$(OBJ)
	$(LINKER) $(LNKFLAG) $(LIB) -o $@ $?
	mv $@ $(BINDIR)
