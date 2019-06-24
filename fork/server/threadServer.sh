#!/bin/bash
cd $PWD/fork/server
gcc -o TCPEchoServer-Thread TCPEchoServer-Thread.c CreateTCPServerSocket.c AcceptTCPConnection.c \
  ../../tcp/server/HandleTCPClient.c -L../../ -lDieWithError.o -I./ \
  && ./TCPEchoServer-Thread 5050
