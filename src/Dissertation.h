#ifndef DISSERTATION_H_
#define DISSERTATION_H_

#include <iostream>
#include <vector>
#include <string>

class Student;
class Supervisor;

using namespace std;

class Dissertation {

private:
	static unsigned int id; //starts at 1
	unsigned int thisID;
	string name;
	bool pairedStu;
	Student* pairStu;
	bool pairedSup;
	Supervisor* pairSup;
	vector<unsigned int> preferencesID;
	vector<Student*> preferences;

public:
	Dissertation();
	Dissertation(string name, unsigned int oldId, vector<Student*> preferences, vector<unsigned int> preferencesID);
	~Dissertation();

	unsigned int getID() const;
	string getName() const;
	bool getPairedStu() const;
	Student* getPairStu() const;
	bool getPairedSup() const;
	Supervisor* getPairSup() const;
	vector<unsigned int> & getPreferencesID();
	vector<Student*> & getPreferences();

	void setName(string name);
	void setPairedStu(bool paired);
	void setPairStu(Student* person);
	void setPairedSup(bool paired);

	void setPairSup(Supervisor* professor);
};

#endif
