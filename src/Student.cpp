#include "Student.h"

unsigned int Student::id=1;

Student::Student(){
	thisID=id;
	id++;
	pair=NULL;
}

Student::Student(string name, unsigned int oldId, vector<Dissertation*> preferences, vector<unsigned int> preferencesID){
	thisID=oldId;
	this->name=name;
	pair=NULL;
	this->preferences=preferences;
	this->preferencesID = preferencesID;
}


unsigned int Student::getID() const{
	return thisID;
}

string Student::getName() const{
	return name;
}

Dissertation* Student::getPair() const{
	return pair;
}

vector<unsigned int> & Student::getPreferencesID(){
	return preferencesID;
}

vector<Dissertation*> & Student::getPreferences(){
	return preferences;
}


void Student::setName(string name){
	this->name=name;
}

void Student::setPair(Dissertation* project){
	this->pair=project;
}


bool Student::teseGostaAluno(Dissertation * project){
	vector<unsigned int> preferencias = project->getPreferencesID();

	for(int i=0; i<(int)preferencias.size(); i++)
		if(preferencias[i]==(this->getID()))
			return true;

	return false;
}

