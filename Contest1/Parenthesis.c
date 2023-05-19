#include<stdio.h>
#include<stdlib.h>
typedef struct Parenthesis
{
	char c;
	struct Parenthesis * next;
}node;
node * MakeNode(char c)
{
	node * temp = malloc(sizeof(node));
	temp->c=c;
	temp->next=NULL;
	return temp;
}
node * first = NULL;
node* Push(char x, node *f)
{
	node * temp = MakeNode(x);
	temp->next=f;
	f=temp;
	return f;
}
char Pop(node ** f)
{
	char c=NULL;
	if(*f==NULL) return c;
	c=(*f)->c;
	node * del=*f;
	(*f)=(*f)->next;
	free(del);
	return c;
}
int Empty(node * f)
{
	if(f==NULL) return 1;
	return 0;
}
int Check(char x, char y)
{
	if(x=='('&&y==')') return 0;
	else if(x=='['&&y==']') return 0;
	else if(x=='{'&&y=='}') return 0;
	return 1;
}
void PrintList(node * f)
{
	while(f!=NULL)
	{
		printf("%c",f->c);
		f=f->next;
	}
}
int Try()
{
	while(1)
	{
		char c=getchar();
		if(c!='(' && c!=')' && c!='[' && c!=']' && c!='{' && c!='}') break;
		if(c=='('||c=='['||c=='{') first=Push(c,first);
		if(c==')'||c==']'||c=='}')
		{
			char d=Pop(&first);
			if(Check(d,c)) return 0;
		}
	}
	if(Empty(first)) return 1;
	return 0;
}
int main()
{
	printf("%d",Try());
	/*first=Push('(',first);
	first=Push('[',first);
	first=Push(']',first);
	first=Push('(',first);
	char c=Pop(&first);
	PrintList(first);*/
	return 0;
}
