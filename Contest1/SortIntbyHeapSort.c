#include<stdio.h>
#define N 1000001
int n;
int a[N];
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
}
void Swap(int * x, int * y)
{
	int tmp=*x; *x=*y; *y=tmp;
}
void Heapify(int x[], int i, int k)
{
	int L=2*i,R=2*i+1; int max=i;
	if(L<=k) if(x[L]>x[max]) max=L;  if(R<=k) if(x[R]>x[max]) max=R;
	if(max!=i)
	{
		Swap(x+i,x+max); Heapify(x,max,k);
	}else return;
}
void BuildHeap(int x[], int k)
{
	for(int i=k/2; i>=1; i--)
		Heapify(x,i,k);
}
void HeapSort(int x[], int k)
{
	BuildHeap(x,k);
	for(int i=k; i>=1; i--)
	{
		Heapify(x,1,i);
		Swap(x+1,x+i);
	}
}
void Output()
{
	for(int i=1; i<=n; i++)
		printf("%d ",a[i]);
}
int main()
{
	Input();
	HeapSort(a,n);
	Output();
	return 0;
}
