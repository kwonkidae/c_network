#!/bin/bash
cd $PWD/fork/server
gcc -o TCPEchoServer-ForkN TCPEchoServer-ForkN.c CreateTCPServerSocket.c AcceptTCPConnection.c \
  ../../tcp/server/HandleTCPClient.c -L../../ -lDieWithError.o -I./ \
  && ./TCPEchoServer-ForkN 5050 5
