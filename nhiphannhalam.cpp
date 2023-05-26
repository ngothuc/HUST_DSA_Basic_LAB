#include<stdio.h>
int n,songhiem=0; // do dai xau nhi phan
int a[100];
void solution()
{
	for(int i=1; i<=n; i++) printf("%d ",a[i]);
	printf("\n");
}
int check(int v, int k)
{
	if(v==0||v==1) return 1;
	else return 0;
}
void Try(int k)
{
		for (int v=0; v<=1; v++)
			if (check(v,k))
			{
				a[k]=v;
				if(k==n) {solution(); songhiem=songhiem+1;}
				else Try(k+1);
			}		
}
int main()
{
	printf("n="); scanf("%d",&n);
	Try(1);	
	printf("So nghiem =%d",songhiem);
}
