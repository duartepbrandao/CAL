/*
* ThesisSolver.cpp
*
*  Created on: 27 de Mar de 2014
*      Author: Utilizador
*/

#include "ThesisSolver.h"

Entity* ThesisSolver::getStudentByID(int id){
	vector<Entity*>::iterator it;
	for( it = students.begin(); it!=students.end() ;it++)
	{
		if ((*it)->getID()==id)
		{return (*it);
		}
	}
}

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
			if (phase == 3)
				temp2->setName(name);
			else temp->setName(name);

			content.erase(0, content.find('\t') + 1);

			while (content.size() != 0) {
				int pos;

				if (content.find_first_of(',') < INT_MAX) //encontrou a virgula
					pos = content.find(',');
				else pos = content.size(); //nao encontra a virgula, apenas existe mais uma preferencia

				int pref = atoi(content.substr(0, pos).c_str());
				if (phase == 3)
					temp2->addToPreferencesID(pref);
				else temp->addToPreferencesID(pref);

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
			if (phase == 3) break;
			getline(readFile, content);
		}
		if (phase == 3) break;
		phase++;
		getline(readFile, content);
		getline(readFile, content);
	}
}

void ThesisSolver::saveFile() {
	ofstream fileSave("Preferencies Information.txt");

	fileSave << "Students Information\n\n" << "Name\t" << "preferencies\n";

	for(vector<Entity*>::iterator it = students.begin(); it!=students.end(); it++){
		fileSave << (*it)->getName() << '\t';
		for(vector<int>::iterator it2 = (*it)->getPreferencesID().begin(); it2!=(*it)->getPreferencesID().begin(); it2++){
			fileSave << (*it2) << ",";
		}
		fileSave << endl;
	}

	fileSave << "---------------------\n\n\n" << "Projects Information\n\n" << "Name\t" << "preferencies\n";

	for(vector<Entity*>::iterator it = dissertations.begin(); it!=dissertations.end(); it++){
		fileSave << (*it)->getName() << '\t';
		for(vector<int>::iterator it2 = (*it)->getPreferencesID().begin(); it2!=(*it)->getPreferencesID().begin(); it2++){
			fileSave << (*it2) << ",";
		}
		fileSave << endl;
	}

	fileSave << "---------------------\n\n\n" << "Supervisors Information\n\n" << "Name\t" << "preferencies\n";

	for(vector<Supervisor*>::iterator it = supervisors.begin(); it!=supervisors.end(); it++){
		fileSave << (*it)->getName() << '\t';
		for(vector<int>::iterator it2 = (*it)->getPreferencesID().begin(); it2!=(*it)->getPreferencesID().begin(); it2++){
			fileSave << (*it2) << ",";
		}
		fileSave << endl;
	}

	fileSave << "---------------------\n";

	fileSave.close();
}

vector<Entity*> & ThesisSolver::getStudents() {
	return students;
}

void ThesisSolver::setStudents(const vector<Entity*> &vec) {
	this->students = vec;
}

void ThesisSolver::menu() {
	bool display=true;
	string choice = ""; //Recebe o input de escolha

	while(true){

		while (true) {
			if(display){
				cout << endl;
				cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
				cout << "\t\t\t\t\t" << "==" << "Organizador de Dissertações" << "=="
					<< "\n";
				cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
				cout << "\t\t\t\t\t" << "1.Gestao de Alunos\n";
				cout << "\t\t\t\t\t" << "2.Gestao de Dissertacoes\n";
				cout << "\t\t\t\t\t" << "3.Gestao de Supervisores\n";
				cout << "\t\t\t\t\t" << "4.Atribuicao de Alunos a Dissertacoes\n";
				cout << "\t\t\t\t\t" << "5.Atribuicao de Supervisores a Dissertacoes\n";
				cout << "\t\t\t\t\t" << "6.Visualizacao do Grafo.\n";
				cout << "\t\t\t\t\t" << "7.Quit\n\n\n";
				display=false;
			}
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1
				&& (choice == "1" || choice == "2" || choice == "3"
				|| choice == "4" || choice == "5" || choice == "6"
				|| choice == "7"))
				break;
			cout << "Opção invalido, insira uma opção novamente." << endl;
		}

		int option = atoi(choice.c_str());

		switch (option){
		case 1:
			gestaoAlunos();
			display=true;
			break;
		case 2:
			gestaoDissertacoes();
			display=true;
			break;
		case 3:
			gestaoSupervisores();
			display=true;
			break;
		case 4:
			cout<<"por implementar"<<endl;
			display=true;
			break;
		case 5:
			cout<<"por implementar"<<endl;
			display=true;
			break;
		case 6:
			cout<<"por implementar"<<endl;
			display=true;
			break;
		default:
			return;
		}
	}
}

ThesisSolver::ThesisSolver() {

}

void ThesisSolver::solver1() {

}
/*
void ThesisSolver::checkEnd() {
for (vector<Entity*>::iterator it = students.begin(); it != students.end(); it++) {

}
}*/

void ThesisSolver::gestaoAlunos(){
	cout << endl;
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "==" << "Gestao de Alunos" << "=="
		<< "\n";
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "1.Adiciona Aluno\n";
	cout << "\t\t\t\t\t" << "2.Edita Aluno\n";
	cout << "\t\t\t\t\t" << "3.Remove Aluno\n";
	cout << "\t\t\t\t\t" << "4.Voltar ao MenuPrincipal\n";

	//Recebe o input de escolha
	string choice = "";

	while(true){

		while (true) {
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1
				&& (choice == "1" || choice == "2" || choice == "3"
				|| choice == "4"))
				break;
			cout << "Opção invalido, insira uma opção novamente." << endl;
		}

		int option = atoi(choice.c_str());

		switch (option){
		case 1:
			cout<<"por implementar\n";
			system("cls");
			break;
		case 2:
			cout<<"por implementar\n";
			break;
		case 3:
			cout<<"por implementar\n";
			break;
		default:
			return;
		}
	}
}

void ThesisSolver::gestaoDissertacoes(){
	cout << endl;
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "==" << "Gestao de Dissertacoes" << "=="
		<< "\n";
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "1.Adiciona Dissertacao\n";
	cout << "\t\t\t\t\t" << "2.Edita Dissertacao\n";
	cout << "\t\t\t\t\t" << "3.Remove Dissertacao\n";
	cout << "\t\t\t\t\t" << "4.Voltar ao MenuPrincipal\n";

	//Recebe o input de escolha
	string choice = "";

	while(true){

		while (true) {
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1
				&& (choice == "1" || choice == "2" || choice == "3"
				|| choice == "4"))
				break;
			cout << "Opção invalido, insira uma opção novamente." << endl;
		}

		int option = atoi(choice.c_str());

		switch (option){
		case 1:
			cout<<"por implementar\n";
			break;
		case 2:
			cout<<"por implementar\n";
			break;
		case 3:
			cout<<"por implementar\n";
			break;
		default:
			return;
		}
	}
}

void ThesisSolver::gestaoSupervisores(){
	cout << endl;
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "==" << "Gestao de Dissertacoes" << "=="
		<< "\n";
	cout << "\t\t\t\t\t" << setfill('=') << setw(32) << "\n";
	cout << "\t\t\t\t\t" << "1.Adiciona Supervisor\n";
	cout << "\t\t\t\t\t" << "2.Edita Supervisor\n";
	cout << "\t\t\t\t\t" << "3.Remove Supervisor\n";
	cout << "\t\t\t\t\t" << "4.Voltar ao MenuPrincipal\n";

	//Recebe o input de escolha
	string choice = "";

	while(true){

		while (true) {
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1
				&& (choice == "1" || choice == "2" || choice == "3"
				|| choice == "4"))
				break;
			cout << "Opção invalido, insira uma opção novamente." << endl;
		}

		int option = atoi(choice.c_str());

		switch (option){
		case 1:
			cout<<"por implementar\n";
			break;
		case 2:
			cout<<"por implementar\n";
			break;
		case 3:
			cout<<"por implementar\n";
			break;
		default:
			return;
		}
	}
};

void ThesisSolver::solver2()
{//supervisor size > thesis size

	vector<vector<int>> matrix;
	for (int theIT = 0; theIT<dissertations.size();theIT++)
	{
		for (int supIT= 0; supIT<supervisors.size();supIT++)
		{
			int custo = (supervisors[supIT])->getCost(dissertations[theIT]);
			matrix[theIT].push_back(custo);
		}
	}
	subtractSmallestRow(matrix);
}


void ThesisSolver::convertIdsToEntitys()
{
	vector<Entity*>::iterator it;
	for ( it = students.begin(); it!=students.end();it++)
	{
		for(int i = 0; i<(*it)->getPreferencesID().size();i++){
			(*it)->addToPreferences(dissertations[i]);
		}
	}
	vector<Entity*>::iterator ita;
	for (ita = dissertations.begin(); ita != dissertations.end();ita++)
	{
		for(int i = 0; i<(*ita)->getPreferencesID().size();i++){
			(*ita)->addToPreferences(students[i]);
		}
	}
	vector<Supervisor*>::iterator it4;
	for (it4 = supervisors.begin(); it4 != supervisors.end(); it4++)
	{
		for(int i = 0; i <(*it4)->getPreferencesID().size();i++){
			(*it4)->addToPreferences(dissertations[i]);
		}
	}
}

void ThesisSolver::subtractSmallestRow(vector<vector<int>> & matrix )
{	vector <int> smallest;
	for (int j = 0; j < matrix.size(); j++);
	{
		int smallestNumber = matrix[j][0];
		for (int i = 0; i < matrix[j].size();i++)
		{
			if (matrix[j][i] < smallest)
			{
				smallestNumber = matrix[j][i];
			}
		}
		smallest.push_back(smallestNumber);
	}

	for (int j = 0; j < matrix.size(); j++)
	{
		for (int i = 0; i < matrix[j].size();i++)
		{
			matrix[j][i] = matrix[j][i] - smallest[j];
		}
	}
}

void ThesisSolver::subtractSmallestColumn(vector<vector<int>> & matrix )
{	
	vector <int> smallest;
	for (int j = 0; j < supervisors.size(); j++);
	{
		int smallestNumber = matrix[0][j];
		for (int i = 0; i < matrix[j].size();i++)
		{
			if (matrix[i][j] < smallest)
			{
				smallestNumber = matrix[j][i];
			}
		}
		smallest.push_back(smallestNumber);
	}

	for (int j = 0; j < matrix.size(); j++)
	{
		for (int i = 0; i < matrix[j].size();i++)
		{
			matrix[j][i] = matrix[j][i] - smallest[j];
		}
	}
}


