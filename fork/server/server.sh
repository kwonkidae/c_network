#!/bin/bash
cd $PWD/fork/server
gcc -o TCPEchoServer-Fork TCPEchoServer-Fork.c CreateTCPServerSocket.c AcceptTCPConnection.c \
  ../../tcp/server/HandleTCPClient.c -L../../ -lDieWithError.o -I./ \
  && ./TCPEchoServer-Fork 5050
