#include<stdio.h>
#define N 100001
typedef struct Segment
{
	int x,y;
}Segment;
Segment a[N];
int n;
int ans=0;
void Input()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d %d",&a[i].x,&a[i].y);
}
int Partion(int low, int high)
{
	int pivot=a[high].y;
	int left=low; int right=high-1;
	while(1)
	{
		while(left<=right && a[left].y<pivot) left++;
		while(right>=left && a[right].y>pivot) right--;
		if(left>=right) break;
		Segment tmp=a[left]; a[left]=a[right]; a[right]=tmp;
		left++;
		right--;
	}
	Segment tmp=a[left]; a[left]=a[high]; a[high]=tmp;
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
void Greedy()
{
	int last=-1;
	for(int i=1; i<=n; i++)
		if(a[i].x>last)
		{
			last=a[i].y;
			ans++;
		}
}
int main()
{
	Input();
	quickSort(1,n);
	Greedy();
	printf("%d",ans);
	return 0;
}
