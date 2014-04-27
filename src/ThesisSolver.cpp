#include "ThesisSolver.h"


ThesisSolver::ThesisSolver() {}

void ThesisSolver::setStudents(const vector<Student*> &vec) {
	this->students = vec;
}

vector<Student*> &ThesisSolver::getStudents() {
	return students;
}

vector<Dissertation*> &ThesisSolver::getDissertations() {
	return dissertations;
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
			Student* tempStu = NULL;
			Dissertation* tempDis = NULL;
			Supervisor* tempSup = NULL;

			string name = content.substr(0, content.find('\t'));

			switch (phase){
			case 1:
				tempStu=new Student();
				tempStu->setName(name);
				break;
			case 2:
				tempDis=new Dissertation();
				tempDis->setName(name);
				break;
			default:
				tempSup=new Supervisor();
				tempSup->setName(name);
				break;
			}

			content.erase(0, content.find('\t') + 1);

			while (content.size() != 0) {
				int pos;

				if (content.find_first_of(',') < INT_MAX) //encontrou a virgula
					pos = content.find(',');
				else pos = content.size(); //nao encontra a virgula, apenas existe mais uma preferencia

				int pref = atoi(content.substr(0, pos).c_str());
				switch (phase){
				case 1:
					tempStu->getPreferencesID().push_back(pref);
					break;
				case 2:
					tempDis->getPreferencesID().push_back(pref);
					break;
				default:
					tempSup->getPreferencesID().push_back(pref);
					break;
				}

				content.erase(0, pos + 1);
			}

			switch (phase) {
			case 1:
				students.push_back(tempStu);
				break;
			case 2:
				dissertations.push_back(tempDis);
				break;
			default: //case 3:
				int numberTasks = tempSup->getPreferencesID()[0];
				vector<unsigned int>::iterator it = tempSup->getPreferencesID().begin();
				tempSup->getPreferencesID().erase(it);
				for (int i = 0; i < numberTasks;i++)
					supervisors.push_back(tempSup);
				break;
			}
			getline(readFile, content);
		}
		if (phase == 3) break;
		phase++;
		getline(readFile, content);
		getline(readFile, content);
	}
}

void ThesisSolver::saveFile() {
	ofstream fileSave("Preferencies Saved.txt");

	fileSave << "Students Information\n\n" << "Name\t" << "preferencies\n";

	for(vector<Student*>::iterator it = students.begin(); it!=students.end(); it++){
		fileSave << (*it)->getName() << '\t';
		for(unsigned int i=0; i<(*it)->getPreferencesID().size(); i++){
			fileSave << (*it)->getPreferencesID()[i];
			if(i+1<(*it)->getPreferencesID().size()) fileSave << ",";
		}
		fileSave << endl;
	}

	fileSave << "---------------------\n\n\n" << "Projects Information\n\n" << "Name\t" << "preferencies\n";

	for(vector<Dissertation*>::iterator it = dissertations.begin(); it!=dissertations.end(); it++){
		fileSave << (*it)->getName() << '\t';
		for(unsigned int i=0; i<(*it)->getPreferencesID().size(); i++){
			fileSave << (*it)->getPreferencesID()[i];
			if(i+1<(*it)->getPreferencesID().size()) fileSave << ",";
		}
		fileSave << endl;
	}

	fileSave << "---------------------\n\n\n" << "Supervisors Information\n\n" << "Name\t" << "preferencies\n";

	for(vector<Supervisor*>::iterator it = supervisors.begin(); it!=supervisors.end(); it++){
		fileSave << (*it)->getName() << '\t';
		for(unsigned int i=0; i<(*it)->getPreferencesID().size(); i++){
			fileSave << (*it)->getPreferencesID()[i];
			if(i+1<(*it)->getPreferencesID().size()) fileSave << ",";
		}
		fileSave << endl;
	}

	fileSave << "---------------------\n";

	fileSave.close();
}


Student* ThesisSolver::getStudentByID(unsigned int id){
	vector<Student*>::iterator it;
	for( it = students.begin(); it!=students.end() ;it++) {
		if ((*it)->getID()==id)
			return (*it);
	}
	return NULL;
}

Dissertation* ThesisSolver::getDissertationsByID(unsigned int id){
	vector<Dissertation*>::iterator it;
	for( it = dissertations.begin(); it!=dissertations.end() ;it++) {
		if ((*it)->getID()==id)
			return (*it);
	}
	return NULL;
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


void ThesisSolver::atribuirTeses(){
	Student* aluno = checkEnd();

	while(aluno!=NULL){
		Dissertation * teseFavorita = getDissertationsByID((aluno)->getPreferencesID()[0]);
		if(!teseFavorita->getPairStu()){
			if(aluno->teseGostaAluno(teseFavorita)){
				aluno->setPair(teseFavorita);
				teseFavorita->setPairStu(aluno);
			}
			else aluno->getPreferencesID().erase(aluno->getPreferencesID().begin());
		}
		else{
			Student* alunoVencedor = desempata(teseFavorita->getPairStu(),aluno,teseFavorita);
			alunoVencedor->setPair(teseFavorita);
			teseFavorita->setPairStu(alunoVencedor);
		}
		aluno = checkEnd();
	}
}

Student* ThesisSolver::checkEnd() const{ //NULL se ja terminou
	for (vector<Student*>::const_iterator it = students.begin(); it != students.end(); it++) {
		if((*it)->getPair()==NULL && (*it)->getPreferencesID().size()!=0)
			return (*it);
	}
	return NULL;
}

Student* ThesisSolver::desempata(Student* aluno1, Student* aluno2, Dissertation* dissertacao){
	unsigned int id1 = aluno1->getID();
	unsigned int id2 = aluno2->getID();
	vector<unsigned int> preferencias = dissertacao->getPreferencesID();
	for(unsigned int i=0; i<preferencias.size(); i++){
		if(preferencias[i]==id1){
			aluno2->getPreferencesID().erase(aluno2->getPreferencesID().begin());
			return aluno1;
		}
		if(preferencias[i]==id2){
			aluno1->setPair(NULL);
			aluno1->getPreferencesID().erase(aluno1->getPreferencesID().begin());
			return aluno2;}
	}
	return NULL;
}

/*
void ThesisSolver::solver2(){
	//supervisor size > thesis size
	vector<vector<unsigned int> > matrix;

	for (unsigned int supIT= 0; supIT<supervisors.size();supIT++){
		for (unsigned int theIT = 0; theIT<supervisors.size();theIT++){
			int custo = INT_MAX;
			if (theIT<dissertations.size())
				int custo = (supervisors[supIT])->getCost(dissertations[theIT]);
			matrix[supIT].push_back(custo);
		}
	}
	subtractSmallestRow(matrix);
}

void ThesisSolver::convertIdsToEntitys(){
	vector<Student*>::iterator it;
	for ( it = students.begin(); it!=students.end();it++)
		for(unsigned int i = 0; i<(*it)->getPreferencesID().size();i++)
			(*it)->getPreferences().push_back(dissertations[i]);

	vector<Dissertation*>::iterator ita;
	for (ita = dissertations.begin(); ita != dissertations.end();ita++)
		for(unsigned int i = 0; i<(*ita)->getPreferencesID().size();i++)
			(*ita)->getPreferences().push_back(students[i]);

	vector<Supervisor*>::iterator it4;
	for (it4 = supervisors.begin(); it4 != supervisors.end(); it4++)
		for(unsigned int i = 0; i <(*it4)->getPreferencesID().size();i++)
			(*it4)->getPreferences().push_back(dissertations[i]);
}

void ThesisSolver::subtractSmallestRow(vector<vector<int> > &matrix ){
	vector <int> smallest;
	for (unsigned int j = 0; j < matrix.size(); j++){
		int smallestNumber = matrix[j][0];
		for (int i = 0; i < matrix[j].size();i++)
			if (matrix[j][i] < smallest)
				smallestNumber = matrix[j][i];
		smallest.push_back(smallestNumber);
	}

	for (int j = 0; j < smallest.size(); j++)
		for (int i = 0; i < matrix[j].size();i++)
			matrix[j][i] = matrix[j][i] - smallest[j];
}

void ThesisSolver::subtractSmallestColumn(vector<vector<int> > &matrix ){
	vector <int> smallest;
	for (unsigned int j = 0; j < supervisors.size(); j++){
		int smallestNumber = matrix[0][j];
		for (unsigned int i = 0; i < matrix[j].size();i++)
			if (matrix[i][j] < smallest)
				smallestNumber = matrix[i][j];
		smallest.push_back(smallestNumber);
	}
	for (unsigned int j = 0; j < dissertations.size(); j++)
		for (unsigned int i = 0; i < matrix[j].size();i++)
			matrix[i][j] = matrix[i][j] - smallest[i];
}
*/
