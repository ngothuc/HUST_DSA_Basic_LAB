#include<stdio.h>
int n,sum;
int a[8];
int ans=0;
char mark[10];
void Try(int k)
{
	int v;
	for(v=1; v<10; v++)
	{
		if(mark[v]==0)
		{
			a[k]=v; mark[v]=1;
			if(k==7)
			{
				sum =  1000*a[4] + 100*(a[1]-a[7]+a[5]) + 10*(a[2]-6+a[6]) +1*(a[3]-2+a[3]);
				if(sum==n) ans++;
			}else Try(k+1);
			mark[v]=0;
		}
		
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1; i<10; i++)
		mark[i]=0;
	Try(1);	
	printf("%d",ans);
	return 0;
}
