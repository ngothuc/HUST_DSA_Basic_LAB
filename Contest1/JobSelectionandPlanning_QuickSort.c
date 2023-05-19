#include<stdio.h>
#define N 100001
typedef struct Job
{
	int d,p;
}Job;
Job a[N];
int mark[N]={0};
int sum=0,day=0;
int n;
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&a[i].d,&a[i].p);
	}
}
int Partion(int low,int high)
{
		
	int pivet=a[high].p;
	int left=low;
	int right=high-1;
	while(1)
	{
		while(left<=right && a[left].p>pivet) left++;
		while(right>=left && a[right].p<pivet) right--;
		if(left>=right) break;
		Job tmp=a[left]; a[left]=a[right]; a[right]=tmp;
		left++; right--;
	}
	Job tmp=a[left]; a[left]=a[high]; a[high]=tmp;
	return left;
	
}
void quickSort(int low, int high)
{
	if(low<high)
	{
		int index=Partion(low,high);
		quickSort(low,index-1);
		quickSort(index+1,high);
	}
}
int main()
{
	Input();
	quickSort(1,n);
	for(int i=1;i<=n;i++){
		int j=a[i].d;
		while(mark[j]!=0 && j>1){
			j--;
		}
		if(j>0 && mark[j]==0){
			sum=sum+a[i].p;
			mark[j]=1;
		}
	}
	printf("%d",sum);
	return 0;
}
