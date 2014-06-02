#ifndef _COMPARADOR_
#define _COMPARADOR_

#include "Changes.h"

using namespace std;

class Comparador{
private:
	int offset, ** matrix;
	bool offsetFlag;
	string original, copia;
	vector <string> lcs;
	vector <int> linesEquals;
	Changes* change;
public:
	Comparador(Changes *change);
	void menuInicial();
	void menuPrincipal();
	vector<string> sepLinhas(string nome);
	void clearAttributes();
	bool start_of_diff(); //returns true and sets the offset if the files are different
	void calcLCS(vector<string> original, vector<string> copia);
	void backTrack(vector<string> original, vector<string> copia, int i, int j);
	void print_diff( vector<string> original, vector<string> copia, int i, int j);
	};

#endif
