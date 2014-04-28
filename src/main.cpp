#include <iostream>
#include <stdlib.h>
#include "ThesisSolver.h"
#include <vector>

using namespace std;

int main (){
	ThesisSolver* solution = new ThesisSolver();
	solution->readFiles();
	//solution->menu();

	solution->atribuirTeses();

	//solution->solver2();

	solution->printSolution1();

	//solution->solver2();

	solution->saveFile();
	solution->visualizador();

	cout<<"\nreading done!"<<endl;
	system("pause");

	return 1;
}
