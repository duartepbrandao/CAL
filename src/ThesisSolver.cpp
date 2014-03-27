/*
 * ThesisSolver.cpp
 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */
#include "ThesisSolver.h"

bool ThesisSolver::readFile() {
	bool result = true;
	std::ifstream ins;
	std::string line;
	int phase = 1;
	ins.open("db.txt");
	int counter = 0;

	if (ins.is_open()) {
		while (getline(ins, line)) {
			std::cout << "read: " << counter << line << std::endl;
			counter++;
			getline(ins, line);
			std::cout << "read: " << counter << line << std::endl;
			counter++;
			while (!line.compare("/")) {
				std::cout << "read: " << counter << line << std::endl;
				counter++;
				Entity* temp = new Entity();
				getline(ins, line);
				std::cout << "read: " << counter << line << std::endl;
				counter++;
				temp->setName(line);
				getline(ins, line);
				std::cout << "read: " << counter << line << std::endl;
				counter++;
				do {
					char * str = new char[line.length() + 1];
					strcpy(str, line.c_str());
					int id;
					id = atoi(str);
					temp->addToPreferencesID(id);
					getline(ins, line);
					std::cout << "read: " << counter << line << std::endl;
					counter++;
					if ((line.compare("*") || line.compare("/"))) { //std::cout << phase;
						if (phase == 1) {
							std::cout <<"added" << temp->getName()<<std::endl;
							students.push_back(temp);
						} else if (phase == 2) {
							dissertations.push_back(temp);
						} else {
							supervisors.push_back(temp);
						}
					}
				} while (!(line.compare("*") || line.compare("/")));
				phase++;
			}
		}
	} else
		return result;
}

ThesisSolver::ThesisSolver() {

}

void ThesisSolver::computeSolution() {
	// TODO: Implement the solver
}

