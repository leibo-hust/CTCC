#pragma once
#include <string>
#include <vector>
#include "BlockList.h"
using namespace std;

class VarList
{
private:
	vector<string> varlist;			//store all the variables that equal to the key variable
	//string initIns;					//store the init instruction of the variable, aim to use it if the structure is pattern
	vector<string> initIns;
	string type;
	string row, col;
	//vector<string> range;
		
public:
	bool findVar(string goalvar);		//judge if the variable is in the list
	void addVar(string& var);
	void buildList(BlockList blocklist, string var);		//according to the blocklist of the function and the key var, build the varList;
	//string getinitIns();				//get the init instuction
	vector<string> getInitIns();
	void setInitIns(vector<string> newIns);
	void setType(string t);
	string getType();
	void setRow(string r);
	string getRow();
	void setCol(string c);
	string getCol();
	void deBuilidVarList(vector<string> &content, string var);
	//void deBuilidVarList(Block loopbody, string var);
	void showList();
	vector<string> getList();
	int Size();
	string getVar(int i);
	bool operator==(VarList& other);

	//void setRange(string line, vector<string> varlist);
	//vector<string> getRange();
	VarList();
	~VarList();
};

