#include<stdio.h> //Standerd library
#include<sys/types.h>  // help to execute socket.h and netinet.h also contains alotof data types
#include <sys/socket.h>  //contains definations of structure needed in socket
#include <netinet/in.h> //contains const and struct of internet domain address
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  

struct abc
{
 int a;
 char p;	

};


void error(const char *msg)
{
	perror(msg);  //interprates the error num and o/p the error disciption
	exit(1); //if any error then terminate the program
}


int main(int argc, char* argv[])
 //using comand line argument
 {
 
 //argc is num of agrument
 //1. file name
 //2. port num
 //argv contains original value of parameter
 	struct abc obj;
 	
 	if(argc<2)
	 {
 		fprintf(stderr,"Port num not provided\n");
 		exit(1);
 		
	 }
	 int sockfd, newsockfd,port_num,valread,valwrite;  //socket file discriptor
	 char buffer[1024]; //1 MB buffer , first msg stored in buffer
	 struct sockaddr_in serv_addr, cli_addr;// gives internr address
	 socklen_t clilen; //32 bit data type
	 
	 //creating socket
	 
	 sockfd =socket(AF_INET, SOCK_STREAM, 0);
	 if(sockfd==0)
	 {
	 	 error("[+]Socket failed..");
	 	  
	 }
	 printf("[+]Socket Created...\n");
	//bzero((char *) &serv_addr, sizeof(serv_addr));
	 
	 port_num=atoi(argv[1]); //atoi converts string to int
	 serv_addr.sin_family = AF_INET; 
   	serv_addr.sin_addr.s_addr = INADDR_ANY; 
    	serv_addr.sin_port = htons( port_num ); 
    
    
    	//Binding code
    	
    	if (bind(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr))<0) 
    	{ 
        	perror("[+]Binding failed..\n"); 
        	exit(EXIT_FAILURE); 
    	}
    	printf("[+]Bind to the port %d",port_num);
    	printf("\n");
    	listen(sockfd, 2);
    	printf("[+]Start listening...\n");
    	 // 5 is max num of client can connect
    	clilen = sizeof(cli_addr);
    	newsockfd = accept(sockfd , (struct sockaddr *)&cli_addr , &clilen);
        if(newsockfd<0)
    	{
    		perror("[+]Error on accept\n"); 
    	        exit(EXIT_FAILURE); 
    	}
    
     printf("##### Welcome to CryptCom #####\n");
     printf("\n*** You are in server side ***\n");
     printf(" Type 'exit' to terminate\n");
    while(1)
    {
    	 //bzero(buffer,1024);
   	// valread = read( newsockfd ,struct abc *obj, 1); 
   	 valread = read( newsockfd , (struct abc *)&obj, 1); 
   	
   	 
   	 
   	 printf("\nClient: %d", (obj.a));
   	  
   	 printf("Server(type): " );
    	 bzero(buffer,1024);
    	 fgets(buffer,1024,stdin);
    	
     	 valwrite = write( newsockfd , buffer, strlen(buffer));
     
     if(valwrite<0)
     {
     	perror("[+]Error on writing..\n"); 
     }
     int i=strncmp("exit",buffer,4);
     if(i==0)
     break;
    
     
    }
    
    close(sockfd);
    close(newsockfd);
    return 0; 
    
    
 }
	 			
