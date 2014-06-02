#ifndef _CHANGE_
#define _CHANGE_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Changes{
private:
	vector<string> lines, lines_equal;
	vector<int> type; // 1 is add, 0 is remove
	vector<int> line_numbers, line_numbers_equal;
	int offset;
public:
	Changes();
	void add(string line, int type, int line_number);
	void print();
	void setEqualOffset(vector<string> similar, int offset, vector<int> line_numbers);
	void clearAttributes();
};

#endif
