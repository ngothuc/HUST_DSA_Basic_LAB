#include<stdio.h>
#include<limits.h>
#define N 16
int n,min=INT_MAX;
int ans=INT_MAX;
int a[N][N];
int mark[N];
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]<min) min=a[i][j];
		}	
}
int d=0,pos=1;
int prep[N];
void Try(int k)
{
	for(int i=2; i<=n; i++)
	{
		if(mark[i]==0)
		{
			d=d+a[pos][i]; mark[i]=1; prep[i]=pos; pos=i;
			if(d+(n-k)*min>ans)
			{
				d=d-a[prep[pos]][pos]; mark[pos]=0; pos=prep[pos];
				continue;
			}
			if(k==n)
			{
				if(d+a[pos][1]<ans) ans=d+a[pos][1];
			}else Try(k+1);
			d=d-a[prep[pos]][pos]; mark[pos]=0; pos=prep[pos];
		}
	}
}
int main()
{
	Input();
	for(int i=1; i<=n; i++)
		mark[i]=0;
	Try(2);
	printf("%d",ans);
	return 0;
}
