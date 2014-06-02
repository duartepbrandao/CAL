#ifndef _CHANGE_
#define _CHANGE_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

//manipula toda a informacao relacionada com as diferencas/semelhancas
class Changes{
private:
	vector<string> lines, lines_equal; //lines-vector com as linhas diferentes, lines_equal-vector com as linhas iguas
	vector<int> type; // 1 is add, 0 is remove
	vector<int> line_numbers, line_numbers_equal; //line_numbers-vector com os numeros das linhas diferentes, numbers_Equal-vector com o numero das linhas em comum
	int offset; //primeiras n linhas em comum desde o inicio dos dois ficheiros
public:
	Changes();
	void add(string line, int type, int line_number); //adiciona dados importantes ao atributos relacionados com manipulacao das diferencas
	void print(); //imprime na consola e guarda num ficheiro todas diferencas/semelhanca entre ficheiros
	void setEqualOffset(vector<string> similar, int offset, vector<int> line_numbers); //atualiza os atributos relacionados as semelhancas
	void clearAttributes(); //coloca todos os atributos com valores nulos ou predefinidos a 0
};

#endif
