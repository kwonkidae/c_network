#!/bin/bash
cd $PWD/socket/signal
gcc -o SigAction SigAction.c -L../../ -lDieWithError.o && ./SigAction
