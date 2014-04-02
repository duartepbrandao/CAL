#include <iostream>
#include <stdlib.h>
#include "ThesisSolver.h"
#include <vector>
using namespace std;

int main (){
	ThesisSolver* solution = new ThesisSolver();
	solution->readFile();
	solution->menu();

	cout<<"\nreading done!"<<endl;

	//cout<<solution->getStudents().size()<<" nome "<<solution->getStudents()[0]->getName();
	//system("pause");
return 1;
}
