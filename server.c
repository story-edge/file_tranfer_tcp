#include <unistd.h>
#include "tcp_socket.h"
#include <pthread.h>
#include "file_transfer.h"

//子线程接收client的file
void *do_pthreadTask(void *arg)
{

    size_t size;
    int cfd = *(int *)arg;

    size = client_upload_file(cfd);
    if (size >= 0)
    {
        printf("client upload file size : %ld\n",size);
    }

    close(cfd);
    pthread_exit(NULL);

}

int main(int argc,char *argv[])
{
    int sfd,cfd,ret;
    struct sockaddr_in client_addr;
    pthread_t tid;

    if (argc != 3)
    {
        fprintf(stderr,"Usage: %s ip port\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    sfd = create_tcp_server_socket(argv[1], atoi(argv[2]));
    if (sfd < 0)
        exit(EXIT_FAILURE);

    //循环接收文件
    for (;;) {
        bzero(&client_addr, sizeof(client_addr));

        cfd = wait_for_connect(sfd, &client_addr);
        if (cfd < 0)
            exit(EXIT_FAILURE);

        show_tcp_network_address(&client_addr);

        ret = pthread_create(&tid,NULL,do_pthreadTask,(void *)&cfd);
        if (ret < 0)
        {
            DEBUG_INFO("[ERROR] to pthread_create()");
            exit(EXIT_FAILURE);
        }

        //线程分离
        pthread_detach(tid);
    }


    close(sfd);

    return 0;
}