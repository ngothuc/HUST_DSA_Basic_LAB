#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 200000
#define M 100000 // number of Hash
typedef struct BST{
	char key[60];
	struct BST* leftChild;
	struct BST* rightChild;
}node;
node* root[M];
void Init()
{
	for(int i=0; i<M; i++)
		root[i]=NULL;
}
node* MakeNode(char* s)
{
	node* temp=(node*)malloc(sizeof(node));
	strcpy(temp->key,s);
	temp->leftChild=NULL; temp->rightChild=NULL;
	return temp;
}
int Hash(char* s)
{
	int h=0;
	for(int i=0; i<strlen(s); i++)
	{
		h=h*256+s[i];
		h=h%M;
	}
	return h;
}
node* FindBST(char* s, node* r)
{
	if(r==NULL) return r;
	int c=strcmp(s,r->key);
	if(c==0) return r;
	else if(c<0) return FindBST(s,r->leftChild);
	else if(c>0) return FindBST(s,r->rightChild);
	return NULL;
}
int Find(char* s)
{
	int index=Hash(s);
	int ok=0;
	if(FindBST(s,root[index])!=NULL) ok=1;
	return ok;
}
node* InsertBST(char* s, node* r)
{
	if(r==NULL) return r=MakeNode(s);
	int c=strcmp(s,r->key);
	if(c<0) r->leftChild=InsertBST(s,r->leftChild);
	else if(c>0) r->rightChild=InsertBST(s,r->rightChild);
	return r;
}
int Insert(char* s)
{
	int index=Hash(s);
	int ok=Find(s);
	if(ok==1) return 0;
	else{
		root[index]=InsertBST(s,root[index]);
		return 1;
	}
}
int main()
{
	Init();
	char cmd[60],word[60];
	while(1)
	{
		scanf("%s",word);
		if(strcmp(word,"*")==0) break;
		else Insert(word);
	}
	while(1)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"***")==0) break;
		else if(strcmp(cmd,"$find")==0)
		{
			scanf("%s",word);
			printf("%d\n",Find(word));
		}else if(strcmp(cmd,"$insert")==0)
		{
			scanf("%s",word);
			printf("%d\n",Insert(word));			
		}
	}
	return 0;
}
