#!/bin/bash
cd $PWD/broadcast/server
gcc -o BroadcastReceiver BroadcastReceiver.c -L../../ -lDieWithError.o -I./ \
  && ./BroadcastReceiver 5050
