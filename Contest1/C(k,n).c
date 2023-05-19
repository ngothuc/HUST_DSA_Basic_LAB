#include<stdio.h>
#include<math.h>
int k,n;
int c[1000][1000];
int C(int k, int n)
{
	if(k == n || k == 0) return 1;
	if(c[k][n]<0) c[k][n]=C(k-1,n-1)+C(k,n-1);
	while(c[k][n]>(pow(10,9)+7)) c[k][n]=c[k][n]-pow(10,9)-7;
	return c[k][n];
}
int main()
{
	for(int i=1; i<1000; i++)
		for(int j=1; j<1000; j++)
			c[i][j]=-1;
	scanf("%d %d",&k,&n);
	printf("%d",C(k,n));
}
