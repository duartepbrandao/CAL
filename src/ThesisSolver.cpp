/*
 * ThesisSolver.cpp
 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */
#include "ThesisSolver.h"

void ThesisSolver::readFile() {

	ifstream readFile; //read the content of a file
	string content; // temporary information string

	//start reading
	readFile.open("Preferencies Information.txt");

	if (readFile.fail()) {
		readFile.close();
		ofstream fileCreate("Preferencies Information.txt");
		fileCreate << "Students Information\n\n" << "Name\t" << "preferencies\n"
				<< "---------------------\n\n\n" << "Projects Information\n\n"
				<< "Name\t" << "preferencies\n" << "---------------------\n\n\n"
				<< "Supervisors Information\n\n" << "Name\t" << "preferencies\n"
				<< "---------------------\n";
		fileCreate.close();
		readFile.open("Preferencies Information.txt");
	}

	int phase = 1; //lecture phase: 1-Students, 2-Dissertations, 3-Supervisors

	while (true) {

		for (int i = 0; i < 4; i++) {
			getline(readFile, content);
		}

		while (content != "---------------------") {
			Supervisor* temp2 = new Supervisor();
			Entity* temp = new Entity();
			string name = content.substr(0, content.find('\t'));
			if (phase == 3) {
				temp2->setName(name);
			} else {
				temp->setName(name);
			}
			content.erase(0, content.find('\t') + 1);

			while (content.size() != 0) {
				int pos;

				if (content.find_first_of(',') < INT_MAX)
					pos = content.find(',');
				else
					pos = content.size();
				int pref = atoi(content.substr(0, pos).c_str());
				if (phase == 3) {
					temp2->addToPreferencesID(pref);
				} else {
					temp->addToPreferencesID(pref);
				}
				content.erase(0, pos + 1);
			}

			switch (phase) {
			case 1:
				students.push_back(temp);
				break;
			case 2:
				dissertations.push_back(temp);
				break;
			default: //case 3:
				supervisors.push_back(temp2);
				break;
			}
			if (phase == 3)
				break;
			getline(readFile, content);
		}
		if (phase == 3)
			break;
		phase++;
		getline(readFile, content);
		getline(readFile, content);
	}
}

vector<Entity*> & ThesisSolver::getStudents() {
	return students;
}

void ThesisSolver::setStudents(const vector<Entity*> &vec) {
	this->students = vec;
}

void ThesisSolver::menu() {
	cout << endl;
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "==" << "Organizador de Dissertações" << "=="
			<< "\n";
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "1.Mostrar Informação Atual\n";
	cout << "\t\t\t\t\t" << "2.Adicionar Estudantes\n";
	cout << "\t\t\t\t\t" << "3.Adicionar Projetos\n";
	cout << "\t\t\t\t\t" << "4.Adicionar Professor\n";
	cout << "\t\t\t\t\t" << "5.Guardar Informação Alterada\n";
	cout << "\t\t\t\t\t" << "6.Creditos\n";
	cout << "\t\t\t\t\t" << "7.Quit\n\n\n";

	//Recebe o input de escolha
	string choice = "";

	while (true) {
		cout << "Resposta: ";
		getline(cin, choice);
		if (choice.length() == 1
				&& (choice == "1" || choice == "2" || choice == "3"
						|| choice == "4" || choice == "5" || choice == "6"
						|| choice == "7"))
			break;
		cout << "Opção invalido, insira uma opção novamente." << endl;
	}
}

ThesisSolver::ThesisSolver() {

}

void ThesisSolver::solver1() {

}

bool ThesisSolver::checkEnd() {
	for (std::vector<Entity*> it = students.begin(); it != students.end();
			it++) {

	}
}
