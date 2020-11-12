#ifndef BTREE_H
#define BTREE_H
#include "Block.h"
#include "BlockList.h"
#include <iostream>
#pragma once
using namespace std;

class Node
{
public:
	Block block;
	Node* left;
	Node* right;

public:
	Node();
	~Node();
};

class BTree
{
private:
	Node* root; //root node
	//static int callcount;

public:
	//void create(Node * &p, Node * &temp); //create the binary tree
	void create(Node * &node, Block block, BlockList list);
	void Init(Node * p); //create the binary tree
	//void InsertLeftChild(Node *tree, Node *left);
	//void InsertRightChild(Node *tree, Node *right);

	//void insert(Node * &p); //insert node
	//Node* search(string name);
	void destroy(Node * &p);  //destory
	void printTree(Node *Tree);
	void findLoops(Node *Tree);
	Node* getRoot();

	BTree();
	~BTree();
};

#endif // BTREE_H