#include "BTree.h"
#include <string>
#include <iostream>

BTree::BTree()
{
	//root = nullptr;
	root = new Node;
	//callcount = 1;
}

BTree::~BTree()
{
	//Node * p = root;
	//destroy(p);
}

Node::Node()
{
}

Node::~Node()
{
}

void BTree::Init(Node * p)
{
	//root = p;
}

/*void BTree::create(Node * &p, Node * &temp)
{
	//保证二叉树满足 左子树小于根节点，右子树大于根节点
	//p是新的节点，temp是从root开始遍历的节点
	if (temp == nullptr)
	{
		temp = p;
	}
	else
	{
		//if the block has occured or is empty string
		if (temp->title == p->title  || temp->title.empty())
		{
			cout << "the same value is not allowed" << endl;
		}
		else if (p->title == temp->getNextTrue()) //新节点比根节点小，就去左边递归
		{
			create(p, temp->left);
		}
		else if (p->title == temp->getNextFalse()) //p->data > root->data //反之去右边递归
		{
			create(p, temp->right);
		}

	}

}*/

void BTree::create(Node * &node, Block block, BlockList list)
{
	//callcount++;
	//cout << "n is:_" << callcount << endl;
	//cout << "size is:_" << list.FuncBlockList.size() << endl;
	if (node == nullptr) {
		node = new Node;
	}
	else {
		cout << "ooooooooooooot title:_" << node->block.getTitle() << endl;
		root = node;
		cout << "rooooooooooooot title:_" << root->block.getTitle() << endl;
	}
		
	node->block = block;
	int e = list.find(block.getTitle());
	list.erase(e);		//erase the used block to void build the graph

	/*cout << "title:_" << node->block.getTitle() << endl;
	cout << "type:_" << node->block.getType() << endl;
	cout << "the left:_" << node->block.getNextFalse() << endl;
	cout << "the right:_" << node->block.getNextTrue() << endl;
	cout << "--------------------------" << endl;*/

	int rp = list.find(node->block.getNextTrue());
	if (rp != -1) {
		//Block *b = &list.findById(rp);
		//create(node->right, b, list);
		create(node->right, list.findById(rp), list);
	}
	int lp = list.find(node->block.getNextFalse());
	if (lp != -1) {
		//Block *b = &list.findById(lp);
		//create(node->left, b, list);
		create(node->left, list.findById(lp), list);
	}
	//if (callcount <= list.FuncBlockList.size()) {
	/*if (!node->block->getNextTrue().empty()) {
		int p = list.find(node->block->getNextTrue());
		if (p != -1) {
			create(node->right, &list.findById(p), list);
		}
	}*/
	/*if (!node->block->getNextTrue().empty()) {
		create(node->right, &list.find(node->block->getNextTrue()), list);
	}*/
	//}
	

	/*if (node->block->getNextTrue().empty()) {
		cout << block->getTitle() << " right null" << endl;
		//return;
	}
	else {
		create(node->right, &list.find(node->block->getNextTrue()), list);
	}

	if ((node->block->getNextFalse().empty())) {
		cout << block->getTitle() << " left null" << endl;
		//return;
	}
	else {
		create(node->right, &list.find(node->block->getNextFalse()), list);
	}*/
}


void BTree::destroy(Node * &p)
{
	if (p != nullptr)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = nullptr;
	}
}


void BTree::printTree(Node *Tree) {
	//cout << "tree block title:_" << Tree->block->getTitle() << endl;
	if (Tree != NULL) {
		cout << "tree block title:_" << Tree->block.getTitle() << " and block type:_" << Tree->block.getType() << endl;
		printTree(Tree->right);
		printTree(Tree->left);
	}
	/*else {
		cout << "is null ptr" << endl;
	}*/
} 

void BTree::findLoops(Node *Tree)
{
	BlockList looplist;
	if (Tree != NULL) {
		if (Tree->block.getType() == "loop_cond") {
			//cout << "in the loop find function:" << Tree->block.getTitle() << endl;
			looplist.insert(Tree->block);
			//cout << "right in the loop find function:" << Tree->right->block.getType() << endl;
			Node *cond = new Node;
			cond = Tree;
			while(cond->right->block.getType() != "other")
			{
				//cout << "title and type of right:" << cond->right->block.getTitle() << "_ " << cond->right->block.getType() << endl;
				looplist.insert(cond->right->block);
				cond = cond->right;
			}
			cout << "````````````````````````````````" << endl;
			for (int i = 0; i < looplist.getListSize(); i++) {
				cout << "title: " << looplist.FuncBlockList[i].getTitle() << endl;
				//cout << "2222222222222222222222222222222222222222222222222222222" << endl;
			}
			findLoops(Tree->left);			//Recursive left
		}
		else {
			//cout << "others:" << Tree->block.getTitle() << endl;
			findLoops(Tree->right);
			findLoops(Tree->left);
		}
	}
}

Node* BTree::getRoot()
{
	return root;
}

/*void BTree::InsertLeftChild(Node *tree, Node *left) {
	tree->left = left;
}

//插入一个右节点
void BTree::InsertRightChild(Node *tree, Node *right) {
	tree->right = right;
}*/
