#include "Comparador.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

Comparador::Comparador() {}

<<<<<<< HEAD
void Comparador::menuInicial() {

	vector<string> vecOrig = sepLinhas("original.txt");
	vector<string> vecCopia = sepLinhas("copia.txt");
=======
Comparador::Comparador(){
	offset = 0;
}

void Comparador::menuInicial(){
	cout << endl <<
		"\t\t\t\t\t" << setfill('=') << setw(30) << "\n" <<
		"\t\t\t\t\t" << "==Similaridade de Ficheiros==" << "\n" <<
		"\t\t\t\t\t" << setfill('=') << setw(31) << "\n\n";
>>>>>>> 8547e0b5148674f3b74dbead1d223dacbe10429f

	calcLCS(vecOrig,vecCopia);
	backTrack(vecOrig, vecCopia, vecOrig.size(), vecCopia.size());
	/*cout << endl << "\t\t\t\t\t" << setfill('=') << setw(30) << "\n"
			<< "\t\t\t\t\t" << "==Similaridade de Ficheiros==" << "\n"
			<< "\t\t\t\t\t" << setfill('=') << setw(31) << "\n\n";

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
	}*/
	return;
}

void Comparador::menuPrincipal() {
	bool display = true;
	string choice; //Recebe o input de escolha

	while (true) {
		while (true) {
<<<<<<< HEAD
			if (display) {
				cout << "\t\t\t\t\t" << "#Ficheiro original: " << this->original
						<< "\n" << "\t\t\t\t\t" << "#Ficheiro a comparar: "
						<< this->copia << "\n";
=======
			if(display){
				cout << "\t\t\t\t\t" << "#Ficheiro original: " << this->original << "\n" <<
					"\t\t\t\t\t" << "#Ficheiro a comparar: " << this->copia << "\n";
				//cout << "\t\t\t\t\t" << "1.Alterar Ficheiros a Comparar\n";
>>>>>>> 8547e0b5148674f3b74dbead1d223dacbe10429f
				cout << "\t\t\t\t\t" << "1.Visualizar Diferenças.\n";
				cout << "\t\t\t\t\t" << "2.Quit\n\n";
				display = false;
			}
			this->copia = "copia.txt";
			this->original = "original.txt";
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1 && (choice == "1" || choice == "2"))
				break;
			cout << "Opção invalida, insira uma opção novamente.\n";
		}

		int option = atoi(choice.c_str());
<<<<<<< HEAD
		switch (option) {
=======
		switch (option){
			/*case 1:
			alteraFicheiro();//alterar ficheiros a comparar
			display=true;
			break;*/
>>>>>>> 8547e0b5148674f3b74dbead1d223dacbe10429f
		case 1:
		{
			vector<string> vecOrig = sepLinhas(this->original);
			vector<string> vecCopia = sepLinhas(this->copia);
			calcLCS(vecOrig,vecCopia);
			backTrack(vecOrig, vecCopia, vecOrig.size(), vecCopia.size());
			display = true;
			break;
		}
		default: //case 2:
			display = false;
			cout << "O programa terminou.";
			return;
			break;
		}
	}
}

<<<<<<< HEAD
vector<string> Comparador::sepLinhas(string nome) {
	vector<string> todasLinhas;
	string linha;

	ifstream ficheiro(nome.c_str());
	while (!ficheiro.eof()) {
		getline(ficheiro, linha);
		todasLinhas.push_back(linha);
	}
	ficheiro.close();
	return todasLinhas;
}

vector<string> Comparador::sepFrases(string nome) {
	vector<string> todasFrases;
	string linha, frase;

	ifstream ficheiro(nome.c_str());
	while (!ficheiro.eof()) {
		getline(ficheiro, linha);

		unsigned pos = 0;
		while (pos < linha.size()) {
			pos = linha.find_first_of('.');
			if (pos < linha.size()) {
				frase += linha.substr(pos);
				linha = linha.substr(pos + 1, linha.size());
				todasFrases.push_back(frase);
				frase.clear();
			}
			frase += linha;
		}
	}
	todasFrases.push_back(frase); //pode-se ignorar caso o texto termine com um ponto final
	ficheiro.close();
	return todasFrases;
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

void Comparador::backTrack(vector<string> original, vector<string> copia, int i,
		int j) {
	if (i == 0 || j == 0) {
		return;
	} else if (original[i-1]==copia[j-1]) {
		backTrack(original, copia, i-1, j-1);
		lcs.push_back(original[i-1]);
		return;
	} else {
		if( matrix[i][j-1] > matrix[i-1][j] ) {
			return backTrack(original, copia, i, j-1);
		}
		else {
			return backTrack(original, copia, i-1, j);
=======
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
>>>>>>> 8547e0b5148674f3b74dbead1d223dacbe10429f
		}
	}
}

vector<string> Comparador::getLCS(){
	return this->lcs;
}

