
#include "file_transfer.h"
#define RECV_DATA_BUF 1024

/*
 * tcp协议传输数据应该防止底层的粘包问题
 */
int recv_protocol_head(int cfd,file_protocol_t *pHead)
{
    ssize_t rbytes;
    ssize_t total_received = 0;//记录接收到的数据大小
    char *buf = (char *)pHead;//按字节流接收

    for (;;)
    {
        //每一次buf和len都要根据total_received的大小进行定位下一次的起始偏移量
        rbytes = tcp_recv_pack(cfd,buf + total_received,sizeof(file_protocol_t) - total_received);
        if (rbytes < 0)
        {
            DEBUG_INFO("[ERROR] %s ", strerror(rbytes));
            return -1;
        } else if (rbytes == 0)//== 0 表示对方以关闭
        {
            printf("The client has shutdown!\n");
            break;
        } else if (rbytes > 0)
        {
            total_received += rbytes;//更新total_received
            if (total_received == sizeof(file_protocol_t))
                break;
        }
    }

    //接收与发送方的数据大小比较
    if (total_received != sizeof(file_protocol_t))
    {
        DEBUG_INFO("[ERROR] Fail to receive data_head!\n");
        return -1;
    }

    return 0;
}

/*
 * 接收数据后并写入本地文件
 */
int recv_fileData(int cfd,char *filename,size_t targetSize)
{
    int fd;
    ssize_t rbytes = 0, wbytes = 0, filesize = 0;
    char buf[RECV_DATA_BUF] = {0};

    fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC|0666);
    if (fd < 0)
    {
        DEBUG_INFO("[ERROR] Fail to open filename: %s!\n", strerror(fd));
        return -1;
    }

    for (;;)
    {
        rbytes = tcp_recv_pack(cfd,buf,sizeof(buf));
        if (rbytes < 0)
        {
            DEBUG_INFO("[ERROR] %s ", strerror(rbytes));
            return -1;
        } else if (rbytes == 0)
        {
            printf("The client has shutdown!\n");
            break;
        } else if (rbytes > 0)
        {
            wbytes = write(fd,buf,rbytes);
            if (wbytes != rbytes)
            {
                DEBUG_INFO("[ERROR] Fail to write data.\n");
                return -1;
            }

            filesize += wbytes;//更新写入的大小

            if (filesize == targetSize)//接收大小一致
                break;
        }
    }

    close(fd);
    return (int)filesize;//返回文件的大小
}

/*
 * 在自定义传输协议的基础上完成上传文件的接口
 */
int client_upload_file(int cfd)
{
    int ret;
    file_protocol_t head;
    char *filename;
    size_t filesize = 0,receivedSize = 0;

    ret = recv_protocol_head(cfd,&head);
    if (ret < 0)
        return -1;

    filename = head.filename;
    filesize = head.filesize;


    receivedSize = recv_fileData(cfd,filename,filesize);
    if (receivedSize < 0)
        return -1;

    printf("Recv %%%d\n",(int )(receivedSize *1.0 / filesize));
    return receivedSize;

}

int send_protocol_head(const char *filename,int sockfd)
{
    int fd,filesize;
    file_protocol_t head;
    ssize_t ret;

    fd = open(filename,O_RDONLY);
    if (fd < 0)
    {
        DEBUG_INFO("[ERROR] Fail to open filename: %s!\n", strerror(fd));
        return -1;
    }

    filesize = lseek(fd,0,SEEK_END);//通过lseek函数返回值来记录大小
    close(fd);

    head.filesize = filesize;
    //strncpy(head.filename,filename,sizeof(head.filename));
    strcpy(head.filename,filename);

    ret = tcp_send_pack(sockfd,&head,sizeof(head));
    if (ret != sizeof(file_protocol_t))//每次接收的都是与结构体大小一致
    {
        DEBUG_INFO("[ERROR] Fail to send protocol pack:%s.\n", strerror(ret));
        return -1;
    }

    return filesize;

}

int upload_file(const char *filename,int sockfd)
{
    int file_size;
    int fd;
    ssize_t rbytes = 0,sbytes = 0,uploadSize = 0;
    char buf[RECV_DATA_BUF] = {0};

    //发送协议头的信息
    file_size = send_protocol_head(filename,sockfd);
    if (file_size < 0)
    {
        DEBUG_INFO("[ERROR] Fail to send_protocol_head.\n");
        return -1;
    }

    //遍历文件数据发送给服务器
    fd = open(filename,O_RDONLY);
    if (fd < 0)
    {
        DEBUG_INFO("[ERROR] Failed to open fd:%s", strerror(fd));
        return -1;
    }

    for (;;)
    {
        rbytes = read(fd,buf,sizeof(buf));
        if (rbytes < 0)
        {
            DEBUG_INFO("[ERROR] Failed to read data:%s", strerror(rbytes));
            return -1;
        } else if (rbytes == 0)
        {
            break;
        }

        sbytes = tcp_send_pack(sockfd,buf,rbytes);
        if (sbytes < 0)
        {
            DEBUG_INFO("[ERROR] Failed to tcp_send_pack:%s", strerror(rbytes));
            return -1;
        }

        uploadSize += sbytes;

    }

    close(fd);

    return uploadSize;
}