    #include<stdio.h>
     

     
    #include<stdlib.h>
     
    #include<math.h>
     
    #include<string.h>
     
     int p=317,q=113,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i,check[100];
     char encmsg[100];
    
    char msg[100];
     
    int prime(long int);
     
    void ce();
     
    long int cd(long int);
     
    void encrypt();
     
    void decrypt();
    void intToChar()
    {
    	for(int i=0;en[i]!=-1;i++)
    	{
    		encmsg[i]=en[i];
    	}
    	printf("From inside...\n");
    	printf("%s",encmsg);
    
    }
    
    void charToInt()
    {
    	for(int i=0;encmsg[i]!='\0';i++)
    	{
    		en[i]=encmsg[i];
    	}
    	
    }
     
    int main() {
     
    
     
    	
    	
     
    	printf("\nENTER MESSAGE\n");
     
    	fflush(stdin);
     
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
     
    	decrypt();
    	intToChar();
    	charToInt();
     
     	
    	
     
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
    	
    	printf("d[0]:%d",d[0]);
     
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
     
    		i++;//temp[i]=en[i]-96;
     
    	}
     
    	en[i]=-1;
     
    	printf("\nTHE ENCRYPTED MESSAGE IS\n");
     
    	for (i=0;en[i]!=-1;i++)
     
    	printf("%d",en[i]);
    	
    	  
    	 
     
    }
     
    void decrypt() {
    
     int s=0;
    	  
    	  printf("\nTemp\n");
    	for(s;s<100;s++)
    	{
    		printf(" %d",temp[s]);
    	
    	}
    	 printf("\nTemp\n");
    	for(s=0;s<100;s++)
    	{
    		printf(" %d",en[s]);
    	
    	}
    printf("from dec:\n");
    	for(s;s<100;s++)
    	{
    		//printf(" %d",m[s]);
    		printf("%c",m[s]);
    	
    	}
    	
     
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
     
    		check[i]=pt;
     
    		i++;
     
    	}
     
    	check[i]=-1;
     
    	printf("\nTHE DECRYPTED MESSAGE IS\n");
     
    	for (i=0;check[i]!=-1;i++)
     
    	printf("%c",check[i]);
    	
     
    }
     
