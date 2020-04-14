#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define MAXLINE 4098

int main(int argc, char **argv)

{

  int sockfd,n,i,startport,endport;

  struct sockaddr_in servaddr;

  startport = atoi(argv[2]);
  endport = atoi(argv[3]);
 
  if(startport<1 || endport>65535 || endport<startport) 
     {  
        printf("端口范围出错\n");  
        return 0;   
     }   
   srand((int)time(NULL)); //get time now
   printf("port start service!\n");
   for(i=startport;i<=endport;i++)
       {  
      if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
              {
         printf("socket error\n");
         return -1;
               }
  
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;

    servaddr.sin_port = htons(i);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) 
        {
      printf("inet_pton error\n");
         }

    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) 
         {

      printf("unopened port: %d\n", i);

      close(sockfd);

      continue;

             }

    else {

      printf("opend port: %d\n", i);

      close(sockfd);

      continue;
    }

  }

  exit(0);

}
