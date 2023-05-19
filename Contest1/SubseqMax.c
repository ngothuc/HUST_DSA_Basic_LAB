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
int max[N];
int Subseq(int k)
{
	if(k==1) return max[1];
	if(max[k-1]<0)
	{
		max[k]=a[k];
	}else max[k]=a[k]+max[k-1];
	return max[k];
}
void Try()
{
	for(int i=1; i<=n; i++)
		max[i]=Subseq(i);
	int MAX=max[1];
	for(int i=2; i<=n; i++)
		if(max[i]>MAX) MAX=max[i];
	printf("%d",MAX);
}
int main()
{
	Input();
	max[1]=a[1];
	Try();
	return 0;
}
