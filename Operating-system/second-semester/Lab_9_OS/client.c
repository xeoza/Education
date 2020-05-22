#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 256

char msg[MAXBUF];

int request(int sockfd, struct sockaddr_un serv_addr, int saddrlen){

    int msglen = strlen(msg);
    if (sendto(sockfd, msg, msglen, 0, (struct sockaddr*)&serv_addr, saddrlen) != msglen) {
        printf("Ошибка передачи сообщения\n");
        exit(1);
    }
    return 0;
}

int main() {
    struct sockaddr_un serv_addr, clnt_addr;
    int sockfd;
    int saddrlen, caddrlen, msglen;

    //Инициализируем sockaddr_un  для сервера
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "./echo.serv");
    saddrlen = sizeof(serv_addr);

    //Создаем сокет
    if ((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        printf("Невозможно создать сокет\n");
        exit(1);
    }

    //Инициализируем структуру sockaddr_un для клиента
    // memset(&clnt_addr, 0, sizeof(clnt_addr));
    // clnt_addr.sun_family = AF_UNIX;
    // strcpy(clnt_addr.sun_path, "/tmp/clnt.XXXX");
    // mktemp(clnt_addr.sun_path);
    // caddrlen = sizeof(clnt_addr);


    // if (bind(sockfd, (struct sockaddr*)&clnt_addr, caddrlen) < 0) {
    //     printf("Ошибка связывания сокета\n");
    //     exit(1);
    // }

    printf("Client with pid: %d\n", getpid());
    while (1) {
        printf(">> ");
        scanf("%s", &msg);
        request(sockfd, serv_addr, saddrlen);
        memset(&msg, 0, sizeof(msg));
    }

    close(sockfd);
    unlink(clnt_addr.sun_path);

    return 0;
}