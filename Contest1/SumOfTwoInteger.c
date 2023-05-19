#include<stdio.h>
#include<string.h>
char a[30], b[30], c[30];
void Input()
{
	scanf("%s %s",a,b);
	//printf("%s %s",a,b);
}
int Max(int a, int b)
{
	if(a>b) return a;
	return b;
}
int m,n,i;
char r=0;
int main()
{
	Input();
	m = strlen(a); n = strlen(b);
	r=0; i=0;
	int max_len = Max(m,n);
	while(1)
	{
		if(m<0 && n<0) break;
		else{
			char x,y;
			if(m>=0) x=a[m]; else x=48;
			if(n>=0) y=b[n]; else y=48;
			c[i] = x + y + r - 96;
			if(c[i]>9) r = 1; else r = 0;
			if(r==1) c[i] = c[i] % 10;
			i++; m--; n--;
		}
	}
	if(r==1) printf("1");
	for(int i=max_len; i>0; i--)
		printf("%d",c[i]);
	return 0;
}
