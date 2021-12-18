#ifndef BISTREE_H
#define BISTREE_H

#include "tree.h"

typedef BiTree BisTree:

#define AVL_LFT_HEAVY 1
#define AVL_BALANCED 0
#define AVL_RGT_HEAVY -1

typedef struct AvlNode_
{
	void *data;
	int hidden;
	int factor;
}AvlNode;

void bistree_init(BisTree *tree,int (*compare)(const void *key1,const void *key2),
			void (*destroy)(void*data));



#endif
