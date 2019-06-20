#!/bin/bash
cd $PWD/udp/client
gcc -o UDPEchoClient UDPEchoClient.c -L../../ -lDieWithError.o && ./UDPEchoClient 127.0.0.1 "hello" 5050
