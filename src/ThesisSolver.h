/*
 * ThesisSolver.h

 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */

#ifndef THESISSOLVER_H_
#define THESISSOLVER_H_

#include "Supervisor.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include "graphviewer.h"

using namespace std;

class ThesisSolver {
private:
	vector<Entity*> students;
	vector<Entity*> dissertations;
	vector<Supervisor*> supervisors;

public:
	ThesisSolver();
	void assignVectors();
	void readFiles();
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
	void subtractSmallestRow(vector<vector<int> > & matrix);
	void subtractSmallestColumn(vector<vector<int> > & matrix );
	bool teseGostaAluno(Entity * aluno);
	int countStarred( vector<vector<int> >& matrix, vector<vector<int> > & mask, vector<int> & rowCover, vector<int>& colCover );
	void findZero( vector<vector<int> > & matrix, vector<vector<int> > & mask,vector<int> & rowCover, vector<int> & colCover );
	vector<Entity*> getStudents();
	void setStudents(vector<Entity*> vec);
	void visualizador();
	int prime( vector<vector<int> > &matrix, vector<vector<int> > &mask, vector<int> &rowCover, vector<int> &colCover, int &path_row0, int & path_col0 );
	void find_a_zero( int & row, int & col , vector<vector<int> > &matrix , vector<int> rowCover,vector<int> colCover);
	bool star_in_row( int row, vector<vector<int> > mask);
	void find_star_row( int row, int & col,vector<vector<int> > mask );
	int matching( vector<vector<int> > &mask, vector<int> &rowCover, vector<int> &colCover, int &path_row0, int &path_col0 );
	void find_star_col( vector<vector<int> > & mask, int path, int &r );
	void find_prime_row( vector<vector<int> > & mask, int path, int &c );
	void augment_path(int path_count, vector<vector<int> > & mask, vector <vector<int> > path);
	void clear_covers(int size, vector<int> &colCover, vector<int> &rowCover );
	void erase_primes(int size, vector<vector<int> > & mask);
	int adjustCost( vector<vector<int> > &matrix, vector<int> rowCover, vector<int> colCover );
	void find_smallest( int &min, vector<vector<int> > & matrix, vector<int> rowCover, vector<int> colCover );
	void printSolution1();
	void printSolution2();
	void print_matrix( vector<vector<int> > matrix );
};
#endif /* THESISSOLVER_H_ */
