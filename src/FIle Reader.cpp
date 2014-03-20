#include "File Reader.h"



bool fileReader(std::vector <Entity*> students, std::vector <Entity*> supervisors, std::vector <Entity*> dissertations){
	bool result=true;
	std::ifstream ins;
	std::string line;
	ins.open("db.txt");

	if (ins.is_open())
	{
		while (getline (ins,line)){

		}
	}

	ins.close();
	return result;
}
