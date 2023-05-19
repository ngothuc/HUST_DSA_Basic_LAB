#include<stdio.h>
#include<stdlib.h>
#define N 100001
int n,m;
int d[N];
typedef struct LL{
	int id;
	struct LL* next;
}node;
node* A[N];
node* head; node* tail;
node* MakeNode(int v)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->id=v; tmp->next=NULL;
	return tmp;
}
node* Add(int v, node* h)
{
	if(h==NULL) return MakeNode(v);
	node* tmp=MakeNode(v);
	tmp->next=h;
	return tmp;
}
void Input()
{
	scanf("%d %d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		A[u]=Add(v,A[u]); A[v]=Add(u,A[v]);
	}
}
void InitQ()
{
	head=tail=NULL;
}
int Empty()
{
	return head==NULL && tail==NULL;
}
void Push(int v)
{
	if(Empty())
	{
		head=MakeNode(v); tail=head;
		return;
	}
	tail->next=MakeNode(v); tail=tail->next;
}
int Pop()
{
	if(Empty()) return NULL;
	int v=head->id;
	head=head->next;
	if(head==NULL) tail=NULL;
	return v;
}
int BFS(int u)
{
	d[u]=0; InitQ(); Push(u);
	while(!Empty())
	{
		int v=Pop();
		for(node* q=A[v]; q!=NULL; q=q->next)
		{
			int x=q->id;
			if(d[x]==-1)
			{
				d[x]=d[v]+1;
				Push(x);
			}else{
				int check=d[x]+d[v];
				if(check%2==0) return 0;
			}
		}
	}
	return 1;
}
void Solve()
{
	int ans=1;
	for(int i=1; i<=n; i++)
		d[i]=-1;
	for(int i=1; i<=n; i++)
	{
		if(d[i]==-1)
		{
			int check=BFS(i);
			if(check==0)
			{
				ans=0;
				break;
			}
		}
	}
	printf("%d",ans);
}
int main()
{
	Input();
	Solve();
	return 0;
}
