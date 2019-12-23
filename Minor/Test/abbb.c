#include<stdio.h>
#include<string.h>
char * string()
{
 	return "Hello";

}
int main()

{
	char *str;
	str=string();
	for(int i=0;str[i]!='\0';i++)	
	{
		printf("%c",*(str+i));
	}

}
