#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
  // create socket
  int fd;
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if(fd == -1){
    puts("Error creating socket");
    exit(EXIT_FAILURE);
  }
  printf("File descriptor: %d\n",fd);
  puts("1. Socket created ...");

  // connect to socket server
  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr("172.217.21.174");
  server.sin_family = AF_INET;
  server.sin_port = htons(80);

  if(connect(fd, (struct sockaddr *) &server, sizeof(server)) < 0){
    puts("Error connecting to server");
    exit(EXIT_FAILURE);
  }
  puts("2. Connected to server");
  // send data
  char buf[] = "GET / HTTP/1.1\r\n\r\n";
  if(send(fd,&buf,2000,0) == -1){
    puts("Error on sending data request");
    exit(EXIT_FAILURE);
  }
  puts("3. Data sent\n");
  // receive data
  char data[5000];
  if( recv(fd,data,sizeof(data),0) == -1 ) {
    puts("4. Error on receiving data\n");
    exit(EXIT_FAILURE);
  }
  puts("Data received \n");
  puts(data);




  close(fd);
  return 0;
}
