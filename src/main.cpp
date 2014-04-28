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

	solution->solver2();
	//solution->printSolution1();

	//solution->saveFile();

	cout<<"\nreading done!"<<endl;
	system("pause");

return 1;
}
