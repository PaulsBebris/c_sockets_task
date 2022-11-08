#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
  int socket_id;

  socket_id = socket(AF_INET,SOCK_STREAM,0);
  if(socket_id == -1){
    printf("Error creating socket");
  }
  printf("Socket created\n");

 












  close(socket_id);
  printf("Socket closed\n);
  return 0;

}


