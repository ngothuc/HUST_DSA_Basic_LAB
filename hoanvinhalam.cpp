#include<stdio.h>
int n;
int a[100];
void solution()
{
	for (int i=1; i<=n; i++) printf ("%d ", a[i]);
	printf("\n");
}
int check(int v, int k)
{
	if (v==1 && a[k-1]==1) return 0;
	return 1;
}
void Try(int k)
{
	for (int v=0; v<=1; v++)
		if(check(v,k))
		{
			a[k]=v;
			if(k==n) solution();
			else Try(k+1);
		}
}
int main()
{	
	a[0]=0;
	n=5;
	Try(1);
	return 0;
}
