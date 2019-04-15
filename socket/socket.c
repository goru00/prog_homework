#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main()
{
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	return 0;
}