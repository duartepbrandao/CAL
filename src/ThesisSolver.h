#ifndef THESISSOLVER_H_
#define THESISSOLVER_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>

#include "Student.h"
#include "Dissertation.h"
#include "Supervisor.h"

using namespace std;

class ThesisSolver {

private:
	vector<Student*> students;
	vector<Dissertation*> dissertations;
	vector<Supervisor*> supervisors;

public:
	ThesisSolver();

	void setStudents(const vector<Student*> &vec);

	vector<Student*> &getStudents();
	vector<Dissertation*> &getDissertations();

	void readFile();
	void saveFile();

	void menu();
	void gestaoAlunos();
	void gestaoDissertacoes();
	void gestaoSupervisores();

	Student* getStudentByID(unsigned int id);
	Dissertation* getDissertationsByID(unsigned int id);

	void atribuirTeses();
	Student* checkEnd() const;
	Student* desempata(Student* aluno1, Student* aluno2, Dissertation* thesis);


	void assignVectors();
	void convertIdsToEntitys();
	void solver2();
	void subtractSmallestRow(vector<vector<int> > & matrix);
	void subtractSmallestColumn(vector<vector<int> > & matrix );
};

#endif /* THESISSOLVER_H_ */
