#include<stdio.h>

#include<string.h>
struct abc
{
 int a;
 char p;	

};

int main()
{
	struct abc* obj;
	obj->a=5;
	obj->p='s';
	printf("%d",obj->a);

}
