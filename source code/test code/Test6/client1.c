#include<stdio.h> 
#include<sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <netinet/in.h> 
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  
#include <netdb.h>

char buffer[100];


     
     int p=317,q=113,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
     
    char msg[100];
     
    int prime(long int);
     
    void ce();
     
    long int cd(long int);
     
    void encrypt();
     
    void decrypt();
     
    void rsaAfterReceive() {
     
    
     
    	//printf("\nENTER MESSAGE\n");
     
    	fflush(stdin);
     
    	strcpy(msg, buffer); 
     
    	for (i=0;msg[i]!='\0';i++)
     
    	m[i]=msg[i];
     
    	n=p*q;
     
    	t=(p-1)*(q-1);
     
    	ce();
     
    	//printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
     
    	//for (i=0;i<j-1;i++)
     
    	//printf("\n%d\t%d",e[i],d[i]);
     
    	encrypt();
     
    	decrypt();
     
    	
     
    }
    void rsaBeforeSend()
    {
    
    
    }
    int floorSqrt(int x) 
{ 
    // Base cases 
    if (x == 0 || x == 1) 
    return x; 
  
    // Staring from 1, try all numbers until 
    // i*i is greater than or equal to x. 
    int i = 1, result = 1; 
    while (result <= x) 
    { 
      i++; 
      result = i * i; 
    } 
    return i - 1; 
}
     
    int prime(long int pr) {
     
    	int i;
     
    	j=floorSqrt(pr);
     
    	for (i=2;i<=j;i++) {
     
    		if(pr%i==0)
     
    		    return 0;
     
    	}
     
    	return 1;
     
    }
     
    void ce() {
     
    	int k;
     
    	k=0;
     
    	for (i=2;i<t;i++) {
     
    		if(t%i==0)
     
    		    continue;
     
    		flag=prime(i);
     
    		if(flag==1&&i!=p&&i!=q) {
     
    			e[k]=i;
     
    			flag=cd(e[k]);
     
    			if(flag>0) {
     
    				d[k]=flag;
     
    				k++;
     
    			}
     
    			if(k==99)
     
    			        break;
     
    		}
     
    	}
     
    }
     
    long int cd(long int x) {
     
    	long int k=1;
     
    	while(1) {
     
    		k=k+t;
     
    		if(k%x==0)
     
    		    return(k/x);
     
    	}
     
    }
     
    void encrypt() {
     
    	long int pt,ct,key=e[0],k,len;
     
    	i=0;
     
    	len=strlen(msg);
     
    	while(i!=len) {
     
    		pt=m[i];
     
    		pt=pt-96;
     
    		k=1;
     
    		for (j=0;j<key;j++) {
     
    			k=k*pt;
     
    			k=k%n;
     
    		}
     
    		temp[i]=k;
     
    		ct=k+96;
     
    		en[i]=ct;
     
    		i++;
     
    	}
     
    	en[i]=-1;
     
    	printf("\nReceived Message:\n");
     
    	for (i=0;en[i]!=-1;i++)
     
    	printf("%c",en[i]);
     
    }
     
    void decrypt() {
    	
     
    	long int pt,ct,key=d[0],k;
    	
     
    	i=0;
     
    	while(en[i]!=-1) {
     
    		ct=temp[i];
     
    		k=1;
     
    		for (j=0;j<key;j++) {
     
    			k=k*ct;
     
    			k=k%n;
     
    		}
     
    		pt=k+96;
     
    		m[i]=pt;
     
    		i++;
     
    	}
     
    	m[i]=-1;
     
    	printf("\nDECRYPTED MESSAGE:\n");
     
    	for (i=0;m[i]!=-1;i++)
     
    	printf("%c",m[i]);
     
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
     printf("\n*** You are in Client side ***\n");
     printf("Intructions:\n");
     printf("[1.Type 'exit' to terminate\n2.First Client Send Message]\n");
     
    
    while(1)
    {
    	 bzero(buffer,100);
    	 printf("Client (type): " );
    	 fgets(buffer,100,stdin);
    	 
    	 //Compress call
    	rsaBeforeSend();
    	
    	 valwrite = write( sockfd , buffer, strlen(buffer));
    	 if(valwrite<0)
  	   {
     		error("[+]Error on writing..\n"); 
     	   }
     	   bzero(buffer,100);
   	 valread = read(sockfd , buffer, 100); 
   	 //printf("%s",buffer);
   	 rsaAfterReceive();
   	
   	/* if(strcmp(buffer,"exit") == 0)
   	 {
   	 	printf("Server terninated\n");
   	 	break;
   	 }
   	 */
   	 //printf("Server: %s",buffer );
   	 if(strncmp("exit",buffer,4)==0)
    	 break;
    	 bzero(buffer,1024);
   	 
   	 
    	
    }
    close(sockfd);
    close(newsockfd);
    return 0; 
    
}
	 			
