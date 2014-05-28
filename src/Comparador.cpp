#include "Comparador.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;


Comparador::Comparador(){
	offset = 0;
}

void Comparador::menuInicial(){
	cout << endl <<
		"\t\t\t\t\t" << setfill('=') << setw(30) << "\n" <<
		"\t\t\t\t\t" << "==Similaridade de Ficheiros==" << "\n" <<
		"\t\t\t\t\t" << setfill('=') << setw(31) << "\n\n";

	for(int i=0; i<2; i++){
		if(i==0) cout << "Ficheiro original: ";
		else cout << "Ficheiro a comparar: ";

		string nomeFicheiro;
		getline(cin, nomeFicheiro);

		ifstream existFile(nomeFicheiro.c_str());
		if(existFile){
			existFile.close();
			if(i==0) this->original=nomeFicheiro.c_str();
			else this->copia=nomeFicheiro.c_str();
		}
		else{
			cout<<"\nEsse ficheiro não existe!\n";
			i--;
		}
	}
	return;
}

void Comparador::menuPrincipal(){
	bool display=true;
	string choice; //Recebe o input de escolha

	while(true){

		while (true) {
			if(display){
				cout << "\t\t\t\t\t" << "#Ficheiro original: " << this->original << "\n" <<
					"\t\t\t\t\t" << "#Ficheiro a comparar: " << this->copia << "\n";
				//cout << "\t\t\t\t\t" << "1.Alterar Ficheiros a Comparar\n";
				cout << "\t\t\t\t\t" << "1.Visualizar Diferenças.\n";
				cout << "\t\t\t\t\t" << "2.Quit\n\n";
				display=false;
			}
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1 && (choice == "1" || choice == "2"))
				break;
			cout << "Opção invalida, insira uma opção novamente.\n";
		}

		int option = atoi(choice.c_str());
		switch (option){
			/*case 1:
			alteraFicheiro();//alterar ficheiros a comparar
			display=true;
			break;*/
		case 1:
			//visualizar diferencas
			display=false;
			break;
		case 2:
			display=false;
			cout<<"O programa terminou.";
			return;
			break;
		}
	}
}

bool Comparador::start_of_diff()
{
	string line1,line2;
	ifstream new_file (copia);
	ifstream original_file (original);
	bool diff = false;
	if (new_file.is_open()){
		if (original_file.is_open())
		{
			while(getline(new_file,line1)){
				if(getline(original_file,line2))
				{
					if (!line1.compare(line2))
					{
						//the lines are the same
						offset++;
					} else {
						diff = true;
						break;
					}
				}
				else{
					diff = true;
					break;
				}
			}
			new_file.close();
			original_file.close();
			return diff;
		}
	}

