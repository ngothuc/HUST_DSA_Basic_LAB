#include<bits/stdc++.h>
int n;
int a[21];
void Solution()
{
	for(int i=1; i<=n; i++)
		printf("%d",a[i]);
	printf("\n");
}
void Try(int k)
{
	int v;
	for(v=0; v<=1; v++)
	{	
		a[k]=v;
		if(k==n) Solution();
		else Try(k+1);
	}
}
int main()
{
	scanf("%d",&n);
	Try(1);
}
