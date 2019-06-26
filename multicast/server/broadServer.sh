#!/bin/bash
cd $PWD/multicast/server
gcc -o MulticastReceiver MulticastReceiver.c -L../../ -lDieWithError.o -I./ \
  && ./MulticastReceiver 225.1.1.1 5050
