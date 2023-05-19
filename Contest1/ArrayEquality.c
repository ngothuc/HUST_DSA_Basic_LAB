#include<stdio.h>
int Try(int n, int m)
{
	int a[n],b[m];
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<m; i++)
		scanf("%d",&b[i]);
	if(n!=m) return 0;
	for(int i=0; i<n; i++)
	{
		if(a[i]!=b[i])
		{
			break;
		}
		if(i==n-1) return 1;
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	int answer[t+1];
	for(int i=1; i<=t; i++)
	{		
		int n,m;
		scanf("%d %d",&n,&m);
		answer[i]=Try(n,m);
	}
	for(int i=1; i<=t; i++)
		printf("%d\n",answer[i]);
}
