#include<stdio.h> 
#include<sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  
#include <netdb.h>
int ar[5]={0};
int i;
void printarr()
{
	for(i=0;i<5;i++)
	{
		printf("%d",ar[i]);
	}

}
void takeinput()
{
	for(i=0;i<5;i++)
	{
		scanf("%d",&ar[i]);
	}

}
//Function for error
void error(const char *msg)
{
		perror(msg);  //interprates the error num and o/p the error disciption
		exit(1); //if any error then terminate the program
		
		

}

int main(int argc, char* argv[]) //using comand line argument
{//argc is num of agrument
 //1. file name
 //2. port num
 //argv contains original value of parameter
 	if(argc<2)
	 {
 		fprintf(stderr,"Port num not provided\n");
 		exit(1);
 		
	 }
	 int sockfd, newsockfd,port_num,valread,valwrite;  //socket file discriptor, new socket file discriptor,
	 char buffer[1024];
	 struct sockaddr_in serv_addr; 
	 socklen_t clilen; 
	 struct hostent *server;
	 
	 //creating socket
	 
	 sockfd =socket(AF_INET, SOCK_STREAM, 0);
	 if(sockfd<0)
	 {
	 	 perror("[+]Socket failed...");
	 	  return -1;
	 }
	 
	 server=gethostbyname(argv[1]);
	 bzero((char *) &serv_addr, sizeof(serv_addr));
	 port_num=atoi(argv[1]);
	 serv_addr.sin_family = AF_INET;  
    	 serv_addr.sin_port = htons( port_num ); 
    
    	 if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)  
   	 { 
      	  printf("\nInvalid address/ Address not supported \n"); 
      	  return -1; 
         } 
    
    
   	 if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    	{ 
     	   printf("\nConnection Failed \n"); 
      	  return -1; 
    	} 
  
  
  //Code for write messages
  
    printf("##### Welcome to CryptCom #####\n");
     printf("\n*** You are in server side ***\n");
     printf(" Type 'exit' to terminate\n");
    
    while(1)
    {
    	 bzero(buffer,1024);
    	 printf("Client (type): " );
    	 //fgets(buffer,1024,stdin);
    	 //printf("%s",buffer);
    	 takeinput();
    	 valwrite = write( sockfd , ar, 5);
    	 if(valwrite<0)
  	   {
     		error("[+]Error on writing..\n"); 
     	   }
     	   bzero(buffer,1024);
     	   
   	 valread = read(sockfd , ar, 5);
   	 printarr();  
   	
   	/* if(strcmp(buffer,"exit") == 0)
   	 {
   	 	printf("Server terninated\n");
   	 	break;
   	 }
   	 */
   	 printf("Server: %s",buffer );
   	 if(strncmp("exit",buffer,4)==0)
    	 break;
    	 bzero(buffer,1024);
   	 
   	 
    	
    }
    close(sockfd);
    close(newsockfd);
    return 0; 
    
}
	 			
