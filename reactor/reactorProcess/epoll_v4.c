

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <pthread.h>

#include <errno.h>
#include <sys/epoll.h>


int epfd = 0;

struct sockitem {
	int sockfd;
	int (*callback)(int fd, int events, void *arg);

};

//  ./epoll 8080

int recv_cb(int fd, int events, void *arg) {

	//int clientfd = events[i].data.fd;
	struct sockitem *si = (struct sockitem*)arg;
	struct epoll_event ev;

	char buffer[1024] = {0};
	int ret = recv(fd, buffer, 1024, 0);
	if (ret < 0) {

		if (errno == EAGAIN || errno == EWOULDBLOCK) { //
			return -1;
		} else {
			
		}

		

		ev.events = EPOLLIN;
		//ev.data.fd = fd;
		epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &ev);

		close(fd);

		free(si);
		

	} else if (ret == 0) { //

		// 
		printf("disconnect %d\n", fd);

		

		ev.events = EPOLLIN;
		//ev.data.fd = fd;
		epoll_ctl(epfd, EPOLL_CTL_DEL, fd, &ev);

		close(fd);

		free(si);
		
	} else {

		printf("Recv: %s, %d Bytes\n", buffer, ret);

	}

}


int accept_cb(int fd, int events, void *arg) {

	struct sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(struct sockaddr_in));
	socklen_t client_len = sizeof(client_addr);
	
	int clientfd = accept(fd, (struct sockaddr*)&client_addr, &client_len);
	if (clientfd <= 0) return -1;

	char str[INET_ADDRSTRLEN] = {0};
	printf("recv from %s at port %d\n", inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
		ntohs(client_addr.sin_port));

	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	//ev.data.fd = clientfd;

	struct sockitem *si = (struct sockitem*)malloc(sizeof(struct sockitem));
	si->sockfd = clientfd;
	si->callback = recv_cb;
	ev.data.ptr = si;
	
	epoll_ctl(epfd, EPOLL_CTL_ADD, clientfd, &ev);
	
	return clientfd;
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
		return -1;
	}

	int port = atoi(argv[1]);

	

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		return -1;
	}

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(struct sockaddr_in));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfd, (struct sockaddr*)&addr, sizeof(struct sockaddr_in)) < 0) {
		return -2;
	}

	if (listen(sockfd, 5) < 0) {
		return -3;
	}

	// epoll opera

	epfd = epoll_create(1);
	
	struct epoll_event ev, events[512] = {0};
	ev.events = EPOLLIN;
	//ev.data.fd = sockfd; //int idx = 2000;
	

	struct sockitem *si = (struct sockitem*)malloc(sizeof(struct sockitem));
	si->sockfd = sockfd;
	si->callback = accept_cb;
	ev.data.ptr = si;
	
	epoll_ctl(epfd, EPOLL_CTL_ADD, sockfd, &ev);

	

	//pthread_cond_waittime();
	
	while (1) {

		int nready = epoll_wait(epfd, events, 512, -1);
		if (nready < -1) {
			break;
		}

		int i = 0;
		for (i = 0;i < nready;i ++) {



			if (events[i].events & EPOLLIN) {
				//printf("sockitem\n");
				struct sockitem *si = (struct sockitem*)events[i].data.ptr;
				si->callback(si->sockfd, events[i].events, si);


			}

			if (events[i].events & EPOLLOUT) {

				

			}


		}

	}

}




