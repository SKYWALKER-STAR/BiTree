#include "bitree.h"

void bitree_init(BiTree bitree,void (*destroy)(void *data))
{
	bitree->root = NULL;	
	bitree->size = 0;
	bitree->destroy = destroy;
}	

int bitree_ins_left(BiTree bitree,Node node,const void *data)
{
	Node new_node ,*position;
	
	if (node == NULL) {
		if (bitree_size(bitree) > 0)
			return -1;
		position = &bitree->root;
	} else {
		if (bitree_left(node) != NULL)
			return -1;
		position = &node->left;
	}

	if ((new_node = (Node)malloc(sizeof(struct _treenode))) == NULL)
		return -1;

	new_node->data = (void*)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;
	bitree->size++;
	
	return 0;
} 

int bitree_ins_right(BiTree bitree,Node node,const void *data)
{
	Node new_node ,*position;
	
	if (node == NULL) {
		if (bitree_size(bitree) > 0)
			return -1;
		position = &bitree->root;
	} else {
		if (bitree_right(node) != NULL)
			return -1;
		position = &node->right;
	}

	if ((new_node = (Node)malloc(sizeof(struct _treenode))) == NULL)
		return -1;

	new_node->data = (void*)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;
	bitree->size++;
	
	return 0;
}

void bitree_rem_left(BiTree bitree,Node node)
{
	Node *position;
	if (bitree_size(bitree) == 0)
		return;
	
	if (node == NULL)
		position = &bitree->root;
	else
		position = &node->left;
	
	if (position != NULL) {
		bitree_rem_left(bitree,*position);
		bitree_rem_right(bitree,*position);
		if (bitree->destroy != NULL)
			bitree->destroy((*position)->data);
		free(*position);
		*position = NULL;
		bitree->size--;
	}
	
	return ;
}

void bitree_rem_right(BiTree bitree,Node node)
{
	Node *position;
	if (bitree_size(bitree) == 0)
		return;
	
	if (node == NULL)
		position = &bitree->root;
	else
		position = &node->left;
	
	if (position != NULL) {
		bitree_rem_left(bitree,*position);
		bitree_rem_right(bitree,*position);
	
		if (bitree->destroy != NULL)
			bitree->destroy((*position) -> data);
		free(*position);
		position = NULL;
		bitree->size--;
	}
	return ;
}

void bitree_destroy(BiTree bitree)
{
	if (bitree_size(bitree) == 0)
		return;
		
	bitree_rem_left(bitree,NULL);

	memset(bitree,0,sizeof(struct _bitree));
}
