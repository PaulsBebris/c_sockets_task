#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_ADDR (argv[1] > 0) ? argv[1] : "127.0.0.1"

int main (int argc, char *argv[]){
  printf("ARGV-1: %s\n", argv[1]);

  // create socket
  int fd = socket(AF_INET,SOCK_STREAM,0);
  if(fd == -1){
    puts("Error creating server socket");
    exit(EXIT_FAILURE);
  }
  puts("1. Socket for server created");
  // bind socket to host
  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr("10.10.10.5");
  server.sin_family = AF_INET;
  server.sin_port = htons(10080);
  if(bind(fd,(struct sockaddr *)&server,sizeof(server)) < 0){
    puts("2. --- Error in binding socket to address");
    exit(EXIT_FAILURE);
  }
  printf("3. Binding socket to address: %s\n", SERVER_ADDR);
  // start listening for requests
  listen(fd,3);
  printf("4. Listening address: %s and port: %d\n", SERVER_ADDR,10080);
  // accept incoming connection
  struct sockaddr_in client;
  int len = sizeof (struct sockaddr_in);
  int fd_in = accept(fd,(struct sockaddr*)&client,(socklen_t *)&len);
  if(fd_in == -1){
    puts("5. Error accepting incoming connection");
  }
  puts("6. Connection accepted");

  // receive request data
  char rcv_buf[2000];

  // create listening loop
//  int listen = 1;
//  while(listen){
//    if(rcv_buf[]){
//
//    }
//  }

  ssize_t rcv_status = recv(fd_in,&rcv_buf,2000,0);
  if(rcv_status == -1){
    puts("7. Error on receiving data");
  }
  printf("%s\n", rcv_buf);

  // send response data

  int stop = 1;
  puts("Enter 0 to stop server");
  while(stop != 0){
    int i = 0;
    i = getc(stdin);
    if( i == 48){
      stop = 0;
    }
  }

//  close(fd);
  return 0;
}


