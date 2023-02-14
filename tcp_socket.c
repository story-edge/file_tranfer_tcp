
#include "tcp_socket.h"

#define LISTEN_SZ 10

int create_tcp_server_socket(const char *ser_ip,unsigned short ser_port)
{
    int sfd,ret;
    struct sockaddr_in server_addr;
    socklen_t socklen = sizeof(server_addr);

    //创建socket
    sfd = socket(AF_INET,SOCK_STREAM,0);
    if (sfd < 0)
    {
        DEBUG_INFO("[ERROR]: %s", strerror(sfd));
        return -1;
    }

    //填充网络字节序大端模式
    memset(&server_addr,0,sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ser_port);
    server_addr.sin_addr.s_addr = inet_addr(ser_ip);

    //绑定服务器sfd
    ret = bind(sfd,(struct sockaddr *)&server_addr,socklen);
    if (ret < 0)
    {
        DEBUG_INFO("[ERROR]: %s", strerror(sfd));
        return -1;
    }

    //监听
    ret = listen(sfd,LISTEN_SZ);
    if (ret < 0)
    {
        DEBUG_INFO("[ERROR]: %s", strerror(sfd));
        return -1;
    }

    DEBUG_INFO("[INFO] Connect %s succeed.\n",ser_ip);

    return sfd;
}


int create_tcp_client_socket(const char *ser_ip,unsigned short ser_port)
{
    int sfd,ret;
    struct sockaddr_in server_addr;
    socklen_t socklen = sizeof(struct sockaddr_in);

    sfd = socket(AF_INET,SOCK_STREAM,0);
    if (sfd < 0)
    {
        DEBUG_INFO("[ERROR]: %s", strerror(sfd));
        return -1;
    }

    memset(&server_addr,0,sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ser_port);
    server_addr.sin_addr.s_addr = inet_addr(ser_ip);

    //发出连接请求
    ret = connect(sfd,(struct sockaddr *)&server_addr,socklen);
    if (ret < 0)
    {
        DEBUG_INFO("[ERROR]: %s", strerror(sfd));
        return -1;
    }


    DEBUG_INFO("[INFO] Connect %s succeed.\n",ser_ip);

    return sfd;
}


int wait_for_connect(int sfd,struct sockaddr_in *cli_addr)
{
    int cfd;
    socklen_t socklen = sizeof(struct sockaddr_in);

    //服务端accept连接请求
    cfd = accept(sfd,(struct sockaddr *)cli_addr,&socklen);
    if (cfd < 0)
    {
        DEBUG_INFO("[ERROR]: %s", strerror(sfd));
        return -1;
    }

    return cfd;
}

void show_tcp_network_address(struct sockaddr_in *sockaddr)
{
    printf("ip:%s\n", inet_ntoa(sockaddr->sin_addr));
    printf("port:%d\n", ntohs(sockaddr->sin_port));
}

ssize_t tcp_send_pack(int sockfd,const void *buf,size_t len)
{
    //如果想交换IP/host的用sendto,接收用recvform
    return send(sockfd,buf,len,0);
}

ssize_t tcp_recv_pack(int sockfd,void *buf,size_t len)
{
    return recv(sockfd,buf,len,0);
}