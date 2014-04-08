/*
 * ThesisSolver.h

 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */

#ifndef THESISSOLVER_H_
#define THESISSOLVER_H_

#include <iostream>
#include "Entity.h"
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include "Supervisor.h"

using namespace std;

class ThesisSolver {
private:
	vector<Entity*> students;
	vector<Entity*> dissertations;
	vector<Supervisor*> supervisors;

public:
	vector<Entity*> &getStudents();
	void setStudents(const vector<Entity*> &vec);

	ThesisSolver();
	void readFile();
	void saveFile();
	void menu();
	void solver1();
	void checkEnd();
};

#endif /* THESISSOLVER_H_ */
