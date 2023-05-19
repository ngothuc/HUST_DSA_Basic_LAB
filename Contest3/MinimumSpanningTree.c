#include<stdio.h>
#define N 100001
int p[N],r[N];
typedef struct Edge{
	int u,v,w;
}edge;
int n,m;
edge e[N];
void Input()
{
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1; i<=n; i++)
	{
	    p[i]=i;
	    r[i]=1;
	}
}
int FindSet(int x)
{
	if(x!=p[x]) p[x]=FindSet(p[x]);
	return p[x];
}
void Unify(int r1, int r2)
{
	if(r[r1]>r[r2]) p[r2]=r1;
	else{
		p[r1]=r2;
		if(r[r1]==r[r2]) r[r2]=r[r1]+1;
	}
}
edge E[N];
void Merge(edge x[], int L, int mid, int R)
{
	int i=L,j=mid+1;
	for(int k=L; k<=R; k++)
	{
		if(i>mid)
		{
			E[k]=x[j]; j++;
		}else if(j>R)
		{
			E[k]=x[i]; i++;
		}else{
			if(x[i].w<x[j].w)
			{
				E[k]=x[i]; i++;
			}else{
				E[k]=x[j]; j++;
			}
		}
	}
	for(int k=L; k<=R; k++)
		x[k]=E[k];
}
void MergeSort(edge x[], int L, int R)
{
	if(L>=R) return;
	int mid=(L+R)/2;
	MergeSort(x,L,mid);
	MergeSort(x,mid+1,R);
	Merge(x,L,mid,R);
}
long long int Kruskal()
{
	MergeSort(e,1,m);
	int ET=0;
	long long int W=0;
	for(int i=1; i<=m; i++)
	{
		int u,v;
		u=e[i].u; v=e[i].v;
		int r1,r2;
		r1=FindSet(u); r2=FindSet(v);
		if(r1!=r2)
		{
			ET++;
			W=W+e[i].w;
			Unify(r1,r2);
		}
		if(ET==n-1) break;
	}
	return W;
}
int main()
{
	Input();
	printf("%lld",Kruskal());
	return 0;
}
