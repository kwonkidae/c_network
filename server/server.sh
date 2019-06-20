#!/bin/bash

gcc -o TCPEchoServer TCPEchoServer.c HandleTCPClient.c -L../ -lDieWithError.o && ./TCPEchoServer 5050

# gcc -o TCPEchoServer TCPEchoServer.c -L../ -lDieWithError.o && ./TCPEchoServer 5050
