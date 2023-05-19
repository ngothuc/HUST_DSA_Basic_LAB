#include<stdio.h>
#include<limits.h>
int n,k,N;
int per[50]; //khack i co tren xe hay khong
int mark[50]; //da di qia diem i hay chua
int prep[50]; //diem da toi truoc khi toi diem i
int a[50][50];
int num;//so khach hien tai tren xe
int min,ans,pos;//pos: vi tri hien tai
int d;//quang duong
void Input()
{
	min=ans=INT_MAX; pos=0; num=0; d=0;
	scanf("%d %d",&n,&k);
	N=2*n;
	for(int i=0; i<=N; i++)
	{
		for(int j=0; j<=N; j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]<min && i!=j) min=a[i][j];
		}
	}
	for(int i=1; i<=N; i++)
		mark[i]=0;
	for(int i=1; i<=n; i++)
		per[i]=0;
}
int Check(int v)
{
	if(mark[v]==1) return 0;
	if(v<=n)
	{
		if(num==k) return 0;
		return 1;
	}else{
		if(per[v-n]==1) return 1;
		return 0;
	}
}
void Try(int m)
{
	int v;
	for(v=1; v<=N; v++)
	{
		if(Check(v))
		{
			mark[v]=1; prep[v]=pos; pos=v; d=d+a[prep[pos]][pos];
			if(v<=n)
			{
				num++;
				per[v]=1;
			}else{
				num--;
				per[v-n]=0;
			}			
			if(d+(N-m+1)*min>ans)
			{
				mark[v]=0; d=d-a[prep[pos]][pos]; pos=prep[pos];
				if(v<=n)
				{
					num--;
					per[v]=0;
				}else{
					num++;
					per[v-n]=1;
				}
				continue;
			}
			if(m==N)
			{
				if(d+a[pos][0]<ans) ans=d+a[pos][0];
			}else Try(m+1);
			mark[v]=0; d=d-a[prep[pos]][pos]; pos=prep[pos];
			if(v<=n)
			{
				num--;
				per[v]=0;
			}else{
				num++;
				per[v-n]=1;
			}
		}
	}
}
int main()
{
	Input();
	Try(1);
	printf("%d",ans);
	return 0;
}
