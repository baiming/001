/***************************************************************************
* Module Name   : server.c                                                   
* Identification:                                                  
* Date          : 2010.09.04                                          
*                                                                        
* Author        : Yu Lianqing                                           
*                                                                        
* Copyright (c)                          
* ALL RIGHTS RESERVED                                                
*                                                                         
* Revisions of %M% :                                                    
* #.##   Name         Date          Description                        
* ----   ------------ ------------- ----------------------------------- 
*                                                                         
* Description   : network server demo program in UDP mode.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT		20001
#define BUFFER_SIZE		256

char buffer[BUFFER_SIZE];

/* Following struct only for demo */
/*
truct sockaddr_in
{
	short int sin_family;          // Address family
	unsigned short int sin_port;   // Port number
	struct in_addr sin_addr;       // Internet address
	unsigned char sin_zero[8];     // Same size as struct sockaddr
};

struct in_addr
{
	unsigned long s_addr;
};
*/

//
//
int main(int argc, char *argv[])
{
	char c;
	int i,len;
	int server_sock;
	socklen_t client_len;
	struct sockaddr_in server,client;
	struct in_addr in;
	
	// 1. create socket - create an endpoint for communication
	// int socket(int domain, int type, int protocol);
	if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("create socket ok!\n");
	}
	
	// 2. bind - bind a name to a socket
	// int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = htons(INADDR_ANY);

	if(bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("bind addr ok!\n");
		printf("\n");
	}


	// communication with client
	while(1)
	{
		// wait for client request
		client_len = sizeof(client);
		len = recvfrom(server_sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client, &client_len);
		if (len < 0)
		{
			close(server_sock);
			fprintf(stderr, "%s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("recvfrom client ok!\n");
			in.s_addr = client.sin_addr.s_addr;
			printf("client ip  : %s\n", inet_ntoa(in));
			printf("client port: %d\n", ntohs(client.sin_port));
			printf("\n");
		}

		// Quit flag
		if(buffer[0] == '.') break;

		// lower to upper	
		for(i=0; i<len; i++)
		{
			c = buffer[i];
			buffer[i] = toupper(c);
		}
	
		// send back to client
		sendto(server_sock, buffer, len, 0, (struct sockaddr *)&client, client_len);
	}

	printf("Client close the socket\n");
	close(server_sock);

	exit(EXIT_SUCCESS);
}

