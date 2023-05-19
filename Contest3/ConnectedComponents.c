#include<stdio.h>
#include<stdlib.h>
#define M 100001
#define N 100001
int m,n;
typedef struct Node{
	int key;
	struct Node* next;
}node;
node* MakeNode(int v)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->key=v; tmp->next=NULL;
	return tmp;
}
node* AddFirst(int v, node* h)
{
	node* p=MakeNode(v);
	p->next=h;
	return p;
}
node* head[N];
int visited[N];
void Input()
{
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		head[i]=NULL;
		visited[i]=0;
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d %d",&x,&y);
		head[x]=AddFirst(y,head[x]);
		head[y]=AddFirst(x,head[y]);
	}	
}
void BFS(int v)
{
	visited[v]=1;
	for(node* p=head[v]; p!=NULL; p=p->next)
	{
		int l=p->key;
		if(visited[l]==0) BFS(l);
	}
}
void Try()
{
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		if(visited[i]==0)
		{
			BFS(i);
			ans++;
		}
	}
	printf("%d",ans);
}
int main()
{
	Input();
	Try();
	return 0;
}
