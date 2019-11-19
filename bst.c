#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node* NODE;
NODE getnode(int item)
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	p->data=item;
	p->lchild=NULL;
	p->rchild=NULL;
	return p;
}
NODE insert(NODE root,int item)
{
	if(root==NULL){
		return getnode(item);}
	if(item < root->data){
		root->lchild=insert(root->lchild,item);}
	else if(item >= root->data){
		root->rchild=insert(root->rchild,item);}
	return root;
}
void inorder(NODE root)
{
	if(root==NULL)
		return;
	inorder(root->lchild);
	printf("%d ",root->data);
	inorder(root->rchild);
}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d ",root->data);
}
int height(NODE root)  
{ 
	int ldepth,rdepth;
	if (root==NULL)  
		return 0; 
	else 
	{ 
		ldepth = height(root->lchild); 
		rdepth = height(root->rchild); 
		if(ldepth > rdepth)  
			return (ldepth+1); 
		else 
			return (rdepth+1); 
	} 
}  
void printGivenLevel(NODE root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		printf("%d ", root->data); 
	else if (level > 1) 
	{ 
		printGivenLevel(root->lchild, level-1); 
		printGivenLevel(root->rchild, level-1); 
	} 
} 
void levelorder(NODE root) 
{ 
	int h = height(root); 
	int i; 
	for (i=1; i<=h; i++) 
	{ 
		printGivenLevel(root, i); 
		printf("\n"); 
	} 
} 


  
int main()
{
	int option,n,i,e;
	NODE root=NULL;
	printf("Enter no of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		root=insert(root,e);
	}
	printf("1.Inorder\n2.Preorder\n3.Postorder\n");
	printf("Enter option\n");
	scanf("%d",&option);
	while(option!=-1)
	{
		switch(option)
		{
			case 1: inorder(root);
				printf("\n");
				break;
			case 2: preorder(root);
				printf("\n");
				break;
			case 3: postorder(root);
				printf("\n");
				break;
		}
		printf("Enter other option or press -1 to exit\n");
		scanf("%d",&option);
	}
	printf("\nNodes in level order\n");
	levelorder(root);
	return 0;
}
	
			
		
