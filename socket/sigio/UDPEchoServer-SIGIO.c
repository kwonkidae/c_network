
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
  struct sockaddr_in echoServAddr;
  unsigned short echoServPort;
  struct sigaction handler;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <SERVER PORT>\n", argv[0]);
    exit(1);
  }

  echoServPort = atoi(argv[1]);

  if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    DieWithError("socket() failed");

  memset(&echoServAddr, 0 , sizeof(echoServAddr));
  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  echoServAddr.sin_port = htons(echoServPort);

  if (bind(sock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
    DieWithError("bind() failed");

  handler.sa_handler = SIGIOHandler;
  if (sigfillset(&handler.sa_mask) < 0)
    DieWithError("sigfillset() failed");

  handler.sa_flags = 0;

  if (sigaction(SIGIO, &handler, 0) < 0)
    DieWithError("sigaction() failed for SIGIO");

  printf("getpid(): %d\n", getpid());
  if (fcntl(sock, F_SETOWN, getpid()) < 0)
    DieWithError("Unable to set process owner to us");

  if (fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    DieWithError("Unable to put client sock into nonblocking/asyn mode");

  for (;;)
    UseIdleTime();

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
  printf("SIGIOHandler\n");
  do {
    clntLen = sizeof(echoClntAddr);

    if ((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0,
      (struct sockaddr *)&echoClntAddr, &clntLen)) < 0) {
        printf("<0");
        if (errno != EWOULDBLOCK)
          DieWithError("recvfrom() failed");
    } else {
      printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
      sleep(5);
      if (sendto(sock, echoBuffer, recvMsgSize , 0, (struct sockaddr *)
        &echoClntAddr, sizeof(echoClntAddr)) != recvMsgSize)
        DieWithError("sendto() failed");
    }
  } while (recvMsgSize >= 0);
}
