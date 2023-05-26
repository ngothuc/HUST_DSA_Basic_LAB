#include<stdio.h>
int n;
int x[100];
int y[100];
int markx[100];
int marky[100];
void solution()
{
	for (int i=1; i<=n; i++)
	{
		printf("(x,y)=(%d,%d)",x[i],y[i]);
	}
}
int checkx(int v, int k)
{
	if (markx[v]==0) return 1;
	else return 0;
}
int checky(int v, int k)
{
	if (marky[v]==0) return 1;
	else return 0;
}
int checkxy(int x[], int y[])
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if(x[j]-x[i]==y[j]-y[i]&&i!=j) return 0;
			else return 1;
}
void Try(int k)
{
	for(int p=1;p<=n;p++)
		for(int q=1;q<=n;q++)
			{
				if(checkx(p,k)) if(checky(q,k))
				{
					x[k]=p; markx[p]=1;
					y[k]=q; marky[q]=1;
					if(k<n) Try(k+1); else
					{
						a[]=x[n]; b[]=y[n];					
						if(checkxy(a, b) solution();
					}
					markx[p]=0;
					marky[q]=0;
				}
			}
}
int main()
{
	printf("n="); scanf("%d",&n);
	for(int v=1; v<=n; v++)
	{
		markx[v]=0;
		marky[v]=0;
	}
	Try(1);
}

