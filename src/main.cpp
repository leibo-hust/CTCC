#include <iostream>
#include "functions.h"
#include "VarList.h"
#include "Insert.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Input file error" << endl;
		return 0;
	}
	string filename(argv[1]);
	// string filename = "mvm";
	readFile(filename);
	write_pattern(filename, patternlist);

	return 0;
}