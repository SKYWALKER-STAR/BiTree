#include "tree.h"
using std::cout;
using std::endl;

BiTree::BiTree(void(*destroy)(void *data))
{
	size = 0;
	root = NULL;
	data_destroy = destroy;
}

BiTree::~BiTree()
{
	bitree_rem_left(NULL);
	root = NULL;
}

int BiTree::bitree_ins_left(Node node,const void *data)
{
	Node new_node;
	if ((new_node = (struct _treenode*)malloc(sizeof(struct _treenode))) == NULL)
		return -1;
	
	new_node->data = (int*)data;
	
	if (node == NULL) {
		if (size != 0)
			return -1;//not allow insert root when tree is not empty
		root = new_node;
		new_node -> left = NULL;
		new_node -> right = NULL;
	} else {
		if (node -> left != NULL)
			return -1;//If node alreay have a left node,not insert
		node -> left = new_node;
		new_node -> left = NULL;
		new_node -> right = NULL;
	}
	
	size++;
	return 0;
	
}

int BiTree::bitree_ins_right(Node node,const void *data)
{
	Node new_node;
	if ((new_node = (struct _treenode*)malloc(sizeof(struct _treenode))) == NULL)
		return -1;
	
	new_node->data = (int*)data;
	
	if (node == NULL) {
		if (size != 0)
			return -1;//not allow insert root when tree is not empty
		root = new_node;
		new_node -> left = NULL;
		new_node -> right = NULL;
	} else {
		if (node->right != NULL)
			return -1;
		node -> right = new_node;
		new_node -> left = NULL;
		new_node -> right = NULL;
	}
	
	size++;
	return 0;
	
}

void BiTree::bitree_rem_left(Node node)
{
	Node position;
	
	if (bitree_size() == 0)
		return;
	
	if (node == NULL)
		position = bitree_root();
	else
		position = node->left;
	
	if (position != NULL) {
		bitree_rem_left(position);
		bitree_rem_right(position);
		if (data_destroy != NULL)
			data_destroy(position->data);
		free(position);
		position = NULL;
		size--;
	}

	return;
}

void BiTree::bitree_rem_right(Node node)
{
	Node position;
	
	if (bitree_size() == 0)
		return;
	if (node == NULL)
		position = bitree_root();
	else
		position = node->right;
	
	if (position != NULL) {
		bitree_rem_left(position);
		bitree_rem_right(position);
		if (data_destroy != NULL)
			data_destroy(position->data);
		free(position);
		position = NULL;
		size--;
	}
	
	return;
}

int BiTree::bitree_size()
{
	return size;
}

Node BiTree::bitree_root()
{
	return root;
}

int BiTree::bitree_is_eob(Node node)
{
	if (node -> left == NULL && node->right == NULL)
		return 1;
	else
		return 0;
}

void *BiTree::bitree_data(const Node node)
{
	return node->data;
}

Node BiTree::bitree_left(const Node node)
{
	return node->left;
}

Node BiTree::bitree_right(const Node node)
{
	return node->right;
}

int bitree_is_leaf(const Node node)
{
	return (node->left == NULL || node->right == NULL) ? 1 : 0;
}

int BiTree::bitree_merge(class BiTree *left,class BiTree *right,void *data)
{
	
	if ((root = (struct _treenode*)malloc(sizeof(struct _treenode))) == NULL)
		return -1;

	size = left->bitree_size() + right->bitree_size();
	root->data = data;
	root->left = left->bitree_root();
	root->right = right->bitree_root();
	return 0;
}
