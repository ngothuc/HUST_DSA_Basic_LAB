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
	if(k>1)
	{	
		if(v==0) return 1;
		if(v==1 && a[k-1]==1) return 0;
		if(v==1 && a[k-1]==0) return 1;
	}	
	if(k=1) return 1;
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
