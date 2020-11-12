#include "BlockList.h"
#include <string>

void BlockList::insert(Block block)
{
	FuncBlockList.push_back(block);
}

int BlockList::find(string block_name)
{
	//int pos = -1;
	for (int i = 0; i < FuncBlockList.size(); i++) {
		if (FuncBlockList[i].getTitle() == block_name)
			return i;
	}
	return -1;
}

void BlockList::erase(int id)
{
	FuncBlockList.erase(FuncBlockList.begin() + id);
}

Block BlockList::findById(int id)
{
	/*Block b = FuncBlockList[id];
	int i = 0;
	for (auto it = FuncBlockList.begin(); it != FuncBlockList.end();)
	{
		if (i == id) {
			it = FuncBlockList.erase(it);
		}
		i++;
	}*/
	return FuncBlockList[id];
}

void BlockList::cleanList()
{
	FuncBlockList.clear();
}

int BlockList::getListSize()
{
	return FuncBlockList.size();
}

// according to the pred's block's type
void BlockList::setBodyBlock()
{
	for (int i = 1; i < FuncBlockList.size(); i++) {
		Block b = FuncBlockList[i];
		if (b.getType() == "loop_cond") {
			int p = BlockList::find(b.getNextTrue());
			Block *next = &FuncBlockList[p];
			//cout << "block name:_" << next.getTitle() << "_" << endl;
			next->setType("loop_body");
			//cout << "block type:_" << next->getType() << "_" << endl;
		}
	}
}


BlockList::BlockList()
{
}


BlockList::~BlockList()
{
}
