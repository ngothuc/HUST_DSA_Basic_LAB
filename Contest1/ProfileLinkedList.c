#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct profile
{
	char name[100];
	int age;
	struct profile * next;
}profile;
typedef profile * node;
node head=NULL;
node Makenode(char name[], int age)
{
	node temp = (node) malloc (sizeof(profile));
	strcpy(temp->name,name);
	temp->age=age;
	temp->next=NULL;
	return temp;
}
void AddFirst(char name[], int age)
{
	node temp = Makenode(name,age);	
	if(head==NULL)
	{
		head=temp;
	}else{
		temp->next=head;
		head=temp;
	}
}
void AddLast(char name[], int age)
{
	node temp = Makenode(name,age);
	if(head==NULL)
	{
		head=temp;
	}else{
		node p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
void Remove(char name[])
{
	if(head==NULL) return;
	while(strcmp(head->name,name)==0 && head!=NULL)
	{
		head=head->next;
		if(head==NULL) return;
	}
	node p=head;
	while(p->next!=NULL)
	{
		if(strcmp(p->next->name,name)==0)
		{
			node del=p->next;
			p->next=p->next->next;
			free(del);
		}else p=p->next;	
	}
}
void Print()
{
	if(head==NULL) return;
	for(node p=head; p!=NULL; p=p->next)
		printf("%s ",p->name);
}
void Free()
{
	if(head==NULL) return;
	while(head!=NULL)
	{
		node p=head;
		head=head->next;
		free(p);		
	}
}
int main()
{
	while(1)
	{
		char name[100];
		int age;
		char command[100];
		scanf("%s",command);
		if(strcmp(command,"***")==0) break;
		else if(strcmp(command,"$addlast")==0)
		{
			scanf("%s",name);
			scanf("%d",&age);
			AddLast(name,age);
		} else
		if(strcmp(command,"$addfirst")==0)
		{
			scanf("%s",name);
			scanf("%d",&age);
			AddFirst(name,age);
		} else
		if(strcmp(command,"$remove")==0)
		{			
			scanf("%s",name);
			Remove(name);
		}
	}
	Print();
	Free();
}
