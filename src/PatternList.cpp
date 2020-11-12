#include "PatternList.h"


void PatternList::add(Pattern p)
{
	patternlist.push_back(p);
}


vector<Pattern> PatternList::getPatterns()
{
	return patternlist;
}


Pattern PatternList::getPattern()
{
	Pattern p = patternlist.back();
	patternlist.pop_back();
	return p;
}

int PatternList::size()
{
	return patternlist.size();
}


PatternList::PatternList()
{
}


PatternList::~PatternList()
{
}
