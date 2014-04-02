#include <iostream>
#include <stdlib.h>
#include "ThesisSolver.h"
#include <vector>
using namespace std;

int main (){
	
	ThesisSolver* solution =  new ThesisSolver();
	solution->readFile();

	cout<<solution->students.size()<<" nome "<<solution->students[0]->getName();


	cout<<"reading done!"<<endl;
	//system("pause");
return 1;
}
