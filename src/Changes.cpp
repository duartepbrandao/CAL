#include "Changes.h"


Changes::Changes()
	{

	}

void Changes::add( string line, int type, int line_number )
	{
	lines.push_back(line);
	this->type.push_back(type);
	line_numbers.push_back(line_number);
	}

void Changes::print()
	{
	

	}
