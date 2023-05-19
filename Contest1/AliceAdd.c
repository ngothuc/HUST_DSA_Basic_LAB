#include<stdio.h>
#include<string.h>
#include<math.h>
int Max(int a, int b)
{
	if(a>b) return a;
	else return b;
}
void Do(char a[], int length_max);
void Try(char a[], char b[])
{
	strrev(a);
	strrev(b);
	int length_max=Max(strlen(a),strlen(b));	
	if(strlen(a)<strlen(b)) Do(a,length_max);
	if(strlen(a)>strlen(b)) Do(b,length_max);
}
void Do(char a[], int length_max)
{
	for(int i=strlen(a); i<length_max; i++)
		a[i]=48;
	a[length_max]='\0';
}
int main()
{
	char a[30],b[30],c[30];
	scanf("%s %s",a,b);
	int length_a=strlen(a);
	int length_b=strlen(b);
	int length_max=Max(length_a,length_b);
	Try(a,b);
	for(int i=0; i<length_max; i++)
	{
		c[i]=a[i]+b[i]-96;
	}
	c[length_max]='\0';
	/*for(int i=0; i<length_max; i++)
		printf("%d",c[i]);*/
	if(c[length_max-1]>9)
	{
		c[length_max-1]=c[length_max-1]%10;
		c[length_max]=1;
		c[length_max+1]='\0';
		length_max++;
	}
	for(int i=1; i<length_max; i++)
	{
		if(c[i-1]>9) c[i]++;
	}
	for(int i=0; i<length_max; i++)
		c[i]=c[i]%10;
	//strrev(c);
	for(int i=length_max-1; i>=0; i--)
		printf("%d",c[i]);
}
