#include<stdio.h>
#define N 1000001
int a[N];
int n;
int b[N];
int max=-9999;
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		b[i]=-9999;
	}
}
int S(int x)
{
	if(x==1)
	{
		b[x]=a[x];
		return b[x];
	}
	if(b[x]==-9999)
	{
		if(S(x-1)<0) b[x]=a[x];
		else b[x]=S(x-1)+a[x];
	}
	return b[x];
}
int Max(int a, int b)
{
	if(a>b) return a;
	return b;
}
int main()
{
	Input();
	for(int i=1; i<=n; i++)
	{
		S(i);
		max=Max(max,b[i]);
	}
	printf("%d",max);
	return 0;
}
