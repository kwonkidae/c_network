#!/bin/bash
cd /Users/kidaekwon/study/c/network/udp/client
gcc -o UDPEchoClient UDPEchoClient.c -L../../ -lDieWithError.o && ./UDPEchoClient 127.0.0.1 "hello" 5050
