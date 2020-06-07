#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <iostream>
#include <string>
#include <fstream>

void save_to_file(std::string buffer) {
    std::cout << buffer << std::endl;
    // std::cout << buffer.size() << std::endl;
    const std::string filename = "response.txt";
    std::ofstream client_file(filename);
    if (client_file.is_open()) {
        client_file << buffer;
        client_file.close();
    }
    else std::cout << "Unable to open file\n";
}

int main(int argc, char const *argv[]) 
{
    const int port = 8080;
    const int buffer_length = 1024;
    int sock = 0; 
    struct sockaddr_in serv_addr; 

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        perror("Socket creation error\n"); 
        return -1; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(port); 

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)  
    { 
        perror("Invalid address/ Address not supported\n"); 
        return -1; 
    } 

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        perror("Connection Failed\n"); 
        return -1; 
    } 

    char buffer[buffer_length] = {0};
    read(sock, buffer, buffer_length); 
    
    save_to_file(std::string(buffer));

    return 0; 
} 