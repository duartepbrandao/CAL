#ifndef _COMPARADOR_
#define _COMPARADOR_

#include <string>

using namespace std;

class Comparador{
private:
	string original, copia;
public:
	Comparador();
	void menuInicial();
	void menuPrincipal();
	void alteraFicheiro();
};

#endif
