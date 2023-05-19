#include<stdio.h>
int n;
int a[16];
void Solution()
{
	for(int i=1; i<=n; i++)
		printf("%d",a[i]);
	printf("\n");
}
int Check(int v, int k)
{
	if(k==1) return 1;
	if(v==1 && a[k-1]==1) return 0;
	return 1;
}
void Try(int k)
{
	int v;
	for(v=0; v<=1; v++)
	{
		if(Check(v,k))
		{
			 a[k]=v;
			if(k==n) Solution();
			else Try(k+1);
		}
	}
}
int main()
{
	scanf("%d",&n);
	Try(1);
}
