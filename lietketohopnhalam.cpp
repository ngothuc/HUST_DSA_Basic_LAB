#include<stdio.h>
int k,n;
int a[100];
void solution()
{
	for (int i=1; i<=k; i++) printf("%2d ", a[i]);
	printf("\n");
}
int check(int v, int i)
{
	if (v>a[i-1] && v<=n-k+i) return 1;
}
void Try(int i)
{
	a[0]=0;
	for (int v=a[i-1]+1; v<=n-k+i; v++)
	{
		if(check(v,i)) a[i]=v;
		if(i==k) solution();
		else Try(i+1);
	}
}
int main()
{
	k=6;
	n=10;
	Try(1);
}
