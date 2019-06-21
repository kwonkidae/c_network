
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>

#define ECHOMAX 255

void DieWithError(char *errorMessage);
void UseIdleTime();
void SIGIOHandler(int signalType);

int sock;

int main(int argc, char *argv[]) {
  return 0;
}

void UseIdleTime() {
  printf(".\n");
  sleep(3);
}

void SIGIOHandler(int signalType) {
  struct sockaddr_in echoClntAddr;
  unsigned int clntLen;
  int recvMsgSize;
  char echoBuffer[ECHOMAX];

  do {
    clntLen = sizeof(echoClntAddr);

    if ((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0,
      (struct sockaddr *)&echoClntAddr, &clntLen)) < 0) {
        if (errno != EWOULDBLOCK)
          DieWithError("recvfrom() failed");
    } else {
      printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

      if (sendto(sock, echoBuffer, recvMsgSize , 0, (struct sockaddr *)
        &echoClntAddr, sizeof(echoClntAddr)) != recvMsgSize)
        DieWithError("sendto() failed");
    }
  } while (recvMsgSize >= 0);
}
