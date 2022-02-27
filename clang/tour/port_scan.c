#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h> // addrinfo
 // close
 // https://linux.die.net/man/2/clos
#include <unistd.h>
#include <arpa/inet.h>

void port_scan(char *tIP, char *First_Port, char *Last_Port) {
	printf("IP: %s, Start: %s, End: %s\n", tIP, First_Port, Last_Port);

  struct addrinfo hints, *res, *tmp;
  struct sockaddr_in *sa;
	char host[256];
	char                 abuf[INET_ADDRSTRLEN];
	const char             *addr;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	int ret = getaddrinfo(tIP, NULL, &hints, &res);
	if(ret != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
		exit(EXIT_FAILURE);
	}
	int port_start = atoi(First_Port);
	int port_end = atoi(Last_Port);
	for (int port = port_start; port <= port_end; port++) {
		printf("---\nPort: %d\n", port);
		for (tmp = res; tmp != NULL; tmp = tmp->ai_next) {
			// getnameinfo(tmp->ai_addr, tmp->ai_addrlen, host, sizeof(host), NULL, 0, NI_NUMERICHOST);
			// puts(host);

			int sockfd = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);
			if (sockfd < 0) {
				printf("[create] Port %d is NOT open.[%d]\n", port, sockfd);
				continue;
			}
			// int status = connect(sockfd, tmp->ai_addr, tmp->ai_addrlen);
			// int status = connect(sockfd, tmp, tmp->ai_addrlen);
			// printf("addrinfo %s %d\n", tmp->ai_addr, tmp->ai_port);
			// sa.sin_family = AF_INET;
			// sa.sin_port = htons(port);
			// sa.sin_addr.s_addr = tmp->ai_addr;
			sa = (struct sockaddr_in*)tmp->ai_addr;
			addr = inet_ntop(AF_INET, &sa->sin_addr, abuf, INET_ADDRSTRLEN);
      printf("address %s", addr?addr:"unknown");
			sa->sin_port = htons(port);
      printf(" port %d\n", ntohs(sa->sin_port));
			int status = connect(sockfd, (struct sockaddr*)sa, sizeof(*sa));
			if (status < 0) {
				printf("[connect] Port %d is NOT open.[%d]\n", port, status);
				close(sockfd);
				continue;
			}
			printf("Port %d is open.\n", port);
			close(sockfd);
		}
	}
	freeaddrinfo(res);
	// exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
	if (argc < 4) {
		printf("Enter IP address and port range\n");
		printf("Usage: %s IP First_Port Last_Port\n", argv[0]);
		exit(1);
	}
	char tIP[16] = {0};
	char First_Port[6] = {0};
	char Last_Port[6] = {0};

	strcpy(tIP, argv[1]);
	strcpy(First_Port, argv[2]);
	strcpy(Last_Port, argv[3]);
	port_scan(tIP, First_Port, Last_Port);
	return 0;
}
