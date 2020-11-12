#pragma once
#include <vector>

using namespace std;
/*class Pattern {

};*/

#include "Pattern.h"

class PatternList
{
private:
	vector<Pattern> patternlist;

public:
	void add(Pattern p);
	vector<Pattern> getPatterns();
	Pattern getPattern();
	int size();

	PatternList();
	~PatternList();
};

