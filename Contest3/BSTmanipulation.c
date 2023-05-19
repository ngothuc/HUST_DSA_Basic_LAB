#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BST{
	int key;
	struct BST * leftChild;
	struct BST * rightChild;
}node;
node * root = NULL;
node * MakeNode(int k)
{
	node * temp = (node *)malloc(sizeof(node));
	temp->key=k; temp->leftChild=NULL; temp->rightChild=NULL;
	return temp;
}
node * Find(int k, node * r)
{
	if(r==NULL) return r;
	else if(r->key==k) return r;
	else if(k>r->key) return Find(k,r->rightChild);
	else return Find(k,r->leftChild);	
}
node * Insert(int k, node * r)
{
	if(r==NULL)
	{
		r=MakeNode(k);
		return r;
	}
	else{
		if(r->key==k) return r;
		else if(k>r->key) r->rightChild=Insert(k,r->rightChild);
		else r->leftChild=Insert(k,r->leftChild);
	}
	return r;
}
node * FindMin(node * r)
{
	if(r==NULL||r->leftChild==NULL) return r;
	else return FindMin(r->leftChild);
}
node * Remove(int k, node * r)
{
	if(Find(k,r)==NULL) return r;
	else if(k < r->key) r->leftChild=Remove(k,r->leftChild);
	else if(k > r->key) r->rightChild=Remove(k,r->rightChild);
	else{
		if(r->leftChild!=NULL && r->rightChild!=NULL)
		{
			node * tmp = FindMin(r->rightChild);
			r->key=tmp->key; r->rightChild=Remove(tmp->key,r->rightChild);
		}else{
			node * tmp=r;
			if(r->leftChild==NULL) r=r->rightChild;
			else r=r->leftChild;
			free(tmp);
		}
	}
	return r;
}
void Input()
{
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num==-1) break;
		else root=Insert(num,root);
	}
}
void Try()
{
	char cmd[30]; int num;
	while(1)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"$remove")==0)
		{
			scanf("%d",&num);
			if(Find(num,root)!=NULL)
			{
				printf("1\n"); root=Remove(num,root);
			}else printf("0\n");
		}else if(strcmp(cmd,"$find")==0)
		{
			scanf("%d",&num);
			if(Find(num,root)!=NULL) printf("1\n");
			else printf("0\n");
		}else if(strcmp(cmd,"$insert")==0)
		{
			scanf("%d",&num);
			if(Find(num,root)==NULL)
			{
				printf("1\n");
				root=Insert(num,root);
			}else printf("0\n");
		}else if(strcmp(cmd,"*")==0) break;
	}
}
int main()
{
	Input();
	Try();
	return 0;
}
