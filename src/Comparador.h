#ifndef _COMPARADOR_
#define _COMPARADOR_

#include <string>
#include <vector>

using namespace std;

class Comparador{
private:
	string original, copia;
	int** matrix;
	vector <string> lcs;
public:
	Comparador();
	void menuInicial();
	void menuPrincipal();
	vector<string> sepFrases(string nome);
	vector<string> sepLinhas(string nome);
	void calcLCS(vector<string> original, vector<string> copia);
	void backTrack(vector<string> original, vector<string> copia, int i, int j);
	vector<string> getLCS();
};

#endif
