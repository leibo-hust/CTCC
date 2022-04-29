#include "VarList.h"
#include <regex>
#include <cstring>
#include <math.h>
#include <iostream>

string equalvar(string keyword, string ins);

bool VarList::findVar(string goalvar)
{
	bool flag;
	vector<string>::iterator iter = find(varlist.begin(), varlist.end(), goalvar);
	if (iter == varlist.end())
		flag = false;
	else
		flag = true;

	return flag;
}

void VarList::buildList(BlockList blocklist, string var)
{
	//all key instructions
	//% 144 = inttoptr i64 %385 to i32*
	//%145 = load i32, i32* %144
	//sotre
	cout << "Building the varlist......." << endl;
	cout << "  var is:_" << var << "_" << endl;
	int len = blocklist.getListSize();
	for (int i = len - 1; i >= 0; i--) {
		vector<string> content = blocklist.findById(i).getContent();
		int n = content.size();
		for (int j = n - 1; j >= 0; j--) {
			if (varlist.empty() || varlist.back() != var) {
				varlist.push_back(var);
			}
			string ins = content[j];
			//cout << "__" << ins << endl;
			//string ins = "%j = load i32, i32* %x, align 4";
	//string ins = "store i32 %mul, i32* %i, align 4";
			//regex load(" = load i+[0-9]*, [a-z, 0-9]*\\* %[a-z, 0-9]");
			//regex load(var + " = load i+[0-9]*, [a-z, 0-9]*\\* %[a-z, 0-9]");		//only match the load i32/i16
			//regex store("store i+[0-9]* %[a-z, 0-9]*, i+[0-9]*\\* " + var);		//only match the load i32/i16
			regex load(var + " = load [a-z, 0-9]*, [a-z, 0-9]*\\* %[a-z, 0-9]");
			//% 144 = inttoptr i64 %385 to i32*
			regex inttoptr(" = inttoptr i+[0-9]* %[a-z, 0-9]* to i+[0-9]*\\*");		//in the decompilation, find the init ins of the loop var

			//store i32 %mul, i32* %var(goal), align 4
			//regex store("store i+[0-9]* %[a-z, 0-9]*, i+[0-9]*\\*");
			regex store("store [a-z, 0-9]* [a-z, 0-9]*, [a-z, 0-9]*\\* " + var);

			//store i32 %var(goal), i32* %arrayidx4, align 4
			regex store2("store [a-z, 0-9]* " + var);
			regex getelment(var + " = getelementptr ");			//use to find the init ins
			regex equal(var + " = ");			//use to find the init ins
			
			smatch s;
			if (regex_search(ins, s, load)) {
				//cout << "matching load...." << ins << endl;
				int b = ins.find("load");
				int e = ins.find("%", b);
				int t = ins.find(",", e);
				int n = ins.size();
				string temp = ins.substr(e, min(t, n) - e);
				//cout << "temp is:_" << temp << "_" << endl;
				var = temp;
			}
			else if (regex_search(ins, s, store)) {
				//cout << "mmmmmatching store.... " <<  ins << endl;
				int b = ins.find("store");
				int e = ins.find("%", b);
				int t = ins.find(",", e);
				//int n = ins.size();
				string temp = ins.substr(e, t - e);
				//cout << "yttttttemp is:_" << temp << "_" << endl;
				var = temp;
			}
			else if (regex_search(ins, s, store2)) {
				//cout << "mmmmmatching store2.... " << var << endl;
				int b = ins.find(",");
				int e = ins.find("%", b);
				int t = ins.find(",", e);
				//int n = ins.size();
				string temp = ins.substr(e, t - e);
				//cout << "yttttttemp is:_" << temp << "_" << endl;
				var = temp;
			}
			else if (regex_search(ins, s, getelment)) {		//set the init ins
				// cout << "///////////////////////////////getelementptr: " << ins << endl;
				//cout << "getelement init ins is:_" << ins << "_" << endl;
				int old_j = j;
				int b = ins.find("=");
				int e = ins.find("%", b);
				int t = ins.find(",", e);
				string array = ins.substr(e, t - e);
				// add to init ins
				initIns.push_back(ins);
				//Determine the type based on the first two instructions for getelementptr
				regex vadd(" = add"), vload(" = load ");
				// regex newequal(array + " = ");			//use to find the init ins
				regex middlegetelment(array + " = getelementptr ");			//use to find the init ins
				// cout << "111111111111 array is: " << ins << " ," << array << endl;
				bool isMat = false;
				for (int k = j - 1; k >= 0; k--) {
					if (regex_search(content[k], s, middlegetelment)) {
						initIns.push_back(content[k]);
						isMat = true;
						int bb = content[k].find("*") + 2;
						int tt = content[k].find(",", bb);
						string mat = content[k].substr(bb, tt - bb);
						// cout << "------~~~~mat:-" << mat << "-" << endl;
						varlist.push_back(mat);
						j = k;
						break;
					}
				}

				if (isMat) {
					type = "matrix";
					regex rangeload(" = load +[i32|i16]+, +[i32|i16]+\\* %[a-z, 0-9]*,");	
					int count = 0;
					for (int k = old_j; k >= 0; k--) {
						if (regex_search(content[k], s, rangeload)){
							int b = content[k].find("*"), e = content[k].find(",", b);
							// cout << "----111111 in set range: " << content[k] << endl;
							string r = content[k].substr(b + 2, e - b - 2);
							if (count == 0) {
								col = r;
							}
							else if (count == 1) {
								row = r;
							} else {
								break;
							}
							count++;
						}
					}
				} else {
					type = "vector";
					row = "1";
					int b = content[j - 2].find("*"), e = content[j - 2].find(",", b);
					col = content[j - 2].substr(b + 2, e - b - 2);
				}


				/*if (regex_search(content[j - 2], s, vadd) || ins.find("%arrayidx", b) != string::npos) {
					type = "matrix";
					regex rangeload(" = load +[i32|i16]+, +[i32|i16]+\\* %[a-z, 0-9]*,");	
					int count = 0;
					for (int k = j; k >= 0; k--) {
						if (regex_search(content[k], s, rangeload)){
							int b = content[k].find("*"), e = content[k].find(",", b);
							string r = content[k].substr(b + 2, e - b - 2);
							if (count == 0) {
								col = r;
							}
							else if (count == 1) {
								row = r;
								// j = k;
								// break;
							}
							count++;
						} else if (regex_search(content[k], s, newequal)) {
							//cout << "matching....." << newins << endl;
							//initIns = newins + "\n" + initIns;
							initIns.push_back(content[k]);
							int bb = ins.find("*");
							int tt = ins.find(",", bb);
							string mat = ins.substr(bb, tt - bb);
							cout << "------~~~~mat" << mat << "-" << endl;
							varlist.push_back(mat);
							j = k;
							break;
						}
					}
					//cout << "col and row Is:_" << row << "_" << col << "_" << endl;
				} 
				else if (regex_search(content[j - 2], s, vload)) {
					//cout << "t:_" << content[j - 2] << endl;
					type = "vector";
					row = "1";
					int b = content[j - 2].find("*"), e = content[j - 2].find(",", b);
					col = content[j - 2].substr(b + 2, e - b - 2);
					//cout << "col is:_" << col << "_" << endl;

				}*/
				//cout << "current ins is:_" << ins << endl;
				//cout << "before twor is:_" << content[j - 2] << endl;
				//cout << "judge type is:_" << type << endl;
				
				//cout << "the array is:_" << array << endl;
				//var = array;
				//initIns = ins;
				// cout << "array is:-" << array << endl;
				var = array;
			}
			else if (regex_search(ins, s, equal)) {		//set the init ins
				//cout << "init ins is:_" << ins << "_" << endl;
				//initIns = ins;
				initIns.push_back(ins);
			}
			else if (regex_search(ins, s, inttoptr)) {
				//cout << "inttoptr ins is:_" << ins << "_" << endl;
				//initIns = ins;
				initIns.push_back(ins);
			}
		}
	}
	
}

void VarList::addVar(string& var) {
	varlist.push_back(var);
}


//void VarList::deBuilidVarList(Block loopbody, string var)
void VarList::deBuilidVarList(vector<string> &content, string var)
{
	//vector<string> content = loopbody.getContent();
	cout << "calling the decompile varlist build" << endl;
	cout << "var is:_" << var << "_" << endl;
	varlist.push_back(var);
	smatch s;
	string temp;
	string ins;
	bool isMatch;

	int n = content.size();
	for (int j = n - 1; j >= 0; j--) {
		isMatch = false;
		ins = content[j];

		regex load(var + " = load [a-z, 0-9]*, [a-z, 0-9]*\\* %[a-z, 0-9]");				//%133 = load i32, i32* %132
		regex inttoptr(var + " = inttoptr i+[0-9]* %[a-z, 0-9]* to i+[0-9]*\\*");			//%132 = inttoptr i64 %131 to i32*
		regex store("store [a-z, 0-9]* [a-z, 0-9]*, [a-z, 0-9]*\\* " + var);				//store i32 % 133, i32* (%134)
		regex store2("store [a-z, 0-9]* " + var + ",");											//store i32 % (134), i32* %137
		regex shl(var + " = shl nsw ");														//%126 = shl nsw i64 %125, 2
		regex sext(var + " = sext i+[0-9]*");												//%125 = sext i32 %179 to i64
		regex mul(var + " = mul nsw i64 %[0-9]*, [0-9]*");												//%125 = sext i32 %179 to i64
		regex equal(var + " = ");			//use to find the init ins
		//cout << "ins is: " << ins << endl;
		//cout << "var is:_" << var << "_" << endl;
		if (regex_search(ins, s, load)) {
			//1  cout << "matching load...." << ins << endl;
			temp = equalvar("load", ins);
			//1 cout << "laod temp is:_" << temp << "_" << endl;
			isMatch = true;
		}
		else if (regex_search(ins, s, store)) {
			//1 cout << "matching store.... " << ins << endl;
		    temp = equalvar("store", ins);
			//1 cout << "store temp is:_" << temp << "_" << endl;
			isMatch = true;
		}
		else if (regex_search(ins, s, store2)) {
			//1 cout << "mmmmmatching store2.... " << ins << endl;
			temp = equalvar(",", ins);
			//1 cout << "store2 temp is:_" << temp << "_" << endl;
			isMatch = true;

		}
		else if (regex_search(ins, s, shl) || regex_search(ins, s, mul)) {		//set the init ins
			//1 cout << "mmmmmatching shl.... " << ins << endl;
			temp = equalvar("=", ins);
			//1 cout << "temp is:_" << temp << "_" << endl;
			isMatch = true;

		}
		else if (regex_search(ins, s, inttoptr) || (regex_search(ins, s, sext))) {
			//1 cout << "matching inttoptr.... " << ins << endl;
			int b = ins.find("=");
			int e = ins.find("%", b);
			int t = ins.find(" ", e);
			temp = ins.substr(e, t - e);
			//1 cout << "temp is:_" << temp << "_" << endl;
			initIns.push_back(ins);
			//find the type
			isMatch = true;
			
		}
		else if (regex_search(ins, s, equal)) {		//set the init ins
			//1 cout << "adding the init: " << ins << endl;
			initIns.push_back(ins);
			//initIns.insert(initIns.begin(), ins);
		}

		if (isMatch) {
			var = temp;
			varlist.push_back(var);

		}
		//var = temp;
	}
}

string equalvar(string keyword, string ins) {
	int b = ins.find(keyword);
	int e = ins.find("%", b);
	int t = ins.find(",", e);
	if (t != string::npos) {	//if find ","
		return ins.substr(e, t - e);
	}
	else {
		return ins.substr(e);
	}
}

void VarList::setInitIns(vector<string> newIns)
{
	initIns = newIns;
}

vector<string> VarList::getInitIns()
{
	return initIns;
}

/*string VarList::getinitIns()
{
	return initIns;
}*/

void VarList::setType(string t)
{
	type = t;
}


string VarList::getType()
{
	return type;
}


void VarList::setRow(string r)
{
	row = r;
}


string VarList::getRow()
{
	return row;
}


void VarList::setCol(string c)
{
	col = c;
}


string VarList::getCol()
{
	return col;
}


/*oid VarList::setRange(string line, vector<string> varlist)
{
	int n = varlist.size();

	smatch s;
	for (int i = 0; i < n; i++) {
		string var = varlist[i];
		regex rangevar(var);			//use to find the init ins
		if (regex_search(line, s, rangevar)) {
			range.push_back(var);
			break;
		}
	}
}


vector<string> VarList::getRange()
{
	return range;
}*/

void VarList::showList()
{
	cout << "----------------show all the var in the list:" << endl;
	for (int i = 0; i < varlist.size(); i++) {
		cout << varlist[i] << endl;
	}
	cout << "-----------------end" << endl;
}

vector<string> VarList::getList()
{
	return varlist;
}

int VarList::Size()
{
	return varlist.size();
}

bool VarList::operator==(VarList& other) {
	vector<string> otherlist = other.getList();
	for (int i = 0; i < otherlist.size(); i++) {
		for (int j = 0; j < varlist.size(); j++) {
			if (otherlist[i] == varlist[j]) {
				return true;
			}
		}
	}

	return false;
}

string VarList::getVar(int i)
{
	return varlist[i];
}

VarList::VarList()
{
}


VarList::~VarList()
{
}
