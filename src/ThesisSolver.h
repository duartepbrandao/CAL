/*
 * ThesisSolver.h

 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */

#ifndef THESISSOLVER_H_
#define THESISSOLVER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
	void assignVectors();
	void readFile();
	void saveFile();
	void menu();
	void solver1();
	Entity * checkEnd();
	void gestaoAlunos();
	void gestaoDissertacoes();
	Entity* getStudentByID(int id);
	void gestaoSupervisores();
	Entity* getDissertationsByID(int id);
	void atribuirTeses();
	Entity* desempata(Entity* aluno1, Entity* aluno2, Entity* dissertacao);
	void convertIdsToEntitys();
	void solver2();
	void subtractSmallestRow(vector<vector<int>> & matrix);
	void subtractSmallestColumn(vector<vector<int>> & matrix );
	bool teseGostaAluno(Entity * aluno);
};

#endif /* THESISSOLVER_H_ */
