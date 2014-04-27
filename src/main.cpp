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
	cout <<"it";
	vector<Entity*>::iterator it = solution->getStudents().begin();
	cout<<solution->getStudents().size()<<endl;

	solution->printSolution1();

	cout <<"it2";
	cout<<"end";
	//solution->saveFile();

	cout<<"\nreading done!"<<endl;

return 1;
}
