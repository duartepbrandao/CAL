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

using namespace std;

class ThesisSolver {
private:

	std::vector<Entity*> supervisors;
	std::vector<Entity*> dissertations;

public:
	std::vector<Entity*> students;
	ThesisSolver();
	void readFile();
	void computeSolution();
};

#endif /* THESISSOLVER_H_ */
