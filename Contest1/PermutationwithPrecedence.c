#include<stdio.h>
#include<stdlib.h>
#define N 7
int n,K;
int a[N],b[N],c[N],mark[N];
void Input()
{
	scanf("%d",&n); scanf("%d",&K);
	for(int i=1; i<=K; i++)
		scanf("%d %d",a+i,b+i);
	for(int i=1; i<=n; i++)
		mark[i]=0;
}
int Check(int v, int k)
{
	if(mark[v]==1) return 0;
	int index=0;
	for(int i=1; i<=K; i++)
		if(v==b[i] && mark[a[i]]==0)
		{
			index=i;
			break;
		}
	if(index==0) return 1;
	return 0;
}
int ans=0;
void Solution()
{
	for(int i=1; i<=n; i++)
		printf("%d ",c[i]);
	printf("\n");
	ans++;
}
void Try(int k)
{
	int v;
	for(v=1; v<=n; v++)
		if(Check(v,k))
		{
			c[k]=v; mark[v]=1;
			if(k==n) Solution();
			else Try(k+1);
			mark[v]=0;
		}
}
int main()
{
	Input();
	Try(1);
	printf("%d",ans);
	return 0;
}
