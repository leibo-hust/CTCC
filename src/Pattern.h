#pragma once
#include <string>
#include <vector>
#include "VarList.h"
#include "BlockList.h"
#include <map>

using namespace std;

class Pattern
{
private:
	string type;
	string datatype;				// the data type, use to distinguish the data type
	vector<string> content;
	string InitIns;
	int modLine;					//line number where the preds last line
	string br_pattern_label;		//the label that jump to the pattern block
	int insertLine;					//insert place
	string br_next_block;			//block that the pattern should jump to
	vector <string> op_1;			// op_1[3]: op1_name, op1_row, op1_col
	vector <string> op_2;
	vector <string> dest;

	//range instructons
	map<string, string> rangeMap;


public:
	int getInsertLine();
	int getmodLine();
	string getbrPatternLabel();
	void setContent(VarList op1, VarList op2, VarList goal, int num);
	void newSetContent(VarList op1, VarList op2, VarList goal, int num);
	string getcontent();
	void setOps(VarList op);
	void setRangeIns(vector<string> loopvar, vector<string> looprange, int num);
	void setOpRange(vector<string> &op, VarList varlist);
	void setbrlabels(BlockList looplist);				//set the label br to this block and the label the block br to
	//Pattern(VarList op1, VarList op2, VarList goal, int num, string t, string label, int line);			//	for decompilation
	void setLibFunc();

	//for decompile
	void deSetContent(VarList op1, VarList op2, VarList goal, int num);
	void deSetRangeIns(vector<string> loopvar, vector<string> looprange, BlockList looplist);
	void deBitmapSetRangeIns(string range, string op_code);
	void deSetRange(int order, string row, string col);

	void insertContent(string addIns);

	//Pattern(string t, int l);
	Pattern(string t);
	Pattern(string t, string d);
	~Pattern();
};

