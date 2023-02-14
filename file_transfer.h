
#ifndef FILE_FILE_TRANSFER_H
#define FILE_FILE_TRANSFER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "tcp_socket.h"
#include "DEBUG.h"

#define FILENAME_SZ 64

typedef struct file_protocol{
    size_t filesize;
    char filename[FILENAME_SZ];
}file_protocol_t;

//防止tcp粘包用先发送头部信息,在接收数据
extern int recv_protocol_head(int cfd,file_protocol_t *pHead);
extern int recv_fileData(int cfd,char *filename,size_t targetSize);
extern int client_upload_file(int cfd);
extern int send_protocol_head(const char *filename,int sockfd);
extern int upload_file(const char *filename,int sockfd);

#endif //FILE_FILE_TRANSFER_H
