#include <iostream>
#include <stdlib.h>
#include "File Reader.h"
#include <vector>
using namespace std;

int main (){
	vector <Entity*> students;
	vector <Entity*> supervisors;
	vector <Entity*> dissertations;
	

	fileReader(students,supervisors,dissertations);

	return 1;
}
