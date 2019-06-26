#!/bin/bash
cd $PWD/fork/server
gcc -o TCPEchoServer-Select TCPEchoServer-Select.c CreateTCPServerSocket.c AcceptTCPConnection.c \
  ../../tcp/server/HandleTCPClient.c -L../../ -lDieWithError.o -I./ \
  && ./TCPEchoServer-Select 4 5050 5051
