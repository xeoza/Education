#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <fstream>

std::string get_html_from_file() {
    const std::string filename = "helloworld.html";
    std::ifstream html_file;
    html_file.open(filename);

    std::string html_string = "";
    if (html_file.is_open()) {
        std::string line;
        while (std::getline(html_file, line)) {
            html_string += line + '\n';
        }
        html_file.close();
    }

    return html_string;
}

std::string get_response() {
    std::string response =  "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html; charset=us-ascii\r\n\r\n";
    std::string html = get_html_from_file();
    response += html;
    return response;
}

int main() {
    int one = 1, client_fd; 
    struct sockaddr_in svr_addr, cli_addr;
    socklen_t sin_len = sizeof(cli_addr);

    const int port = 8080;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error! Failed to create socket\n");
        exit(1); 
    }

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(int));

    svr_addr.sin_family = AF_INET;
    svr_addr.sin_addr.s_addr = INADDR_ANY;
    svr_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *) &svr_addr, sizeof(svr_addr)) == -1) {
        close(sock);
        perror("Error! Faild to bind socket!\n");
        exit(1);
    }

    if ((listen(sock, 5)) != 0) { 
        perror("Error! Failed to listen!\n"); 
        exit(1); 
    } 

    std::string response = get_response();

    for(;;) {
        client_fd = accept(sock, (struct sockaddr *) &cli_addr, &sin_len);
        printf("Got connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        if (client_fd == -1) {
            perror("Can't accept");
            continue;
        }

        write(client_fd, response.c_str(), response.size() - 1); /*-1:'\0'*/
        close(client_fd);
    }

    return 0;
}
