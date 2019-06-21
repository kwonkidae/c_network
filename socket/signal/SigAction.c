#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void DieWithError(char *errorMessgae);
void InterruptSignalHandler(int signalType);

int main(int argc, char *argv[]) {
  struct sigaction handler;

  handler.sa_handler = InterruptSignalHandler;

  if (sigfillset(&handler.sa_mask) < 0)
    DieWithError("sigfillset() failed");

  handler.sa_flags = 0;

  if (sigaction(SIGINT, &handler, 0) < 0)
    DieWithError("sigaction() failed");

  for(;;)
    pause();

  exit(0);
}

void InterruptSignalHandler(int signalType) {
  printf("Interrupt Received. Exiting Program.\n");
  sleep(3);
}
