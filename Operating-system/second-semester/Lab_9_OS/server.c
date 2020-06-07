#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXBUF 256

char buf[MAXBUF];
int main(){
    struct sockaddr_un serv_addr, clnt_addr;
    int sockfd;
    int saddrlen, caddrlen, max_caddrlen, n;

    //Создание сокета
    //семейство адресов - AF_UNIX, AF_LOCAL	Локальное соединение  
    //тип сокета - SOCK_DGRAM  Поддерживает дейтаграммы (ненадежные сообщения с ограниченной длиной без установки соединения)
    // протокол
    if ((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) {
        printf("Невозможно создать сокет\n");
        exit(1);
    }

    //Инициализация sockaddr_un
    /*
    sockaddr-является приведение типов сокетных адресов определённого домена к «общему» 
    типу, что позволяет избежать предупреждений компилятора о несовпадении типов в вызовах API сокетов 
    */
    unlink("echo_serv");
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, "./echo.serv");
    saddrlen = sizeof(serv_addr);

    //Привязка сокета к локальному адресу
    /*
    дескриптор сокета
    указатель на структуру struct sockaddr
    длина этой структуры
     */
    if (bind(sockfd, (struct sockaddr*)&serv_addr, saddrlen) < 0) {
        printf("Ошибка связывания сокета с адресом\n");
        exit(1);
    }

    max_caddrlen = sizeof(clnt_addr);
    while (1) {

        //Прием сообщения
        caddrlen = max_caddrlen;
        n = recvfrom(sockfd, buf, MAXBUF, 0, (struct sockaddr*)&clnt_addr, &caddrlen);
        if (n < 0) {
            printf("Ошибка приема\n");
            exit(1);
        }
        //char extra[32];
        //strcpy(extra, clnt_addr.sun_path);
        printf("+ client: %s\n", buf);
        memset(&buf, 0, sizeof(buf));
    
        
    }
}
