#ifndef _COMPARADOR_
#define _COMPARADOR_

#include <string>
#include <vector>

using namespace std;

class Comparador{
private:
	int offset;
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
	void alteraFicheiro();
	bool start_of_diff(); //returns true and sets the offset if the files are different
};

#endif
