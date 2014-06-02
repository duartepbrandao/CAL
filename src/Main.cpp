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
	//semelhanca->menuPrincipal();

	vector<string> lines = change->getLines();
	vector<int> type = change->getType();
	vector<int> line_number = change->getLine_numbers();

	cout << lines.size()<<endl<<
			type.size() <<endl<<
			line_number.size()<<endl;

	cout<<"Removido"<<endl;
	for(unsigned i=0; i<lines.size();i++){
		if(type[i]==0){cout<<line_number[i]+1; cout << "-";
		//else cout << "+";
		cout<<lines[i]<<endl;}
	}

	cout<<"Adicionado"<<endl;
	for(int i=lines.size()-1; i>-1;i--){
			if(type[i]==1){cout<<line_number[i]+1; cout << "+";
			//else cout << "+";
			cout<<lines[i]<<endl;}
		}

	return 1;
}
