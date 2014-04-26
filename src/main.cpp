#include <iostream>
#include <stdlib.h>
#include "ThesisSolver.h"
#include <vector>
using namespace std;

int main (){
	ThesisSolver* solution = new ThesisSolver();
	solution->readFile();
	//solution->menu();

	solution->atribuirTeses();

	vector<Entity *>::iterator it = solution->getStudents().begin();

	for(; it!=solution->getStudents().end(); it++)
	{
		cout<<(*it)->getName()<<" gosta ";
		if((*it)->getPair()!=NULL) cout<<(*it)->getPair()->getName()<<endl;
		else cout<<"NULL"<<endl;
	}

	solution->saveFile();

	cout<<"\nreading done!"<<endl;

return 1;
}
