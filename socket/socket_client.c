#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<ncurses.h>

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	system("sudo apt-get install libncurses5-dev libncursesw5-dev");
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[256];
	if (argc < 3) {
		printf("Usage %s hostname port\n", argv[0]);
		exit(0);
	}
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("Error OpenSock\n");
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		printf("Error, no such host\n");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Connect failed\n");
	while (1)
	{
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		n = write(sockfd, buffer, strlen(buffer));
		if (n < 0)
			error("Error write\n");
		bzero(buffer, 255);
		n = read(sockfd, buffer, 255);
		if (n < 0)
			error("Error read\n");
		printf("Server: %s", buffer);

		int i = strncmp("Buy", buffer, 3);
		if (i == 0)
			break;
	}
	close(sockfd);
	return 0;
}
