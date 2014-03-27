#include "File Reader.h"
/*
* starts a new Entity
/ starts a new Entity type
*/

bool fileReader(std::vector <Entity*> students, std::vector <Entity*> supervisors, std::vector <Entity*> dissertations){
	bool result=true;
	std::ifstream ins;
	std::string line;
	int phase = 0;
	ins.open("db.txt");

	if (ins.is_open())
	{
		while (getline (ins,line)){
			getline(ins,line);
			while (!line.compare("/"))
			{	
			Entity* temp = new Entity();
			getline(ins,line);
			temp->setName(line);
			getline(ins,line);
			do {
				char * str = new char [line.length()+1];
				strcpy(str,line.c_str());
				int id;
				id = atoi(str);
				temp->addToPreferencesID(id);
				getline(ins,line);
				if ((line.compare("*") || line.compare("/")))
				{
					if ( phase == 0){
						students.push_back(temp);}
					else if (phase == 1)
					{
						dissertations.push_back(temp);
					}
					else {
						supervisors.push_back(temp);
					}
				}
			} while (!(line.compare("*") || line.compare("/")));

			}
			phase++;
		}
	}
	else
			std::cout<<"Could not find file!"<<std::endl;

	ins.close();
	return result;
}
