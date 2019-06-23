#!/bin/bash
cd $PWD/socket/udpTimeout
gcc -o UDPEchoClient-Timeout UDPEchoClient-Timeout.c -L../../ -lDieWithError.o && ./UDPEchoClient-Timeout 127.0.0.1 kkdosk 5050
