/*
 * ThesisSolver.cpp
 *
 *  Created on: 27 de Mar de 2014
 *      Author: Utilizador
 */

#include "ThesisSolver.h"

ThesisSolver::ThesisSolver() {}

vector<Entity*> ThesisSolver::getStudents() {
	return students;
}

void ThesisSolver::setStudents(vector<Entity*> vec) {
	this->students = vec;
}


Entity* ThesisSolver::getStudentByID(int id){
	vector<Entity*>::iterator it;
	for( it = students.begin(); it!=students.end() ;it++) {
		if ((*it)->getID()==id)
			return (*it);
	}
	return NULL;
}

Entity* ThesisSolver::getDissertationsByID(int id){
	vector<Entity*>::iterator it;
	for( it = dissertations.begin(); it!=dissertations.end() ;it++) {
		if ((*it)->getID()==id)
			return (*it);
	}
	return NULL;
}

void ThesisSolver::convertIdsToEntitys()
{
	vector<Entity*>::iterator it;
	for ( it = students.begin(); it!=students.end();it++)
	{
		for(unsigned i = 0; i<(*it)->getPreferencesID().size();i++){
			(*it)->addToPreferences(dissertations[i]);
		}
	}
	vector<Entity*>::iterator ita;
	for (ita = dissertations.begin(); ita != dissertations.end();ita++)
	{
		for(unsigned i = 0; i<(*ita)->getPreferencesID().size();i++){
			(*ita)->addToPreferences(students[i]);
		}
	}
	vector<Supervisor*>::iterator it4;
	for (it4 = supervisors.begin(); it4 != supervisors.end(); it4++)
	{
		for(unsigned i = 0; i <(*it4)->getPreferencesID().size();i++){
			(*it4)->addToPreferences(dissertations[i]);
		}
	}
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
				cout << "\t\t\t\t\t" << "1.Atribuir Alunos a dissertações\n";
				cout << "\t\t\t\t\t" << "2.Atribuir Supervisores a dissertações\n";
				cout << "\t\t\t\t\t" << "3.Visualizador do Grafo.\n";
				cout << "\t\t\t\t\t" << "4.Quit\n\n\n";
				display=false;
			}
			cout << "Indique a opcao desejada: ";
			getline(cin, choice);
			if (choice.length() == 1 && (choice == "1" || choice == "2" || choice == "3" || choice == "4"))
				break;
			cout << "Opção invalido, insira uma opção novamente." << endl;
		}

		int option = atoi(choice.c_str());

		switch (option){
		case 1:
			atribuirTeses();
			display=false;
			break;
		case 2:
			solver2();
			display=false;
			break;
		case 3:
			saveFile();
			visualizador();
			display=false;
			break;
		default:
			return;
		}
	}
}

void ThesisSolver::readFiles() {

	ifstream readFile; //read the content of a file
	string content; // temporary information string

	//start reading
	readFile.open("Preferencies Information.txt");

	if (readFile.fail()) {
		readFile.close();
		ofstream fileCreate("Preferencies Information.txt");
		fileCreate << "Students Information\n\n" << "Name\tpreferencies\n"
				<< "---------------------\n\n\n" << "Projects Information\n\n"
				<< "Name\t" << "preferencies\n" << "---------------------\n\n\n"
				<< "Supervisors Information\n\n" << "Name\tTasks\tpreferencies\n"
				<< "---------------------\n";
		fileCreate.close();
		readFile.open("Preferencies Information.txt");
	}

	unsigned phase = 1; //lecture phase: 1-Students, 2-Dissertations, 3-Supervisors

	while (true) {

		for (int i = 0; i < 4; i++) {
			getline(readFile, content);
		}

		while (content != "---------------------") {
			Supervisor* temp2 = NULL;
			Entity* temp = NULL;
			int tasks;

			string name = content.substr(0, content.find('\t'));
			if (phase == 3){
				temp2=new Supervisor();
				temp2->setName(name);
			}
			else{
				temp=new Entity();
				temp->setName(name);
			}

			content.erase(0, content.find('\t') + 1);

			if(phase==3)
				tasks = atoi(content.substr(0, content.find('\t')).c_str());

			while (content.size() != 0) {
				int pos;

				if (content.find_first_of(',') < INT_MAX) //encontrou a virgula
					pos = content.find(',');
				else pos = content.size(); //nao encontra a virgula, apenas existe mais uma preferencia

				int pref = atoi(content.substr(0, pos).c_str());
				if (phase == 3)
					temp2->addToPreferencesID(pref+students.size());
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
				for (int i = 0; i < tasks; i++)
					supervisors.push_back(temp2);
				break;
			}
			getline(readFile, content);
		}
		if (phase == 3) break;
		if (phase == 1){
			vector<Entity *>::iterator it = students.begin();
			for(;it!=students.end();it++)
				for(unsigned i=0; i<(*it)->getPreferencesID().size(); i++)
					(*it)->getPreferencesID()[i]+=students.size();
		}
		phase++;
		getline(readFile, content);
		getline(readFile, content);
	}
	readFile.close();
}

void ThesisSolver::saveFile() {
	ofstream fileSave("Preferencies Saved.txt");

	fileSave << students.size() << "," << dissertations.size() << "," << 0 << endl;

	for(vector<Entity*>::iterator it = students.begin(); it!=students.end(); it++){
		fileSave << (*it)->getName() << '\t';
		if((*it)->getPair()!=NULL) fileSave << (*it)->getPair()->getID();
		else fileSave << "0";
		fileSave << endl;
	}

	for(vector<Entity*>::iterator it = dissertations.begin(); it!=dissertations.end(); it++){
		fileSave << (*it)->getName() << '\t';
		if((*it)->getPair()!=NULL) fileSave << (*it)->getPair()->getID();
		else fileSave << "0";
		fileSave << endl;
	}

	/*for(vector<Entity*>::iterator it = supervisors.begin(); it!=supervisors.end(); it++){
			fileSave << (*it)->getName() << '\t';
			if((*it)->getPair()!=NULL) fileSave << (*it)->getPair()->getID();
			else fileSave << "0";
			fileSave << endl;
		}*/

	fileSave.close();
}

void ThesisSolver::visualizador() {
	GraphViewer *gv = new GraphViewer(1000, 1000, false);
	gv->createWindow(1000, 1000);
	gv->defineEdgeColor("black");

	ifstream readFile; //read the content of a file
	string content; // temporary information string
	vector<int> prefes;

	//start reading
	readFile.open("Preferencies Saved.txt");



	if (readFile.fail())
		readFile.close();

	else{
		int numEnt[3], numE=0, idNo=1, X=100, Y=100, phase=1;

		getline(readFile,content,',');
		numEnt[0]=atoi(content.c_str());
		getline(readFile,content,',');
		numEnt[1]=atoi(content.c_str());
		getline(readFile,content);
		numEnt[2]=atoi(content.c_str());

		for(int j=1; j<4; j++){
			Y=100*j;
			for(int i=1; i<numEnt[numE]+1; i++){
				//guarda dados do ficheiro
				getline(readFile, content);
				string name = content.substr(0, content.find('\t'));
				content.erase(0, content.find('\t') + 1);

				int pos;
				if (content.find_first_of(',') < INT_MAX)
					pos = content.find(',');
				else pos = content.size();

				if(content.size() != 0)
					prefes.push_back(atoi(content.substr(0, pos).c_str()));
				else prefes.push_back(0);
				//guardou os dados relativos ao primeiro

				X=100*i;
				gv->addNode(idNo,Y,X);
				switch(phase){
				case 1:
					gv->setVertexColor(idNo, "red");
					break;
				case 2:
					gv->setVertexColor(idNo, "blue");
					break;
				default:
					gv->setVertexColor(idNo, "green");
					break;
				}
				gv->setVertexLabel(idNo, name);
				idNo++;
			}
			phase++;
			numE++;
		}

		numE=0; phase=1; idNo=1;
		for(int j=1; j<4; j++){
			for(int i=1; i<numEnt[numE]+1; i++){
				if(prefes[idNo-1]!=0)
					gv->addEdge(idNo,idNo,prefes[idNo-1], EdgeType::UNDIRECTED);
				switch(phase){
				case 1:
					gv->setEdgeColor(idNo, "red");
					break;
				case 2:
					gv->setEdgeColor(idNo, "blue");
					break;
				default:
					gv->setEdgeColor(idNo, "green");
					break;
				}
				idNo++;
			}
			phase++;
			numE++;
		}
	}

	readFile.close();

	gv->rearrange();
}


void ThesisSolver::atribuirTeses(){
	Entity * aluno = checkEnd();

	while(aluno!=NULL){
		Entity * teseFavorita = getDissertationsByID((aluno)->getPreferencesID()[0]);

		if(!teseFavorita->isPaired()){
			if(aluno->teseGostaAluno(teseFavorita)){
				aluno->setPair(teseFavorita);
				teseFavorita->setPair(aluno);
			}
			else aluno->getPreferencesID().erase(aluno->getPreferencesID().begin());
		}
		else{
			Entity * alunoVencedor = desempata(teseFavorita->getPair(),aluno,teseFavorita);
			alunoVencedor->setPair(teseFavorita);
			teseFavorita->setPair(alunoVencedor);
		}
		aluno = checkEnd();
	}
}

Entity * ThesisSolver::checkEnd() { //true se ainda nao terminou
	for (vector<Entity*>::iterator it = students.begin(); it != students.end(); it++) {
		if((*it)->isPaired()==false && (*it)->getPreferencesID().size()>0)
			return (*it);
	}
	return NULL;
}

Entity * ThesisSolver::desempata(Entity* aluno1, Entity* aluno2, Entity* dissertacao){
	int id1 = aluno1->getID();
	int id2 = aluno2->getID();
	vector<int> preferencias = dissertacao->getPreferencesID();
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


void ThesisSolver::solver2()
{
	//supervisor size > thesis size
	//line supervisor, column task

	vector<vector<int> > matrix;
	vector<vector<int> > mask;
	convertIdsToEntitys();
	vector <int> rowCover,colCover;
	int step = 0;
	int path_col0, path_row0;
	bool done = false;
	vector<int> mask_line;
	vector<int> matrix_line;

	for (unsigned supIT= 0; supIT<supervisors.size();supIT++){
		rowCover.push_back(0);
		colCover.push_back(0);

		for (unsigned theIT = 0; theIT<supervisors.size();theIT++)
		{
			int custo = INT_MAX;
			if (theIT<dissertations.size())
				custo = (supervisors[supIT])->getCost(dissertations[theIT]);
			mask_line.push_back(0);
			matrix_line.push_back(custo);
		}
		matrix.push_back(matrix_line);
		mask.push_back(mask_line);
		matrix_line.clear();
		mask_line.clear();
	}
	print_matrix(matrix);
	subtractSmallestRow(matrix);

	findZero(matrix,mask, rowCover,colCover);
int i=0;
	while(!done){
		i++;
		switch(step){
		case 0:
			step = countStarred(matrix,mask,rowCover,colCover);
			break;
		case 1:
			//end
			done = true;
			break;
		case 2:
			step = prime(matrix,mask,rowCover,colCover,path_row0,path_col0);
			break;
		case 3:
			step = matching(mask, rowCover,colCover,path_row0,path_col0);
			break;
		case 4:
			step = adjustCost(matrix, rowCover,colCover);
			break;
		}
	}

	//solution is in mask;
	for (unsigned r = 0; r < mask.size(); r++)
	{
		for (unsigned c = 0; c < mask.size(); c++)
		{	//if mask [c][r] == 1, thats the solution
			if (mask[c][r]==1)
			{
				cout<<supervisors[c]->getName()<<" com " <<dissertations[r]->getName()<<endl;
				(supervisors[c])->setPair(dissertations[r]);
			}
		}
	}
}

void ThesisSolver::subtractSmallestRow(vector<vector<int> > & matrix ){
	vector <int> smallest;
	for (unsigned j = 0; j < matrix.size(); j++)
	{
		int smallestNumber = matrix[j][0];
		for (unsigned i = 0; i < matrix[j].size();i++)
		{
			int compare1 = (matrix[j][i]);
			int compare2 = smallestNumber;
			if (compare1 < compare2)
				smallestNumber = matrix[j][i];
		}
		smallest.push_back(smallestNumber);
	}
	for (unsigned j = 0; j < smallest.size(); j++)
		for (unsigned i = 0; i < matrix[j].size();i++)
			matrix[j][i] = matrix[j][i] - smallest[j];
}

void ThesisSolver::subtractSmallestColumn(vector<vector<int> > & matrix )
{	
	vector <int> smallest;
	for (unsigned j = 0; j < supervisors.size(); j++)
	{
		int smallestNumber = matrix[0][j];
		for (unsigned i = 0; i < matrix[j].size();i++)
		{
			//if ((matrix[i][j]) < smallest)
			{
				smallestNumber = matrix[i][j];
			}
		}
		smallest.push_back(smallestNumber);
	}
	for (unsigned j = 0; j < dissertations.size(); j++)
		for (unsigned i = 0; i < matrix[j].size();i++)
			matrix[i][j] = matrix[i][j] - smallest[i];
}

void ThesisSolver::findZero( vector<vector<int> > & matrix, vector<vector<int> > & mask,vector<int> & rowCover, vector<int> & colCover )
{	
	for (unsigned r = 0; r < matrix.size();r++)
		for (unsigned col = 0; col<matrix.size();col++)
			if(matrix[r][col] == 0 && rowCover[r] == 0 && colCover[col] == 0){
				mask[r][col] = 1;
				rowCover[r] = 1;
				colCover[col] = 1;
			}
	clear_covers(matrix.size(),colCover,rowCover);
}

int ThesisSolver::countStarred( vector<vector<int> >& matrix, vector<vector<int> > & mask, vector<int> & rowCover, vector<int>& colCover)
{
	unsigned colcount = 0;
	for (unsigned r = 0; r< matrix.size(); r++)
		for (unsigned c = 0; c<matrix.size();c++)
			if (mask[r][c] == 1)
				colCover[c] = 1;

	for (unsigned c = 0; c<matrix.size();c++)
		if (colCover[c] == 1)
			colcount++;

	if (colcount >= matrix.size())
		return 1;
	else
		return 2;
}

unsigned ThesisSolver::prime( vector<vector<int> > &matrix, vector<vector<int> > &mask, vector<int> &rowCover, vector<int> &colCover, int &path_row0, int & path_col0  )
{
	int row = -1;
	int col = -1;
	bool done = false;

	while(!done){
		find_a_zero( row, col, matrix,rowCover,colCover);
		if (row==-1)
		{
			done=true;
			return 4;
		}
		else{
			mask[row][col] = 2;
			if (star_in_row(row, mask))
			{
				find_star_row(row, col,mask);
				rowCover[row]=1;
				colCover[col]=0;
			}
			else
			{
				done=true;
				path_col0=col;
				path_row0=row;
			}
		}
	}
	return 3;
}

void ThesisSolver::find_a_zero( int & row, int & col , vector<vector<int> > &matrix , vector<int> rowCover,vector<int> colCover)
{
	unsigned r = 0;
	unsigned c;
	bool done=false;
	row = -1;
	col = -1;
	while(!done){
		c=0;
		while(true){
			if (matrix[r][c] == 0 && rowCover[r] == 0 && colCover[c] == 0)
			{
				row=r;
				col=c;
				done=true;
			}
			c++;
			if (c>= matrix.size() || done)
				break;
		}
		r++;
		if (r>=matrix.size())
			done=true;
	}
}

bool ThesisSolver::star_in_row( int row, vector<vector<int> > mask)
{
	bool temp = false;
	for (unsigned c = 0; c<mask.size();c++)
		if (mask[row][c] == 1)
			temp=true;
	return temp;
}

void ThesisSolver::find_star_row( int row, int & col,vector<vector<int> > mask )
{
	col = -1;
	for (unsigned c = 0; c<mask.size();c++)
		if (mask[row][c] == 1)
			col = c;
}

int ThesisSolver::matching( vector<vector<int> > &mask, vector<int> &rowCover, vector<int> &colCover, int &path_row0, int &path_col0 )
{	
	bool done=false;
	int r=-1;
	int c=-1;
	int path_count =1;

	vector<vector<int> > path;
	vector<int> temp;
	temp.push_back(path_row0);
	temp.push_back(path_col0);
	path.push_back(temp);
	temp.clear();
	while(!done){
		find_star_col(mask,path[path_count-1][1], r);
		if (r>-1)
		{
			path_count++;
			temp.push_back(r);
			temp.push_back(path[path_count-2][1]);
			path.push_back(temp);
			temp.clear();
		}
		else{
			done=true;
		}
		if (!done)
		{
			find_prime_row(mask,path[path_count-1][0], c);
			vector <int> tempor;
			tempor.push_back(path[path_count-1][0]);

			tempor.push_back(path[path_count-1][0]);
			tempor.push_back(c);
			path_count++;
			path.push_back(tempor);
		}
	}
	augment_path(path_count, mask,path);
	clear_covers(mask.size(), colCover,rowCover);
	erase_primes(mask.size(),mask);
	return 0;
}

void ThesisSolver::find_star_col( vector<vector<int> > & mask,int path, int &r )
{
	r=-1;
	for (unsigned i = 0; i< mask.size();i++)
	{
		if (mask[i][path] == 1)
		{
			//r=1;
			r = i;
		}
	}
}

void ThesisSolver::find_prime_row( vector<vector<int> > & mask, int path, int &c )
{
	for (int j = 0; mask.size();j++)
		if (mask[path][j] == 2)
			c = j;
}

void ThesisSolver::augment_path(int path_count, vector<vector<int> > & mask, vector <vector<int> > path)
{
	for (int p = 0; p<path_count; p++)
	{
		if (mask[path[p][0]][path[p][1]] == 1)
			mask[path[p][0]][path[p][1]] = 0;
		else
			mask[path[p][0]][path[p][1]]=1;
	}
}

void ThesisSolver::clear_covers(int size, vector<int> &colCover, vector<int> &rowCover )
{
	for (int r = 0; r< size;r++)
	{
		rowCover[r]=0;
		colCover[r]=0;
	}
}

void ThesisSolver::erase_primes(int size, vector<vector<int>  > & mask)
{
	for (int r= 0; r<size;r++)
		for (int c = 0 ; c<size; c++)
			if (mask[r][c] == 2)
				mask[r][c] = 0;
}

int ThesisSolver::adjustCost( vector<vector<int> > & matrix, vector<int> rowCover, vector<int> colCover )
{
	int min = INT_MAX;
	find_smallest( min, matrix,rowCover,colCover);
	for (unsigned r = 0; r<matrix.size();r++)
	{
		for (unsigned c = 0; c < matrix.size();c++)
		{
			if (rowCover[r]==1)
				matrix[r][c] += min; 
			if (colCover[c] == 0)
				matrix[r][c] -= min;
		}
	}
	return 2;
}

void ThesisSolver::find_smallest( int &min, vector<vector<int> > & matrix, vector<int> rowCover, vector<int> colCover )
{
	for (unsigned r = 0; r<matrix.size();r++)
		for (unsigned c = 0; c < matrix.size();c++)
			if (rowCover[r]==0 && colCover[c]==0)
				if (min > matrix[r][c])
					min=matrix[r][c];
}


void ThesisSolver::print_matrix( vector<vector<int> > mask )
{
	for (unsigned r = 0; r < mask.size(); r++)
	{
		for (unsigned c = 0; c < mask.size(); c++)
			cout<<mask[r][c]<<" ";
		cout<<endl;	
	}
}
