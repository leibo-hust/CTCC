#include "Pattern.h"
#include<algorithm>

using namespace std;

string setInitIns(vector<string> orgIns, string ovar, int num);
//void setRangeIns(VarList varlist);

int Pattern::getInsertLine()
{
	return insertLine;
}


string Pattern::getcontent()
{
	//return content[0];
	return InitIns;
}


void Pattern::setOps(VarList op)
{

}


//
void Pattern::setContent(VarList op1, VarList op2, VarList goal, int num)
{

	if (type == "bitmap") {
		// two vector : call 
		// goal fucntion: call void @CIM_bitmap(i32 len, int* %vec1, int* %vec2, int* %goal);
		string vecIns = setInitIns(op1.getInitIns(), "vec1", num);
		op_1.push_back("%vec1_" + to_string(num));
		setOpRange(op_1, op1);
		cout << "op_1: " << op_1[0] << "_" << op_1[1] << "_" << op_1[2] << "_" << endl;
		//op_1.push_back(vecIns);
		//setRangeIns(op1);

		string matIns = setInitIns(op2.getInitIns(), "vec2", num);
		op_2.push_back("%vec2_" + to_string(num));
		setOpRange(op_2, op2);
		cout << "op_2: " << op_2[0] << "_" << op_2[1] << "_" << op_2[2] << "_" << endl;

		string goalIns = setInitIns(goal.getInitIns(), "out", num);
		dest.push_back("%out_" + to_string(num));
		setOpRange(dest, goal);
		cout << "goal: " << dest[0] << "_" << dest[1] << "_" << dest[2] << "_" << endl;


		InitIns += vecIns + matIns + goalIns;
		//cout << "test:_" << endl;
		//cout << InitIns << endl;
		
	}
	else if (type == "mvm") {
		string vecIns = setInitIns(op1.getInitIns(), "vec", num);
		op_1.push_back("%vec_" + to_string(num));
		setOpRange(op_1, op1);
		cout << "op_1: " << op_1[0] << "_" << op_1[1] << "_" << op_1[2] << "_" << endl;
		//op_1.push_back(vecIns);
		//setRangeIns(op1);

		string matIns = setInitIns(op2.getInitIns(), "mat", num);
		op_2.push_back("%mat_" + to_string(num));
		setOpRange(op_2, op2);
		cout << "op_2: " << op_2[0] << "_" << op_2[1] << "_" << op_2[2] << "_" << endl;

		string goalIns = setInitIns(goal.getInitIns(), "out", num);
		dest.push_back("%out_" + to_string(num));
		setOpRange(dest, goal);
		cout << "goal: " << dest[0] << "_" << dest[1] << "_" << dest[2] << "_" << endl;


		InitIns += vecIns + matIns + goalIns;
		//cout << "test:_" << endl;
		//cout << InitIns << endl;
		//content.push_back(vecIns);
		//content.push_back(matIns);
		//content.push_back(goalIns);

	}
	else if (type == "mmm") {
		string vecIns = setInitIns(op1.getInitIns(), "mat1", num);
		op_1.push_back("%mat1_" + to_string(num));
		setOpRange(op_1, op1);
		cout << "op_1: " << op_1[0] << "_" << op_1[1] << "_" << op_1[2] << "_" << endl;
		//op_1.push_back(vecIns);
		//setRangeIns(op1);

		string matIns = setInitIns(op2.getInitIns(), "mat2", num);
		op_2.push_back("%mat2_" + to_string(num));
		setOpRange(op_2, op2);
		cout << "op_2: " << op_2[0] << "_" << op_2[1] << "_" << op_2[2] << "_" << endl;

		string goalIns = setInitIns(goal.getInitIns(), "out", num);
		dest.push_back("%out_" + to_string(num));
		setOpRange(dest, goal);
		cout << "goal: " << dest[0] << "_" << dest[1] << "_" << dest[2] << "_" << endl;


		InitIns += vecIns + matIns + goalIns;
		//cout << "test:_" << endl;
		//cout << InitIns << endl;

	}
	else if (type == "lib") {

	}

	setLibFunc();
	//cout << "lib:_" << endl;
	//cout << InitIns << endl;
}


void Pattern::setRangeIns(vector<string> loopvar, vector<string> looprange, int num)
{
	br_pattern_label = "  br label %block_" + type + "_" + to_string(num) + "\n";
	InitIns += "block_" + type + "_" + to_string(num) + ":\n";

	for (int i = 0; i < loopvar.size(); i++) {
		string range = looprange[i];
		if (range.find("+") != string::npos) {		//if find +
			string rangeInit;
			string load = "%load_"+ to_string(num * 10 + i);
			// ok rangeInit = "  " + load + " = load i32, i32* " + loopvar[i] + "\n";
			//string size = "%size_" + to_string(num * 10 + i);
			string size = loopvar[i] + "_size";
			rangeInit += ("  " + size + " = add i32 " + looprange[i].substr(0, looprange[i].size() - 1) + ", 1\n");
			InitIns += rangeInit;
			rangeMap.insert({ loopvar[i], size});
			cout << "Insert here ins:_" << loopvar[i] << " " << size << endl;
			//cout << "range init ins:_" << rangeInit << endl;
			//cout << "now Init ins:_" << InitIns << endl;
		}
		else if (range.find("=") != string::npos) {		//  decompilation
			
		}
		else {
			rangeMap.insert({loopvar[i], looprange[i]});
			cout << "huohuo_:" << loopvar[i] << " " << looprange[i] << endl;
		}

	}
}


Pattern::Pattern(string t)
{
	type = t;
}

Pattern::Pattern(string t, string d)
{
	type = t;
	datatype = d;
}

Pattern::~Pattern()
{
}

string setInitIns(vector<string> orgIns, string ovar, int num)
{
	// %arrayidx69 = getelementptr inbounds [2 x float], [2 x float]* %resC, i64 0, i64 %idxprom68
	// %vec1 =  getelementptr inbounds [2 x float], [2 x float]* %resC, i64 0, i64 0
	// %arrayidx108 = getelementptr inbounds float, float* %54, i64 %idxprom66
	string newIns;
	string var = ovar, middlevar;
	int len = orgIns.size();
	for (int i = len - 1; i >= 0 ; i--) {
		string oneIns = orgIns[i];
		int e = oneIns.find("=");
		/*if (len > 1) {
			if (i == 1)
				var = "%middle" + to_string(num);
			else
				var = "%mat" + to_string(num);
		}*/
		if (i == 0) {
			var = ovar + "_" + to_string(num) + " ";
		}
		else {
			var = ovar +"_middle_" + to_string(num) + " ";
			middlevar = var;
		}
		//else var = "mat";
		oneIns = "  %" + var + oneIns.substr(e);		// %vec1 =	getelementptr inbounds [2 x float], [2 x float]* %resC, i64 0, i64 %idxprom68
		//int d = oneIns.rfind(",");
		//oneIns = oneIns.substr(0, d);			// %vec1 =	getelementptr inbounds [2 x float], [2 x float]* %resC, i64 0,
		//d = oneIns.rfind(",");
		//string temp = oneIns.substr(d);			// temp = , i64 0
		//oneIns = oneIns + temp;
		//oneIns += ", i64 0";
		int d = oneIns.rfind("i64");
		if (d > 0) {
			//cout << "d is:" << d << endl;
			oneIns = oneIns.substr(0, d);
			//cout << "new ins:_" << oneIns << endl;
			oneIns += "i64 0";
		}

		if (i >= 0 && i < len - 1)
		{
			int b = oneIns.rfind("%");
			int q = oneIns.find(",", b);
			//cout << "b and q:_" << b << " " << q << "_" << endl;
			//cout << oneIns << endl;
			oneIns = oneIns.replace(b + 1, q - b - 1, middlevar);
			//cout << "replace, the ins is:_" << oneIns << "_" << endl;
		}

		//cout << "after reOrgIns:_" << oneIns << "_" << endl;
		newIns = newIns + oneIns + "\n";
	}
	//cout << "new ins is:_" << newIns << "_" << endl;
	return newIns;
}



void Pattern::setOpRange(vector<string> &op, VarList varlist)
{
	string row = varlist.getRow();
	string col = varlist.getCol();

	cout << " row and column:_" << row << "_" << col << endl;
	if (rangeMap.count(row) > 0)
		row = rangeMap[row];
	if (rangeMap.count(col) > 0)
		col = rangeMap[col];

	cout << "   new row and column:_" << row << " _" << col << endl;
	op.push_back(row);
	op.push_back(col);
}


void Pattern::setLibFunc()
{
	string funcIns;
	if (type == "bitmap") {
		// two vector : call 
		// goal fucntion: call void @CIM_bitmap(i32 len, int* %vec1, int* %vec2, int* %goal);
		funcIns = "  call void @CIM_bitmap(" + dest[1] + ", i32 " + op_1[2] + ", i32* " + op_1[0] + ", i32* " + op_2[0] + ", i32* " + dest[0] + ")\n";
	}
	else if (type == "mvm") {
		// call void @cblas_sgemv(i32 101, i32 111, i32 111(Trans), i32 500, i32 1, i32 500, float %beta0, float* %weight0, i32 500, float* %in0, i32 1, float 0.000000e+00, float* %out0, i32 1)
		funcIns = "  call void @cblas_sgemv(i32 101, i32 112, i32 " + op_2[1] + ", i32 " + op_2[2] + ", float 1.000000e+00, float* " + op_2[0] + ", i32 " + op_2[2] + ", float* " + op_1[0] + ", i32 1, float 0.000000e+00, float* " + dest[0] + ", i32 1)\n";
	}
	else if (type == "mmm") {
		//call void @cblas_sgemm(i32 101, i32 111, i32 111(Trans), i32 500, i32 1, i32 500, float %beta0, float* %weight0, i32 500, float* %in0, i32 1, float 0.000000e+00, float* %out0, i32 1)
		funcIns = "  call void @cblas_sgemm(i32 101, i32 111, i32 111, i32 " + op_1[1] + ", i32 " + op_2[2] + ", i32 " + op_1[2] + ", float 1.000000e+00, float* " + op_1[0] + ", i32 " + op_1[2] + ", float* " + op_2[0] +", i32 " + op_2[2] + ", float 0.000000e+00, float* " + dest[0] + ", i32 " + dest[2] + ")\n";
	}
	else if (type == "lib") {

	}

	InitIns += funcIns;
}


void Pattern::setbrlabels(BlockList looplist)
{
	int len = looplist.getListSize();
	int n;

	Block body = looplist.findById(len - 1);
	insertLine = body.getLastLine() - body.getContent().size() - 1;

	if (type == "bitmap") {
		n = len - 2;
	}
	else if (type == "mvm") {
		n = len - 4;
	}
	else if (type == "mmm") {
		n = len - 6;
	}

	Block b = looplist.findById(len - 2);
	modLine = b.getLastLine() - 1;
	Block c = looplist.findById(n);
	string nextblock = c.getNextFalse();
	br_next_block = "  br label %" + nextblock + "\n";
	InitIns += br_next_block;
	//cout << "in setlabels:" << endl;
	//cout << InitIns << endl;
}

int Pattern::getmodLine()
{
	return modLine;
}


string Pattern::getbrPatternLabel()
{
	return br_pattern_label;
}


void Pattern::newSetContent(VarList op1, VarList op2, VarList goal, int num) {
	
	// two vector : call 
	// goal fucntion: call void @CIM_bitmap(i32 len, int* %vec1, int* %vec2, int* %goal);
	string vecIns = setInitIns(op1.getInitIns(), "op1", num);
	op_1.push_back("%op1_" + to_string(num));
	setOpRange(op_1, op1);
	cout << "op_1: " << op_1[0] << "_" << op_1[1] << "_" << op_1[2] << "_" << endl;
	//op_1.push_back(vecIns);
	//setRangeIns(op1);

	string matIns = setInitIns(op2.getInitIns(), "op2", num);
	op_2.push_back("%op2_" + to_string(num));
	setOpRange(op_2, op2);
	cout << "op_2: " << op_2[0] << "_" << op_2[1] << "_" << op_2[2] << "_" << endl;

	string goalIns = setInitIns(goal.getInitIns(), "dest", num);
	dest.push_back("%dest_" + to_string(num));
	setOpRange(dest, goal);
	cout << "goal: " << dest[0] << "_" << dest[1] << "_" << dest[2] << "_" << endl;


	InitIns += vecIns + matIns + goalIns;
	//cout << "test:_" << endl;
	//cout << InitIns << endl;

	setLibFunc();
}


// for Decompilation

string deInitIns(vector <string> Ins, string ovar, int num) {
	string newIns;
	string var = ovar, middlevar;
	int len = Ins.size();
	for (int i = len - 1; i >= 0; i--) {
		string oneIns = Ins[i];
		//cout << "hhh init ins: " << oneIns << endl;
		//int e = oneIns.find("=");
		if (i == 0) {
			//o var = ovar + "_" + to_string(num * 10 + i) + " ";
			var = ovar + "_" + to_string(num) + " ";
		}
		else {
			var = ovar + "_middle_" + to_string(num * 10 + len - i - 1) + " ";
			middlevar = var;
		}
		int b = oneIns.find("%");
		int e = oneIns.find("=");
		oneIns.replace(b + 1, e - b - 1, var);

		if (i >= 0 && i < len - 1)
		{
			int b = oneIns.rfind("%");
			//int q = oneIns.find(",", b);
			int q = oneIns.find(" ", b);
			oneIns = oneIns.replace(b + 1, q - b, middlevar);
			//cout << "replace, the ins is:_" << oneIns << "_" << endl;
		}
		newIns = newIns + oneIns + "\n";
	}
	//cout << "in the de Init, the new ins: " << newIns << endl;
	return newIns;
}

void Pattern::deSetRangeIns(vector<string> loopvar, vector<string> looprange, BlockList looplist)
{
	if (type == "bitmap") {
		string range = looprange.back();
		op_1.push_back("1");
		op_2.push_back("1");
		dest.push_back("1");
		op_1.push_back(range);
		op_2.push_back(range);
		dest.push_back(range);
	}
}

void Pattern::deBitmapSetRangeIns(string range, string op_code)
{
	op_1.push_back("1");
	op_2.push_back("1");
	dest.push_back(op_code);
	op_1.push_back(range);
	op_2.push_back(range);
	dest.push_back(range);
}

void Pattern::deSetRange(int order, string row, string col)
{
	if (order == 0) {
		op_1.push_back(row);
		op_1.push_back(col);
	}
	else if (order == 1) {
		op_2.push_back(row);
		op_2.push_back(col);
	}
	else if (order == 2) {
		dest.push_back(row);
		dest.push_back(col);
	}
}


void Pattern::deSetContent(VarList op1, VarList op2, VarList goal, int num) 
{
	//set Block name
	InitIns = "\nblock_" + type + "_" + to_string(num) + ":\n";
	br_pattern_label = "  br label %block_" + type + "_" + to_string(num);
	//set Init ins
	string opOneIns = deInitIns(op1.getInitIns(), "op1", num);
	op_1.push_back("%op1_" + to_string(num));
	string opTwoIns = deInitIns(op2.getInitIns(), "op2", num);
	op_2.push_back("%op2_" + to_string(num));
	string goalIns = deInitIns(goal.getInitIns(), "goal", num);
	dest.push_back("%goal_" + to_string(num));

	InitIns += opOneIns + opTwoIns + goalIns;

	//setLibFunc();
	cout << "de Init ins:" << endl;
	cout << InitIns << endl;
}

/*Pattern::Pattern(VarList op1, VarList op2, VarList goal, int num, string t, string label, int line)
{
	br_pattern_label = "  br label %block_" + type + "_" + to_string(num) + "\n";
	//set Init ins
	string opOneIns = deInitIns(op1.getInitIns(), "op1", num);
	string opTwoIns = deInitIns(op2.getInitIns(), "op2", num);
	string goalIns = deInitIns(goal.getInitIns(), "goal", num);

	// set the label
	//br i1 % 187, label %block_400628, label %block_4005f0  ---> br i1 % 187, label %block_400628, label %block_pattern_0

}*/

void Pattern::insertContent(string addIns)
{
	InitIns += addIns;
	//content.push_back(addIns);
}