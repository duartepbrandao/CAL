#include "Changes.h"


Changes::Changes(){
	offset=0;
}

void Changes::add( string line, int type, int line_number )
{
	lines.push_back(line);
	this->type.push_back(type);
	line_numbers.push_back(line_number);
}

void Changes::print(){
	ofstream ficheiro("diferenca.txt", ofstream::out);

	cout << "\n\n\t\t\t" << "REMOVIDO" << endl;
	ficheiro << "\n\n\t\t\t" << "REMOVIDO" << endl;
	for(int i=lines.size()-1; i>=0; i--){
		if(type[i]==0)
			cout << "- " << line_numbers[i]+1+offset << " " << lines[i] << endl;
			ficheiro << "- " << line_numbers[i]+1+offset << " " << lines[i] << endl;
	}

	cout << "\n\n\t\t\t" << "ADICIONADO" << endl;
	ficheiro << "\n\n\t\t\t" << "ADICIONADO" << endl;
	for(int i = lines.size()-1; i>=0; i--){
		if(type[i]==1)
			cout << "+ " << line_numbers[i]+1+offset << " " << lines[i] << endl;
			ficheiro << "+ " << line_numbers[i]+1+offset << " " << lines[i] << endl;
	}

	cout << "\n\n\t\t\t" << "MANTIDO" << endl;
	ficheiro << "\n\n\t\t\t" << "MANTIDO" << endl;
	for(int i=0; i < (int) lines_equal.size(); i++){
		cout << "  " << line_numbers_equal[i] << " " << lines_equal[i] << endl;
		ficheiro << "  " << line_numbers_equal[i] << " " << lines_equal[i] << endl;
	}

	ficheiro.close();

	cout << endl << "Numero de alteracoes: " << type.size() << endl << endl;
}

void Changes::setEqualOffset(vector<string> similar, int offset, vector<int> line_numbers){
	lines_equal = similar;
	this->offset = offset;
	line_numbers_equal = line_numbers;
}

void Changes::clearAttributes(){
	lines.clear();
	lines_equal.clear();
	type.clear();
	line_numbers.clear();
	line_numbers_equal.clear();
	offset=0;
}
