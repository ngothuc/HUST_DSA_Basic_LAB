#include<stdio.h>
#define N 10001
int n;
int a[N];
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
}
int ans[N];
void Try(int k)
{
	if(k==1) ans[k]=1;
	int solve=1;
	for(int i=1; i<=k; i++)
	{
		if(ans[i]+1>solve && a[i]<a[k]) solve=ans[i]+1;
	}
	ans[k]=solve;
}
int Solve()
{
	int max=0;
	for(int i=1; i<=n; i++)
	{
		if(ans[i]>max) max=ans[i];
	}
	return max;
}
int main()
{
	Input();
	for(int i=1; i<=n; i++)
		Try(i);
	printf("%d",Solve());
	return 0;
}
