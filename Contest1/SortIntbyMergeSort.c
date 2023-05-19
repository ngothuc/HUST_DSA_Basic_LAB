#include<stdio.h>
#define N 1000001
int a[N];
int b[N];
int n;
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
}
void Merge(int x[],int L, int mid, int R)
{
	int i=L,j=mid+1;
	for(int k=L; k<=R; k++)
	{
		if(i>mid)
		{
			b[k]=x[j]; j++;
		}else if(j>R)
			  {
			  	b[k]=x[i]; i++;
			  }else
			  {
			  	if(x[i]<x[j])
			  	{
			  		b[k]=x[i]; i++;
				}else{
					b[k]=x[j]; j++;
				}
			  }
	}
	for(int i=L; i<=R; i++)
		x[i]=b[i];
}
void MergeSort(int x[],int L,int R)
{
	if(L>=R) return;
	int mid=(L+R)/2;
	MergeSort(x,L,mid);
	MergeSort(x,mid+1,R);
	Merge(x,L,mid,R);
}
int main()
{
	Input();
	MergeSort(a,1,n);
	for(int i=1; i<=n; i++)
		printf("%d ",b[i]);
	return 0;
}
