#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>

int hostname_to_ip(const char * const hostname, char *ip);

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Please provide a hostname to resolve");
    exit(1);
  }
  char *hostname = argv[1];
  char ip[100];

  hostname_to_ip(hostname, ip);
  printf("%s resolved to %s", hostname, ip);

  printf("\n");  
}

int hostname_to_ip(const char * const hostname, char * const ip)
{
  struct hostent *he;
  struct in_addr **addr_list;
  int i;

  if ((he = gethostbyname(hostname)) == NULL)
  {
    herror("gethostbyname");
    return 1;
  }

  addr_list = (struct in_addr **)he->h_addr_list;

  for (i = 0; addr_list[i] != NULL; i++)
  {
    strcpy(ip, inet_ntoa(*addr_list[i]));
    return 0;
  }
  return 1;
}
