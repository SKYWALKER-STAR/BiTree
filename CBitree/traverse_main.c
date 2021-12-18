#include "traverse.h"
#include <time.h>

#define MAX 100

int main()
{
	int i;
	int data[MAX];
	long int posi;
	struct _bitree bitree;
	Node root;
	
	struct list list;
	Element listnode;
	Element ptrlist;
	
	
	bitree_init(&bitree,NULL);
	for (i = 0;i < MAX;i++)
		data[i] = i;
	
	bitree_ins_right(&bitree,NULL,&data[0]);

	bitree_ins_right(&bitree,bitree.root,&data[1]);
	bitree_ins_left(&bitree,bitree.root,&data[2]);

	bitree_ins_right(&bitree,bitree.root->right,&data[3]);
	bitree_ins_left(&bitree,bitree.root->right,&data[4]);

	bitree_ins_right(&bitree,bitree.root->left,&data[5]);
	bitree_ins_left(&bitree,bitree.root->left,&data[6]);

	bitree_ins_right(&bitree,bitree.root->left->left,&data[7]);
	bitree_ins_left(&bitree,bitree.root->left->left,&data[8]);

	bitree_ins_right(&bitree,bitree.root->left->right,&data[9]);
	bitree_ins_left(&bitree,bitree.root->left->right,&data[10]);

	printf("%d\n",bitree.size);
	
	list_init(&list,NULL);

	inorder(bitree.root,&list);
	ptrlist = list.head;
	
	printf("%d\n",list.size);
	
	while (ptrlist != NULL) {
		printf("%d ",*(int*)ptrlist->data);
		ptrlist = ptrlist -> next;
	}

	printf("\n");
	
	return 0;
			
		
}
