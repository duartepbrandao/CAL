#include "Comparador.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;


Comparador::Comparador(){}

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

/*void Comparador::alteraFicheiro(){
	bool exibir=true, terminar=false;
	string choice = ""; //Recebe o input de escolha

	while(!terminar){
		while(true){
			if(exibir){
				cout << "\t\t\t\t\t" << "Alterar o ficheiro:\n" <<
						"\t\t\t\t\t" << "1. Original\n" <<
						"\t\t\t\t\t" << "2. Copia\n" <<
						"\t\t\t\t\t" << "3. Voltar ao menu principal\n" <<
						"Indique a opção desejada: ";
				getline(cin, choice);
				if (choice == "1" || choice == "2" || choice == "3")
					break;
				cout << "Opção invalida, insira uma opção novamente." << endl;
			}
		}

		switch (atoi(choice.c_str())){
		case 1:
		{
			string nomeFicheiro = "";
			cout << "Novo ficheiro original: ";
			getline(cin, nomeFicheiro);
			ifstream existFile(nomeFicheiro.c_str());
			if(existFile){
				existFile.close();
				this->original=nomeFicheiro.c_str();
			} else cout<<"Esse ficheiro não existe!\n\n";
			break;
		}
		case 2:
		{
			string nomeFicheiro = "";
			cout << "Novo ficheiro a comparar:";
			getline(cin, nomeFicheiro);
			ifstream existFile(nomeFicheiro.c_str());
			if(existFile) {
				existFile.close();
				this->copia=nomeFicheiro.c_str();
			} else cout<<"Esse ficheiro não existe!\n\n";
			break;
		}
		default: //case 3
			terminar=true;
			break;
		}
	}

	return;
}*/
