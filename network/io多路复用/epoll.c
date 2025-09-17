#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include<sys/select.h>
#include<sys/poll.h>
#include<sys/epoll.h>
#define PORT 8888

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket error");
        return -1;
    }
    
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind error");
        close(sockfd);
        return -1;
    }
    
    if(listen(sockfd, 10) < 0) {
        perror("listen error");
        close(sockfd);
        return -1;
    }

    int epfd=epoll_create(1);
    struct epoll_event ev;
    ev.events=EPOLLIN;
    ev.data.fd=sockfd;

    epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);
    struct epoll_event events[1024]={0};

    while(1){
        int nready=epoll_wait(epfd,events,1024,-1);
        int i=0;
        for(i=0;i<nready;i++){
            int connfd=events[i].data.fd;
            if(sockfd==connfd){
                struct sockaddr_in clientaddr;
                socklen_t len=sizeof(clientaddr);

                int clientfd=accept(sockfd,(struct sockaddr*)&clientaddr,&len);
                ev.events=EPOLLIN;
                ev.data.fd=clientfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,clientfd,&ev);
                printf("clientfd:%d\n",clientfd);
            }else if(events[i].events&EPOLLIN){
                char buf[128] = {0};
                int recv_len = recv(connfd, buf, 128, 0);
                if(recv_len <= 0) {
                    printf("disconnect\n");
                    epoll_ctl(epfd,EPOLL_CTL_DEL,connfd,NULL);
                    close(connfd);
                    continue;
                }
                send(connfd, buf, recv_len, 0); 
                printf("clientfd:%d  recv_len :%d buffer :%s\n",connfd,recv_len,buf);
            }
        }
    }
    
    return 0;
}