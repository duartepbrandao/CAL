#include "Supervisor.h"

unsigned int Supervisor::id=1;


Supervisor::Supervisor(){
	thisID=id;
	id++;
	pair=NULL;
	maxSupervisions=0;
}

Supervisor::Supervisor(Supervisor* copyEntity) {
	thisID = copyEntity->getID();
	this->name = copyEntity->getName();
	pair = NULL;
	this->preferences = copyEntity->getPreferences();
	this->preferencesID = copyEntity->getPreferencesID();
	this->maxSupervisions = copyEntity->getMaxSupervisions();
}


unsigned int Supervisor::getID() const{
	return thisID;
}

string Supervisor::getName() const{
	return name;
}

Dissertation* Supervisor::getPair() const{
	return pair;
}

vector<unsigned int> & Supervisor::getPreferencesID(){
	return preferencesID;
}

vector<Dissertation*> & Supervisor::getPreferences(){
	return preferences;
}

unsigned int Supervisor::getMaxSupervisions() const{
	return maxSupervisions;
}


void Supervisor::setName(string name){
	this->name=name;
}

void Supervisor::setPair(Dissertation* pair){
	this->pair=pair;
}

void Supervisor::setMaxSupervisions(unsigned int max){
	this->maxSupervisions=max;
}


int Supervisor::getCost(Dissertation * thesis){
	for (unsigned int i = 0; i < preferences.size(); i++)
		if (thesis->getID()==preferences[i]->getID())
			return i+1;
	return INT_MAX;
}
