#include<stdio.h>
#include<stdlib.h>
typedef struct Linked_List
{
	int value;
	struct Linked_List * next;
}LL;
typedef LL * node;
node head_a=NULL;
node head_b=NULL;
node CreateNode(int a)
{
	node temp = (node) malloc (sizeof(LL));
	temp->value=a;
	temp->next=NULL;
	return temp;
}
void AddFirst(node *head, int a)
{
	node temp=CreateNode(a);
	if(*head==NULL) *head=temp;
	else{
		temp->next=*head;
		*head=temp;
	}
}
void AddLast(node *head, int a)
{
	node temp=CreateNode(a);
	if(*head==NULL) *head=temp;
	else{
		node p=*head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
void Remove(node *head, int a)
{
	if(*head==NULL) return;
	while((*head)->value == a && (*head) != NULL)
	{
		node del=*head;
		(*head) = (*head)->next;
		free(del);
	}
	if(*head==NULL) return;
	node p=*head;
	while(p->next!=NULL)
	{
		if(p->next->value==a)
		{
			node del=p->next;
			p->next=p->next->next;
			free(del);
		}else p=p->next;
	}
}
void Print(node head)
{
	if(head==NULL) return;
	for(node p=head; p!=NULL; p=p->next)
		printf("%d ",p->value);
}
void Free(node head)
{
	if(head==NULL) return;
	while(head!=NULL)
	{
		node del=head;
		head=head->next;
		free(del);
	}
}
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int value;
		scanf("%d",&value);
		AddLast(&head_a,value);
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		int value;
		scanf("%d",&value);
		AddLast(&head_b,value);
	}
	for(node p=head_b; p!=NULL; p=p->next)
	{
		int del=p->value;
		Remove(&head_a,del);
	}
	Print(head_a);
	
}
