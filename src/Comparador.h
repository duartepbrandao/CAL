#ifndef _COMPARADOR_
#define _COMPARADOR_

#include <string>

using namespace std;

class Comparador{
private:
	int offset;
	string original, copia;
public:
	Comparador();
	void menuInicial();
	void menuPrincipal();
	void alteraFicheiro();
	bool start_of_diff(); //returns true and sets the offset if the files are different
};

#endif
