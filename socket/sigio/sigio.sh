#!/bin/bash
cd $PWD/socket/sigio
gcc -o UDPEchoServer-SIGIO UDPEchoServer-SIGIO.c -L../../ -lDieWithError.o && ./UDPEchoServer-SIGIO
