#include<stdio.h>
#define N 10001
int a[N],b[N];
int S[N][N];
int n,m;
void Input()
{
	scanf("%d %d",&n, &m);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=m; i++)
		scanf("%d",&b[i]);	
}
void Solve()
{
	for(int i=0; i<=n; i++) S[i][0]=0;
	for(int i=0; i<=m; i++) S[0][i]=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if(a[i]==b[j]) S[i][j]=S[i-1][j-1]+1;
			else S[i][j]= S[i-1][j]>S[i][j-1] ? S[i-1][j] : S[i][j-1];
}
int main()
{
	Input();
	Solve();
	printf("%d",S[n][m]);
	return 0;
}
