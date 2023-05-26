#include<stdio.h>
int main()
{
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);   
    int a[n+1];
    for (int i=1; i<=n; i++)
    {
    	a[i]=0;
	}
	
	while(1)
	{
		for (int k=1; k<=n; k++)
		{
			printf("%d",a[k]);
		}
		printf("\n");
		
		int i=n;
		while(a[i]==1)
		{
			i=i-1;
		}
		a[i]=1;
		for (int k=i+1; k<=n; k++)
		{
			a[k]=0;
		}
//		
		if (i==0)
		{
			break;
		}	
	}
}
