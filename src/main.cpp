#include <iostream>
#include <stdlib.h>
#include "ThesisSolver.h"
#include <vector>
using namespace std;

int main (){
	ThesisSolver* solution = new ThesisSolver();
	solution->readFile();
	solution->menu();
	//solution->saveFile();

	cout<<"\nreading done!"<<endl;

return 1;
}
