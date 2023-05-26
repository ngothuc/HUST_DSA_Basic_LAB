#include<stdio.h>
int main()
{
	int m,n,k;
	printf("m=");
	scanf("%d",&m);
	printf("n=");
	scanf("%d",&n);
	if (n>m)
	{
		printf("Khong thuc hien duoc");
	} else
	{	
		int a[n];
		for (int i=1; i<=n; i++)
		{
			a[i]=i;
			printf("%d ",a[i]);
		}
		printf("\n");
		while( 1 )
		{
			if(a[n] < m)
			{
				a[n]=a[n]+1;
				for (int i=1; i<=n; i++)
				{
					printf("%d ",a[i]);
				}
				printf("\n");
			} else
			{
				for (int e=n; e>=1; e--)
				{
					while(a[e]==m-(n-e))
					{
						k=e-1;
						e=e-1;
					}
				}
				a[k]=a[k]+1;
				for (k; k<=n; k++)
				{
					a[k+1]=a[k]+1;
				}
				for (int i=1; i<=n; i++)
				{
					printf("%d ", a[i]);
				}
				printf("\n");
			}
			if ( a[1] >= m-n+1)
			{
				break;
			}
	}
	}
	
}
