#ifndef _COMPARADOR_
#define _COMPARADOR_

#include "Changes.h"

using namespace std;

class Comparador{
private:
	int offset;
	string original, copia;
	int** matrix;
	vector <string> lcs;
	Changes* change;
public:
	Comparador(Changes *change);
	void menuInicial();
	void menuPrincipal();
	vector<string> sepFrases(string nome);
	vector<string> sepLinhas(string nome);
	void calcLCS(vector<string> original, vector<string> copia);
	void backTrack(vector<string> original, vector<string> copia, int i, int j);
	vector<string> getLCS();
	void alteraFicheiro();
	bool start_of_diff(); //returns true and sets the offset if the files are different
	void print_diff( vector<string> original, vector<string> copia, int i, int j);
	};

#endif
