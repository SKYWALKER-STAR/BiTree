#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

struct _treenode;
struct _bitree;

typedef struct _treenode *PtrToTreeNode;
typedef PtrToTreeNode Node;
typedef struct _bitree	*PtrToTree;
typedef PtrToTree	BiTree;

#define bitree_size(tree) tree->size
#define bitree_left(node) node->left
#define bitree_right(node) node->right
#define bitree_is_leaf(node) (node->left == NULL && node->right == NULL) \
				? 1 : 0
#define bitree_data(node) node->data
#define bitree_left(node) node->left
#define bitree_right(node) node->right
#define bitree_is_eob(node) ((node) == NULL)
#define bitree_root(bitree) bitree->root

struct _treenode {
	void 	*data;
	Node	left;
	Node	right;
};

struct _bitree {
	int size;
	Node root;
	void (*destroy)(void *data);
	int (*compare)(const void *key1,const void *key2);
};

void bitree_init(BiTree bitree,void (*destroy)(void *data));
int bitree_ins_left(BiTree bitree,Node node,const void *data);
int bitree_ins_right(BiTree bitree,Node node,const void *data);
void bitree_rem_left(BiTree bitree,Node node);
void bitree_rem_right(BiTree bitree,Node node);
void bitree_destroy(BiTree bitree);
#endif
