#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <iomanip>

struct _treenode;
typedef struct _treenode *PtrToTreeNode;
typedef PtrToTreeNode Node;

struct _treenode {
	void *data;
	PtrToTreeNode left;
	PtrToTreeNode right;
};
	

class BiTree {
public:
	BiTree(void (*destroy)(void *data));
	int bitree_ins_left(Node node,const void *data);
	int bitree_ins_right(Node node,const void *data);
	void bitree_rem_left(Node node);
	void bitree_rem_right(Node node);
	
	int bitree_size();
	Node bitree_root();
	int bitree_is_eob(Node node);
	void *bitree_data(const Node node);
	Node bitree_left(const Node node);
	Node bitree_right(const Node node);
	int bitree_is_leaf(const Node node);

	int bitree_merge(class BiTree *left,class BiTree *right, void *data);
	~BiTree();
private:
	int size;
	Node root;
	void (*data_destroy)(void *data);
};
#endif
