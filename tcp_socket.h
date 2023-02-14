
#ifndef FILE_TCP_SOCKET_H
#define FILE_TCP_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "DEBUG.h"

extern int create_tcp_server_socket(const char *ser_ip,unsigned short ser_port);
extern int create_tcp_client_socket(const char *ser_ip,unsigned short ser_port);
extern int wait_for_connect(int sfd,struct sockaddr_in *cli_addr);
extern void show_tcp_network_address(struct sockaddr_in *sockaddr);
extern ssize_t tcp_send_pack(int sockfd,const void *buf,size_t len);
extern ssize_t tcp_recv_pack(int sockfd,void *buf,size_t len);

#endif //FILE_TCP_SOCKET_H
