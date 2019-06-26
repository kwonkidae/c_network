# !/bin/bash
cd $PWD/tcp/client
gcc -o TCPEchoClient TCPEchoClient.c -L../../ -lDieWithError.o \
  # && ./TCPEchoClient 127.0.0.1 "hello" 5050
for ((i=0;i<=10;i++))
do
  ./TCPEchoClient 127.0.0.1 "hello" 5050
done

for ((i=0;i<=10;i++))
do
  ./TCPEchoClient 127.0.0.1 "hello" 5051
done

