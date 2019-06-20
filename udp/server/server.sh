#!/bin/bash
cd $PWD/udp/server
gcc -o UDPEchoServer UDPEchoServer.c -L../../ -lDieWithError.o && ./UDPEchoServer 5050
