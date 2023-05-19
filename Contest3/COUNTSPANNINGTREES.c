#include<stdio.h>
#include<stdlib.h>
#define N 100001
typedef struct Edge{
	int u,v;
}edge;
int n,m;
edge e[N];
int p[N],r[N];
void Input()
{
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&e[i].u,&e[i].v);
	}
}
void MakeSet()
{
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
void Untify(int r1, int r2)
{
	if(r[r1]>r[r2]) p[r2]=r1;
	else{
		p[r1]=r2;
		if(r[r1]==r[r2]) r[r2]=r[r1]+1;
	}
}
int ans=0;
int cnt=0;
void Try(int k, int last)
{	
	for(int i=last+1; i<=m; i++)
	{
		int u,v,r1,r2;
		u=e[i].u; v=e[i].v;
		r1=FindSet(u); r2=FindSet(v);
		if(r1!=r2)
		{
			cnt++; Untify(r1,r2);
			if(cnt==n-1) ans++;
			else Try(k+1,i);
			cnt--; p[r1]=r1; p[r2]=r2;
		}
	}
}
int Factorial(int n)
{
	if(n==1) return 1;
	return n*Factorial(n-1);
}
int main()
{
	Input();
	MakeSet();
	Try(1,0);
	printf("%d",ans);
	return 0;
}
