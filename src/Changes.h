#ifndef _CHANGE_
#define _CHANGE_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Changes{
private:
	vector<string> lines;
	// 1 is add, 0 is remove
	vector<int> type;
	vector<int> line_numbers;
public:
	Changes();
	void add(string line, int type, int line_number);
	void print();
	vector<string> getLines();
	vector<int> getType();
	vector<int> getLine_numbers();
	};


#endif
