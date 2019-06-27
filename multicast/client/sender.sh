#!/bin/bash
cd $PWD/multicast/client
gcc -o MulticastSender MulticastSender.c -L../../ -lDieWithError.o -I./ \
  && ./MulticastSender 225.1.1.1 5050 kkdosk
