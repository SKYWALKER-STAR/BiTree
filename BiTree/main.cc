#include "tree.h"

#define MAXSIZE 10000

int main()
{
	int i;
	int array[MAXSIZE];
	class BiTree MingBiTree(NULL);
	Node ptr;
	
	for (i = 0;i < MAXSIZE;i++)
		array[i] = i;
	
	MingBiTree.bitree_ins_left(NULL,&array[29]);
	ptr = MingBiTree.bitree_root();
	printf("root:%d\n",*(int*)ptr->data);
	
	MingBiTree.bitree_ins_right(ptr,&array[32]);
	printf("%d\n",*(int*)ptr->right->data);

	MingBiTree.bitree_ins_right(ptr->right,&array[52]);
	printf("%d\n",*(int*)ptr->right->right->data);

	MingBiTree.bitree_rem_left(ptr->right);
	
	
	printf("size:%d\n",MingBiTree.bitree_size());

}
