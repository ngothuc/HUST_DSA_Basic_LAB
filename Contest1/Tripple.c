#include<stdio.h>
#include<stdlib.h>
#define N 5001
int n,k;
int a[N],b[N];
void Input()
{
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
}
void Merge(int x[], int L, int mid, int R)
{
	int i=L,j=mid+1;
	for(int m=L; m<=R; m++)
	{
		if(i>mid)
		{
			b[m]=x[j]; j++;
		}else{
			if(j>R)
			{
				b[m]=x[i]; i++;
			}else{
				if(x[i]>x[j])
				{
					b[m]=x[j]; j++;
				}else{
					b[m]=x[i]; i++;
				}
			}
		}
	}
	for(int m=L; m<=R; m++)
		x[m]=b[m];
}
void MergeSort(int x[], int L, int R)
{
	if(L>=R) return;
	int mid=(L+R)/2;
	MergeSort(x,L,mid);
	MergeSort(x,mid+1,R);
	Merge(x,L,mid,R);
}
int q=0;
int counti=1,countj=1;
int C2n(int m)
{
	return m*(m-1)/2;
}
int cnt;
int Try(int m)
{
	int ans=0;
	int sum=k-a[m];
	int i=m+1; int j=n;
	while(i<j)
	{
		if(a[i]+a[j]<sum) i++;
		else if(a[i]+a[j]>sum) j--;
		else{
			cnt=0; int index=j;
			while(a[index]==a[j])
			{
				cnt++; index--;
				if(index==i) break;
			}
			ans+=cnt; cnt=0;
			i++;
		}
	}
	return ans;
}
int main()
{
	Input();
	MergeSort(a,1,n);
	for(int m=1; m<=n-2; m++)
	{
		if(a[m]+a[m+1]+a[m+2]>k) break;
		q=q+Try(m);
	}
	printf("%d",q);
	return 0;
}
