/*
 * ThesisSolver.cpp
 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */
#include "ThesisSolver.h"

void ThesisSolver::readFile() {

	ifstream readFile; //read the content of a file
	string content; // temporary information string

	//start reading
	readFile.open("Preferencies Information.txt");

	if(readFile.fail()){
		readFile.close();
		ofstream fileCreate("Preferencies Information.txt");
		fileCreate <<"Students Information\n\n"
				<<"Name\t"<<"preferencies\n"
				<<"---------------------\n\n\n"
				<<"Projects Information\n\n"
				<<"Name\t"<<"preferencies\n"
				<<"---------------------\n\n\n"
				<<"Supervisors Information\n\n"
				<<"Name\t"<<"preferencies\n"
				<<"---------------------\n";
		fileCreate.close();
		readFile.open("Preferencies Information.txt");
	}

	int phase = 1; //lecture phase: 1-Students, 2-Dissertations, 3-Supervisors

	while (true){

		for(int i=0; i<4 ; i++){
			getline(readFile, content);
		}

		while (content!="---------------------") {

			Entity* temp = new Entity();

			string name = content.substr(0,content.find('\t'));
			temp->setName(name);

			content.erase(0,content.find('\t')+1);

			while(content.size()!=0){
				int pos;

				if(content.find_first_of(',')<100000)
					pos=content.find(',');
				else pos=content.size();

				int pref = atoi(content.substr(0,pos).c_str());
				temp->addToPreferencesID(pref);

				content.erase(0,pos+1);
			}

			switch (phase){
			case 1:
				students.push_back(temp);
				break;
			case 2:
				dissertations.push_back(temp);
				break;
			default: //case 3:
				supervisors.push_back(temp);
				break;
			}
			if(phase==3) break;
			getline(readFile, content);
		}
		if(phase==3) break;
		phase++;
		getline(readFile, content);
		getline(readFile, content);
	}
}

ThesisSolver::ThesisSolver() {

}

void ThesisSolver::computeSolution() {
	// TODO: Implement the solver
}

