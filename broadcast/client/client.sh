#!/bin/bash
cd $PWD/broadcast/client
gcc -o BroadcastSender BroadcastSender.c -L../../ -lDieWithError.o -I./ \
  && ./BroadcastSender 127.0.0.1 5050 kkdosk
