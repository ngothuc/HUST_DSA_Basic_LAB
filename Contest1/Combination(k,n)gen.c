#include<stdio.h>
int n,k;
int a[16];
void Solution()
{
	for(int i=1; i<=k; i++)
		printf("%d ",a[i]);
	printf("\n");
}
int Check(int v, int k)
{
	if(k==1) return 1;
	if(v<=a[k-1]) return 0;
	return 1;
}
void Try(int m)
{
	for(int v=1; v<=n; v++)
	{
		if(Check(v,m))
		{
			a[m]=v;
			if(m==k) Solution();
			else Try(m+1);
		}
	}
}
int main()
{
	scanf("%d %d",&k,&n);
	Try(1);
}
