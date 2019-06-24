#!/bin/bash
cd $PWD/fork/server
gcc -o TCPEchoServer-Fork TCPEchoServer-Fork.c TCPEchoServer.c AcceptTCPConnection.c -L../../ -lDieWithError.o -I./ \
  && ./TCPEchoServer-Fork 5050
