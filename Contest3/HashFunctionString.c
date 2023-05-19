#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define M 100001
int n,m;
char s[M];
int mod[M];
int HashChar(char x, int i)
{
		return x*mod[i] % m;
}
int Hash(char s[])
{
	int ans=0;
	int j=strlen(s)-1;
	for(int i=0; i<strlen(s); i++)
		ans=(ans+HashChar(s[i],j-i))%m;
	return ans;
}
void Start()
{
	mod[0]=1%m;
	for(int i=1; i<M; i++)
		mod[i]=mod[i-1]*256%m;
}
int main()
{
	scanf("%d %d",&n,&m);
	Start();
	for(int i=1; i<=n; i++)
	{
		scanf("%s",s);
		printf("%d\n",Hash(s));
	}
	return 0;
}
