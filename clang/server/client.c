#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[]) {
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char *msg = "From Client";
	char buffer[1024] = {0};
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\ncreate socket error\n");
		return -1;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		printf("\nInvalid address / Address not supported\n");
		return -1;
	}
	if (connect(sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		printf("\nConnection failed\n");
		return -1;
	}
	send(sock, msg, strlen(msg), 0);
	printf("Sent message to server.\n");
	valread = read(sock, buffer, 1024);
	printf("Got: %s\n", buffer);
	return 0;
}
