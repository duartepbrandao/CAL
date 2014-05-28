#include "Comparador.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	Comparador* semelhanca = new Comparador();
	semelhanca->menuInicial();
	//semelhanca->menuPrincipal();
	vector<string> resultado = semelhanca->getLCS();

	for(unsigned i=0; i<resultado.size(); i++)
		cout<<resultado[i]<<endl;

	return 1;
}
