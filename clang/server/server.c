// https://www.geeksforgeeks.org/socket-programming-cc/
// https://stackoverflow.com/questions/58599070/socket-programming-setsockopt-protocol-not-available
// https://stackoverflow.com/questions/50277645/closing-a-file-descriptor-or-a-socket-in-c
// https://trungams.github.io/2020-08-23-a-simple-http-server-from-scratch/
// http://www.cs.cmu.edu/afs/cs/academic/class/15213-s00/www/class28/tiny.c
// https://dev-notes.eu/2018/06/http-server-in-c/
// https://gist.github.com/laobubu/d6d0e9beb934b60b2e552c2d03e1409e

#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[]) {
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char* msg = "From Server ...";

	if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("create socket failed.");
		exit(EXIT_FAILURE);
	}

	if (setsockopt(server_fd, SOL_SOCKET,
				// SO_REUSEADDR | SO_REUSEPORT,
				// for macOS
				SO_REUSEADDR,
				&opt, sizeof(opt))) {
		perror("setsockopt failed");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr*) &address,
				sizeof(address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if (listen(server_fd, 3) < 0) {
		perror("listen failed");
		exit(EXIT_FAILURE);
	}
	printf("Serving HTTP on port %d ...\n", PORT);
	while (1) {
		if((new_socket = accept(server_fd, (struct sockaddr*) &address,
						(socklen_t*) &addrlen)) < 0) {
			perror("accept failed");
			exit(EXIT_FAILURE);
		}
		valread = read(new_socket, buffer, 1024);
		printf("%s\n", buffer);
		char *page = "HTTP/1.1 200 OK\r\n\r\nSimple Server\r\n";
		send(new_socket, page, strlen(page), 0);
		printf("Send data from server...\n");
		// close socket
		close(new_socket);
		new_socket = -1;
	}
	return 0;
}
