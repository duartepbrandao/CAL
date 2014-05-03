#include <iostream>
#include <stdlib.h>
#include "ThesisSolver.h"
#include <vector>

using namespace std;

int main (){
	ThesisSolver* solution = new ThesisSolver();
	solution->readFiles();
	solution->menu();
	return 1;
}
