#include <iostream>
#include "functions.h"
#include "VarList.h"
#include "Insert.h"

using namespace std;

int main() {
	
	string filename = "mvm";
	filename = "./IR/" + filename;
	readFile(filename + ".ll");
	write_pattern(filename, patternlist);

	return 0;
}