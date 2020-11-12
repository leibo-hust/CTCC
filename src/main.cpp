#include <iostream>
#include "functions.h"
#include "VarList.h"
#include "Insert.h"

using namespace std;

int main() {
	//string filename = "bitmap_test";
	//string filename = "mvm_test";
	//string filename = "slt_d";
	//string filename = "bitmap_de";
	//string filename = "slt_d";
	//string filename = "mvmde";
	//string filename = "mmm_d";
	string filename = "mmm_de";
	//string filename = "test_range_var";
	//string filename = "slt_d_var";
	//string filename = "test_rangevar";

	readFile(filename+".ll");
	write_pattern(filename, patternlist);
	//listtest();


	return 0;
}