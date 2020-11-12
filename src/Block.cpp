#include "Block.h"
#include <iostream>
#include <string>
#include <regex>

string Block::getTitle()
{
	return title;
}

string Block::getType()
{
	return type;
}

string Block::getNextTrue() 
{
	return next_true_block;
}

string Block::getNextFalse()
{
	return next_false_block;
}

string Block::getPreds1()
{
	return preds_1;
}

string Block::getPreds2()
{
	return preds_2;
}

int Block::getLastLine()
{
	return last_line_num;
}

vector<string> Block::getContent()
{
	return content;
}

//get function
void Block::setTitle(string title)
{
	Block::title = title;
}	

void Block::setTtileAndPreds(string oneline)
{
	int p, q, r;   //positions of the key chars
	//string title, preds_1, preds_2;;   //the block name of current block and the two preds

	p = oneline.find(":");
	title = oneline.substr(0, p);
	//cout << "titl:_" << title << endl;

	if ((q = oneline.find("preds")) != string::npos) {
		if ((r = oneline.find(",")) != string::npos) {		//if there are two preds
			preds_1 = oneline.substr(q + 9, r - q - 9);
			preds_2 = oneline.substr(r + 3);
			//cout << "prdes1:_" << preds_1 << "_" << " prdes2:_" << preds_2 << "__" << endl;
		}
		else {
			preds_1 = oneline.substr(q + 9);
			//cout << "prdes1:_" << preds_1 << "_" << endl;
		}
	}
}

void Block::DecideType()
{
	//Compile-according to the name of the block
	regex loop_cond("[for|while]+.cond[0-9]*");      //Regular matching, identify whether it is a cond block
	regex loop_body("[for|while]+.body[0-9]*");      //whether it is a body block
	smatch s;
	if (regex_search(title, s, loop_cond)) {
		type = "loop_cond";
	}
	else if (regex_search(title, s, loop_body)) {
		type = "loop_body";
	}
	else
		type = "other";

	//Decompile
	//loop cond-according to the key instrctions of the block
	//regex phi_1("phi i64"), phi_2("phi %struct.Memory\\* ");
	regex phi("phi");
	if (!preds_1.empty() && !preds_2.empty()) { //two preds are not null 
		//cout << "the first :" << content[1] << endl;
		//cout << "the second :" << content[2] << endl;
		if (regex_search(content[1], s, phi) && regex_search(content[2], s, phi)) {
			//cout << "decompile loop cond foud" << endl;
			type = "loop_cond";
		}
	}
	//loop body-according to the type of the preds

}

//old available
void Block::setType(string type)
{
	Block::type = type;
}

void Block::setNextLabels(bool isDecomplie) {
	//vector <string> names;
	string oneline = content.back();
	int q, r;   //positions of the key chars

	//br i1 %cmp, label %for.body, label %for.end           br label %for.inc52
	if (oneline.find("ret") != string::npos) {			//ret is the last block
		next_true_block = next_false_block = "";
	}
	else {
		q = oneline.find("label");

		if ((r = oneline.find(",", q)) != string::npos) {		//if there are two preds
			next_true_block = oneline.substr(q + 7, r - q - 7);
			next_false_block = oneline.substr(r + 9);
			if (isDecomplie) {	//swap
				string temp = next_true_block;
				next_true_block = next_false_block;
				next_false_block = temp;
			}
		}
		else {
			next_true_block = oneline.substr(q + 7);
			next_false_block = "";
		}
	}
	//cout << "true_label:_" << truelabel << "_" << "                  false_label:_" << falselabel << "_" << endl;
}


void Block::setNextTrue(string label)
{
	next_true_block = label;
}

void Block::setNextFalse(string label)
{
	next_false_block = label;
}

void Block::setPreds1(string preds1)
{
	preds_1 = preds1;
}

void Block::setPreds2(string preds2)
{
	preds_2 = preds2;
}

void Block::setLastLine(int linenum)
{
	last_line_num = linenum;
}

void Block::setContent(string line)
{
	content.push_back(line);
}

void Block::cleanContent()
{
	content.clear();
}

void Block::showBlock()
{
	std::cout << "type:_" << type << std::endl;
	std::cout << "title and preds:_" << title << "_" << preds_1 << "_" << preds_2 << std::endl;		//should add the <string>, becasue 简单的说就是string头文件和iostream头文件都有对string类型的声明。
	//如果在程序中使用输入输出流iostream对string类型进行输入输出操作时程序就会报错。其原因在于iostream头文件中并没有重载与string类型相关的输入输出操作符，而该操作符的重载是在string头文件中实现的。
	std::cout << "next two:-----" << next_true_block << "-----" << next_false_block << std::endl;
	std::cout << "line num:~." << last_line_num << ".~" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < content.size(); i++) {
		std::cout << content[i] << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

Block::Block()
{
}


Block::~Block()
{
}

string Loop_cond_block::getRange()
{
	return range;
}
string Loop_cond_block::getRangeVar()
{
	return range_var;
}

void Loop_cond_block::setRange(string range)
{
	Loop_cond_block::range = range;
}

void Loop_cond_block::setRangeVar(string var)
{
	range_var = var;
}


string Loop_body_block::getPatternType()
{
	vector<std::string> bodycontent = Loop_body_block::getContent();
	return bodycontent[0];
}