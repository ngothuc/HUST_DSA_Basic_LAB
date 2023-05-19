#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	int key;
	struct Node * leftChild;
	struct Node * rightChild;
}node;
node * root = NULL;
node * MakeNode(int k)
{
	node * temp = (node*)malloc(sizeof(node));
	temp->key=k;
	temp->leftChild=NULL; temp->rightChild=NULL;
	return temp;
}
node * Insert(int k, node * r)
{
	if(r==NULL)
	{
		r=MakeNode(k);
		return r;
	}else{
		if(r->key > k) r->leftChild=Insert(k,r->leftChild);
		else if(r->key < k) r->rightChild=Insert(k,r->rightChild);
		else return r;
	}
	return r;
}
void preOrder(node * r)
{
	if(r==NULL) return;
	printf("%d ",r->key);
	preOrder(r->leftChild);
	preOrder(r->rightChild);
}
void Try()
{
	char cmd[20]; int num;
	while(1)
	{
		scanf("%s",cmd);
		if(strcmp(cmd,"#")==0) break;
		else if(strcmp(cmd,"$insert")==0)
			 {
			 	scanf("%d",&num);
			 	root=Insert(num,root);
			 }
	}
}
int main()
{
	Try();
	preOrder(root);
	return 0;
}
