#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char string[100000];
	char a,b;
	scanf("%s %c %c",string,&a,&b);
	for(int i=0; i<strlen(string); i++)
		if(string[i]==a) string[i]=b;
	printf("%s",string);
	return 0;
}
