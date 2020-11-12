#pragma once
#include <vector>
#include "Block.h"
using namespace std;

class BlockList
{
public:
	vector<Block> FuncBlockList;		//store all the blocks in one function model;

public:
	void insert(Block block);			//insert one block to the list
	int find(string block_name);		//return the block according to its name
	Block findById(int id);
	void erase(int id);
	void cleanList();					//clean the content of the blocklist
	int getListSize();
	void setBodyBlock();				// find the loop body block in the decompiled IR

	BlockList();
	~BlockList();
};

