#include <iostream>
#include <vector>
using namespace std;
#pragma once
class Block
{
private:
	string title;   //name of block
	string type;    //type of the block: loop_cond, loop_body, other
	string next_true_block; //br next block
	string next_false_block; //br next block
	string preds_1; //before block
	string preds_2; //before block
	int last_line_num; //line num of the last line of loop_cond block
	vector<string> content;

public:

	Block * left;
	Block * right;

	string getTitle();		//get the title of the block
	string getType();		//get the type of the block
	string getNextTrue();	//get the br true block
	string getNextFalse();  //get the br false block
	string getPreds1();		//get the preds1
	string getPreds2();		//get the preds2
	int getLastLine();
	vector<string> getContent();		//get the content

	void setTitle(string title);
	void setTtileAndPreds(string oneline);			//new
	void setType(string type);
	void DecideType();
	void setNextTrue(string label);
	void setNextFalse(string label);
	void setNextLabels(bool isDecomplie);			//new
	void setPreds1(string preds1);
	void setPreds2(string preds2);
	void setLastLine(int linenum);
	void setContent(string line);
	void cleanContent();			//clean the content of the block
	void showBlock();				//print all the content of the block

	Block();
	~Block();
};

class Loop_cond_block : public Block
{
private:
	string range; //range of the loop
	string range_var; //loop condition control variable
	//string next_false_block; //br false label;

public:
	string getRange();
	string getRangeVar();
	//string getNextFalse();

	void setRange(string range);
	void setRangeVar(string var);
	//void setNextFalse(string next);
};

class Loop_body_block : public Block
{
private:
	//vector<std::string> content; //the content of loop body

public:
	//void setContent(string line);
	string getPatternType();
};
