#include<stdio.h>
int n;
int x[100];
void solution()
{
    for(int i=1; i<=n; i++) printf("(%d,%d) ",x[i],i);
    printf("\n");
}
int check(int v, int k)
{
	for(int i = 1; i <= k-1; i++)
	{
		if(v==x[i] || v-x[i]==i-k || v-x[i]==k-i) return 0;		
	} return 1;
}
/*{
for(int i = 1; i <= k-1; i++){
        if(x[i] == v) return 0;
        if(x[i] + i == v + k) return 0;
        if(x[i] - i == v - k) return 0;
    }
    return 1;
}*/
void Try(int k)
{
	for(int v=1; v<=n; v++)
	{
		if (check(v,k)){
		x[k]=v;
		if(k==n) solution();
		else Try(k+1);}
	}		
}
int main()
{
	n=4;
	Try(1);
}
