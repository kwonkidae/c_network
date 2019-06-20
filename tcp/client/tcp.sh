#!/bin/bash

gcc -o TCPEchoClient TCPEchoClient.c -L../../ -lDieWithError.o && ./TCPEchoClient 127.0.0.1 "hello" 5050
