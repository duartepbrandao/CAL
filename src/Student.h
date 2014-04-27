#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

#include "Dissertation.h"

using namespace std;

class Student {

private:
	static unsigned int id; //starts at 1
	unsigned int thisID;
	string name;
	Dissertation* pair;
	vector<unsigned int> preferencesID;
	vector<Dissertation*> preferences;

public:
	Student();
	Student(string name, unsigned int oldId, vector<Dissertation*> preferences, vector<unsigned int> preferencesID);
	~Student();

	unsigned int getID() const;
	string getName() const;
	Dissertation* getPair() const;
	vector<unsigned int> & getPreferencesID();
	vector<Dissertation*> & getPreferences();

	void setName(string name);
	void setPair(Dissertation* project);

	bool teseGostaAluno(Dissertation* project);
};

#endif
