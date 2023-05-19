#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000001
char fullname[N][256];
char name[N][256];
int n;
char* GetName(char* s)
{
	int index;
	for(int i=0; i<strlen(s); i++)
		if(s[i]==' ') index=i;
	char* Name=(char*)malloc(256*sizeof(char));
	strcpy(Name,s+index+1);
	return Name;
}
void Swap(char* s1, char* s2)
{
	char tmp[50];
	strcpy(tmp,s1); strcpy(s1,s2); strcpy(s2,tmp);
}
int main()
{
	freopen("aaa.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		fflush(stdin);
		gets(fullname[i]);
	}
	for(int i=1; i<=n; i++)
	{
		strcpy(name[i],GetName(fullname[i]));
	}
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; i++)
		{
			int c=strcmp(name[j],name[i]);
			if(c<0)
			{
				Swap(name[i],name[j]);
				Swap(fullname[i],fullname[j]);
			}
		}
	//char s1[50]="abcde"; char s2[50]="xyzte";
	//Swap(s1,s2);
	for(int i=1; i<=n; i++)
		printf("%s\n",fullname[i]);
	return 0;
}
