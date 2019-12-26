#include<stdio.h> //Standerd library
#include<sys/types.h>  // help to execute socket.h and netinet.h also contains alotof data types
#include <sys/socket.h>  //contains definations of structure needed in socket
#include <netinet/in.h> //contains const and struct of internet domain address
#include <stdlib.h>  
#include <unistd.h>
#include <string.h>  
struct format
	{
		int sendTemp[100];
		char sendMsg[100];
		
		
	};
	struct format send1;
	struct format receive;
     int p=317,q=113,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i;
     char encmsg[100];
     
    char msg[100];
     
    int prime(long int);
     
    void ce();
     
    long int cd(long int);
     
    void encrypt();
     
    void decrypt();
    void intToChar()
    {
    	bzero(encmsg,100);
    	for(int i=0;en[i]!=-1;i++)
    	{
    		encmsg[i]=en[i];
    	}
    	
    
    }
    
    void charToInt()
    {
    	printf("Encrypted: %s",receive.sendMsg);
    	for(int i=0;receive.sendMsg[i]!='\0';i++)
    	{
    		en[i]=receive.sendMsg[i];
    		printf("%c",receive.sendTemp[i]);
    	}
    	
    }
    void findTemp()
    {
    	for(int i=0;encmsg[i]!='\0';i++)
    	{
    			temp[i]=en[i]-96;
    	}
    	printf("\nTemp:\n");
    	for(int i=0;encmsg[i]!='\0';i++)
    	{
    			printf("%d",temp[i]);
    	}
    
    }
    void takeInput()
    {
    	printf("\nENTER MESSAGE\n");
     
    	fflush(stdin);
     
    	scanf("%s",msg);
     
    	for (i=0;msg[i]!='\0';i++)
     
    	m[i]=msg[i];	
    
    }
    
    
     
    void rsaAfterRec() {
    
    
     
    
    	n=p*q;
     
    	t=(p-1)*(q-1);
     
    	ce();
     
    	//printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
     
    	//for (i=0;i<j-1;i++)
     
    	//printf("\n%d\t%d",e[i],d[i]);
     
    	//encrypt();
    	//findTemp();
     	
    	decrypt();
    	
    	//intToChar();
    	
     
     	
    	
     
    }
    
    void beforeSend()
    {
    	
    	printf("\nENTER MESSAGE\n");
     
    	fflush(stdin);
    	bzero(msg,100);
     
    	scanf("%s",msg);
     
    	for (i=0;msg[i]!='\0';i++)
     
    	m[i]=msg[i];
     
    	n=p*q;
     
    	t=(p-1)*(q-1);
     
    	ce();
     
    	//printf("\nPOSSIBLE VALUES OF e AND d ARE\n");
     
    	//for (i=0;i<j-1;i++)
     
    	//printf("\n%d\t%d",e[i],d[i]);
     
    	encrypt();
     
    	//decrypt();
    	intToChar();
    	//charToInt();
     
    
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
     
    		ct=k;
     
    		en[i]=ct;
     
    		i++;
     
    	}
     
    	en[i]=-1;
     
    	printf("\nTHE ENCRYPTED MESSAGE IS\n");
     
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
    	printf("\nTHE DECRYPTED MESSAGE IS\n");
     
    	for (i=0;m[i]!=-1;i++)
     
    	printf("%c",m[i]);
     
     
    }
     

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
    	 bzero(encmsg,100);
   	 valread = read( newsockfd , (struct format *)&receive, 100); 
   	 //Convert msg to Char
   	 charToInt();
        // rsaAfterRec();
   	 //findTemp();
   	 //charToInt();
   	 printf("Server(type): " );
    	 bzero(encmsg,100);
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
	 			
