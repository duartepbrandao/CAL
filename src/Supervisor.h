#ifndef SUPERVISOR_H_
#define SUPERVISOR_H_

#include <iostream>
#include <climits>

#include "Dissertation.h"

using namespace std;

class Supervisor {

private:
	static unsigned int id; //starts at 1
	unsigned int thisID;
	string name;
	Dissertation* pair;
	vector<unsigned int> preferencesID;
	vector<Dissertation*> preferences;
	int maxSupervisions;

public:
	Supervisor();
	Supervisor(Supervisor* copyEntity);
	~Supervisor();

	unsigned int getID() const;
	string getName() const;
	Dissertation* getPair() const;
	vector<unsigned int> & getPreferencesID();
	vector<Dissertation*> & getPreferences();
	unsigned int getMaxSupervisions() const;

	void setName(string name);
	void setPair(Dissertation* pair);
	void setMaxSupervisions(unsigned int max);

	int getCost(Dissertation* thesis);

};

#endif /* SUPERVISOR_H_ */
