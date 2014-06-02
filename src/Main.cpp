#include "Comparador.h"
#include "Changes.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	Changes* change = new Changes();
	Comparador* semelhanca = new Comparador(change);
	semelhanca->menuInicial();
	semelhanca->menuPrincipal();
	return 1;
}
