#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

int main()
{
    int fd;
    //sockaddr_in специально предназначен для хранения адресов в формате Интернета
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    //семейство адресов AF_INET-указывает, что открываемый сокет должен быть сетевым
    //Тип сокета - SOCK_STREAM-требует, чтобы сокет был потоковым
    //0-протокол выбирается по умолчанию.
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        perror("socket");
        exit(1);
    }
    // операция превращает сокет в неблокирующий.
    fcntl(fd, F_SETFL, O_NONBLOCK);
    
    //htons() переписывает двухбайтовое значение порта так, чтобы порядок байтов соответствовал сетевому
    //В качестве семейства адресов указывается AF_INET, а в качестве самого адреса – специальную константу INADDR_ANY. 
    //Благодаря этой константе наша программа сервер зарегистрируется на всех адресах той машины, на которой она выполняется.
    //INADDR_ANY - любой IP адрес из доступных
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = INADDR_ANY;
    //Для явного связывания номера порта с сетевым адресом сокета
    if(bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }
    
    // переводит сервер в режим ожидания запроса на соединение
    // Второй параметр – максимальное число соединений, которые сервер может обрабатывать одновременно 
    listen(fd, 2);

    std::vector<int> clients;
    clients.clear();

    while(1)
    {
        // Заполняем множество сокетов
        fd_set readset;
        //Смотрите stdin (fd 0), чтобы увидеть, когда он имеет ввод.
        FD_ZERO(&readset); //очищает множество set
        FD_SET(fd, &readset);//добавляет дескриптор fd в множество set

        for(auto it = clients.begin(); it != clients.end(); it++)
            FD_SET(*it, &readset);

        // Задаём таймаут
        timeval timeout;
        timeout.tv_sec = 15;
        timeout.tv_usec = 0;

        // Ждём события в одном из сокетов

        int mx;
        if (!clients.empty()) {
            mx = std::max(fd, *max_element(clients.begin(), clients.end()));
        } else {
            mx = fd;
        }
        /*
        select() and pselect() позволяет программе контролировать несколько файловых дескрипторов, 
        ожидающих, пока один или несколько файловых дескрипторов не станут доступны (готовы)  
        для некоторого класса операций ввода / вывода  
        */
        int err = pselect(mx+1, &readset, NULL, NULL, &timeout, NULL);
        if (err < 0) {
            perror("select");
            exit(3);
        }

        // Определяем тип события и выполняем соответствующие действия
        //FD_SET и FD_ISSET – макросы, предназначенные для работы с набором дескрипторов fd_set.
        if(FD_ISSET(fd, &readset))
        {
            // Поступил новый запрос на соединение, используем accept
            // которая устанавливает соединение в ответ на запрос клиента и создает копию сокета для того,
            // чтобы исходный сокет мог продолжать прослушивание
            //Второй параметр функции accept() содержит сведения об адресе клиента, запросившего соединение,
            //а третий параметр указывает размер второго
            int sock = accept(fd, NULL, NULL);
            if(sock < 0)
            {
                perror("accept");
                exit(3);
            }
            //По умолчанию функция socket() создает блокирующий сокет. 
            //Чтобы сделать его неблокирующим, надо использовать функцию fcntl
            fcntl(sock, F_SETFL, O_NONBLOCK);

            clients.push_back(sock);
        }
        // мультиплексирование ср стат возникн соединения с нес клиентами будет время установ соед 
        // будет меньше чем если устан соед с клиентам в нек порядке
        for(int i = 0; i < clients.size(); ++i)
        {
            //проверяет, содержится ли дескриптор fd в множестве set
            if(FD_ISSET(clients[i], &readset))
            {
                // Поступили данные от клиента, читаем их
                bytes_read = recv(clients[i], buf, 1024, 0);

                if(bytes_read <= 0)
                {
                    // Соединение разорвано, удаляем сокет из множества
                    close(clients[i]);
                    clients.erase(clients.begin() + i);
                    continue;
                }

                // Отправляем данные обратно клиенту
                std::cout << "+client: " << buf << std::endl;
                send(clients[i], buf, bytes_read, 0);
            }
        }
    }

    return 0;
}

