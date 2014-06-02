#include "Comparador.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

Comparador::Comparador(Changes* change) : change(change) {
	offset = 0;
	offsetFlag=true;
}

void Comparador::menuInicial() {
	cout << "\t\t\t\t\t" << "=============================" << endl <<
			"\t\t\t\t\t" << "==Similaridade de Ficheiros==" << endl <<
			"\t\t\t\t\t" << "=============================" << "\n\n";

	for (int i = 0; i < 2; i++) {
		if (i == 0)
			cout << "Ficheiro original: ";
		else
			cout << "Ficheiro a comparar: ";

		string nomeFicheiro;
		getline(cin, nomeFicheiro);

		ifstream existFile(nomeFicheiro.c_str());
		if (existFile) {
			existFile.close();
			if (i == 0)
				this->original = nomeFicheiro.c_str();
			else
				this->copia = nomeFicheiro.c_str();
		} else {
			cout << "\nEsse ficheiro não existe!\n";
			i--;
		}
	}

	return;
}

void Comparador::menuPrincipal() {
	bool display = true;
	string choice; //Recebe o input de escolha

	while (true) {
		while (true) {
			if(display){
				cout << "\t\t\t\t\t" << "#Ficheiro original: " << this->original << endl;
				cout <<	"\t\t\t\t\t" << "#Ficheiro a comparar: " << this->copia << endl;
				cout << "\t\t\t\t\t" << "1.Visualizar Diferencas.\n";
				cout << "\t\t\t\t\t" << "2.Quit\n\n";
				display = false;
			}
			this->copia = "copia.txt";
			this->original = "original.txt";
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1 && (choice == "1" || choice == "2"))
				break;
			cout << "Opcao invalida, insira uma opcao novamente.\n";
		}

		int option = atoi(choice.c_str());

		switch (option){
		case 1:
		{
			if(start_of_diff()){
				vector<string> vecOrig = sepLinhas(original);
				vector<string> vecCopia = sepLinhas(copia);

				calcLCS(vecOrig,vecCopia);
				backTrack(vecOrig, vecCopia, vecOrig.size(), vecCopia.size());
				cout<<lcs.size()<<endl;
				print_diff(vecOrig, vecCopia, vecOrig.size(), vecCopia.size());

				change->setEqualOffset(lcs, offset, linesEquals);
				change->print();

				clearAttributes();
				display = true;
				break;
			}else {
				cout<<"Files are the same!"<<endl;
				return;
				break;
			}
		}
		default: //case 2:
			display = false;
			cout << "O programa terminou.";
			return;
			break;
		}
	}
}

vector<string> Comparador::sepLinhas(string nome) {
	vector<string> todasLinhas;
	string linha;

	ifstream ficheiro(nome.c_str());
	if(ficheiro){
		for (int i = 0; i<offset;i++)
		{
			getline(ficheiro,linha);
			if(offsetFlag) lcs.push_back(linha);
		}
		while (!ficheiro.eof()) {
			getline(ficheiro, linha);
			todasLinhas.push_back(linha);
		}
		offsetFlag=false;
	ficheiro.close();
	}
	else{
		cout << "Erro na leitura do ficheiro.";
		exit(1);
	}
	return todasLinhas;
}

void Comparador::clearAttributes(){
	this->offset=0;
	offsetFlag=true;

	for (unsigned i = 0; i <=sizeof(matrix[0]); i++)
		delete matrix[i];
	delete[] this->matrix;

	lcs.clear();
	linesEquals.clear();

	change->clearAttributes();
}

bool Comparador::start_of_diff() {
	string line1,line2;
	ifstream new_file (copia.c_str());
	ifstream original_file (original.c_str());

	bool diff = false;

	if (new_file.is_open()){
		if (original_file.is_open()) {

			while(!new_file.eof()){
				getline(new_file,line1);

				if(!original_file.eof())
				{
					getline(original_file,line2);
					if (!(line1.compare(line2)))
					{ //the lines are the same
						offset++;
						linesEquals.push_back(offset);
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
		}
	}
	new_file.close();
	original_file.close();
	return diff;
}

void Comparador::calcLCS(vector<string> original, vector<string> copia) {
	matrix = new int*[original.size()+1];
	for (unsigned i = 0; i <=original.size(); i++)
		matrix[i] = new int[copia.size()+1];

	for (unsigned i = 0; i <=original.size(); i++)
		matrix[i][0] = 0;
	for (unsigned j = 0; j <=copia.size(); j++)
		matrix[0][j] = 0;

	for (unsigned i = 1; i < original.size(); i++) {
		for (unsigned j = 1; j < copia.size(); j++) {
			if (original[i-1]==copia[j-1]) {
				matrix[i][j] = matrix[i-1][j-1] +1;
			} else {
				matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j]);
			}
		}
	}
}

void Comparador::backTrack(vector<string> original, vector<string> copia, int i, int j) {
	if (i == 0 || j == 0) {
		return;
	} else if (original[i-1]==copia[j-1]) {
		backTrack(original, copia, i-1, j-1);
		lcs.push_back(original[i-1]);
		linesEquals.push_back(i+offset);
		return;
	} else {
		if( matrix[i][j-1] > matrix[i-1][j] ) {
			return backTrack(original, copia, i, j-1);
		}
		else {
			return backTrack(original, copia, i-1, j);
		}
	}
}

void Comparador::print_diff( vector<string> original, vector<string> copia, int i, int j ) {
	if (i > 0 && j > 0 && (!original[i-1].compare(copia[j-1]))){
		print_diff(original,copia, i-1,j-1);
		//this did not changed
	} else {
		if (j > 0 && (i == 0 || matrix[i][j-1] >= matrix[i-1][j] ))
		{
			change->add(copia[j-1],1,j-1);
			print_diff(original,copia,i,j-1);
		}
		else{
			if (i>0 && (j==0 || (matrix[i][j-1] < matrix[i-1][j] )))
			{
				change->add(original[i-1],0,i-1);
				print_diff(original,copia,i-1,j);
			}
		}
	}
}
