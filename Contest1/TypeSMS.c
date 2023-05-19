#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int Try(char a[])
{
	int sum=0;
	for(int i=0; i<strlen(a); i++)
	{
		if(a[i]==97||a[i]==100||a[i]==103||a[i]==106||a[i]==109||a[i]==112||a[i]==116||a[i]==119||a[i]==32) sum=sum+1;
		if(a[i]==98||a[i]==101||a[i]==104||a[i]==107||a[i]==110||a[i]==113||a[i]==117||a[i]==120) sum=sum+2;
		if(a[i]==99||a[i]==102||a[i]==105||a[i]==108||a[i]==111||a[i]==114||a[i]==118||a[i]==121) sum=sum+3;
		if(a[i]==115||a[i]==122) sum=sum+4;
	}
	return sum;
}
int main()
{
	int t;
	scanf("%d ",&t);
	int a[t+1];
	for(int i=1; i<=t; i++)
	{
		//fflush(stdin);
		char * s = (char *) malloc(10000001 * sizeof(char));		
		fgets(s,10000000,stdin);
		a[i]=Try(s);
		free(s);
	}
	printf("T = %d",t);
	for(int i=1; i<=t ; i++)
	{
		printf("\n%d",a[i]);		
	}
	return 0;
}
