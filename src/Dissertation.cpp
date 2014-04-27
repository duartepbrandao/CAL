#include "Dissertation.h"
#include "Student.h"
#include "Supervisor.h"

unsigned int Dissertation::id=1;


Dissertation::Dissertation(){
	thisID=id;
	id++;
	pairedStu=false;
	pairStu=NULL;
	pairedSup=false;
	pairSup=NULL;
}

Dissertation::Dissertation(string name, unsigned int oldId, vector<Student*> preferences, vector<unsigned int> preferencesID){
	this->name=name;
	thisID=oldId;
	this->preferences=preferences;
	this->preferencesID=preferencesID;
	pairedStu=false;
	pairStu=NULL;
	pairedSup=false;
	pairSup=NULL;
}


unsigned int Dissertation::getID() const{
	return thisID;
}

string Dissertation::getName() const{
	return name;
}

Student* Dissertation::getPairStu() const{
	return pairStu;
}

Supervisor* Dissertation::getPairSup() const{
	return pairSup;
}

vector<unsigned int> & Dissertation::getPreferencesID(){
	return preferencesID;
}

vector<Student*> & Dissertation::getPreferences(){
	return preferences;
}


void Dissertation::setName(string name){
	this->name = name;
}

void Dissertation::setPairedStu(bool paired){
	pairedStu=paired;
}

void Dissertation::setPairStu(Student* person){
	pairedStu=true;
	this->pairStu = person;
}

void Dissertation::setPairedSup(bool paired){
	pairedSup=paired;
}

void Dissertation::setPairSup(Supervisor* professor){
	pairedSup=true;
	this->pairSup = professor;
}
