#include <stdio.h>

#include <arpa/inet.h>//inet_addr() sockaddr_in

#include <string.h>//bzero()

#include <sys/socket.h>//socket

#include <unistd.h>

#include <stdlib.h>//exit()

 

#define BUFFER_SIZE 1024

 

int main() {

    char listen_addr_str[] = "0.0.0.0";

    size_t listen_addr = inet_addr(listen_addr_str);

    int port = 8080;

    int server_socket, client_socket;

    struct sockaddr_in server_addr, client_addr;

    socklen_t addr_size;

    char buffer[BUFFER_SIZE];//��������С

 

    int str_length;

 

    server_socket = socket(PF_INET, SOCK_STREAM, 0);//�����׽���

 

    bzero(&server_addr, sizeof(server_addr));//��ʼ��

    server_addr.sin_family = INADDR_ANY;

    server_addr.sin_port = htons(port);

    server_addr.sin_addr.s_addr = listen_addr;

 

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {

        printf("��ʧ��\n");

        exit(1);

    }

    if (listen(server_socket, 5) == -1) {

        printf("����ʧ��\n");

        exit(1);

    }

 

    printf("����tcp�������ɹ�\n");

    addr_size = sizeof(client_addr);

    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);

    printf("%d ���ӳɹ�\n", client_socket);

    char msg[] = "��ϲ�����ӳɹ�";

    write(client_socket, msg, sizeof(msg));

 

    while (1) {

        str_length = read(client_socket, buffer, BUFFER_SIZE);

        if (str_length == 0)    //��ȡ������Ϲر��׽���

        {

            close(client_socket);

            printf("�����Ѿ��ر�: %d \n", client_socket);

            break;

        } else {

            printf("�ͻ��˷�������:%s",buffer);

            write(client_socket, buffer, str_length);//��������

        }

    }

 

    return 0;

}
