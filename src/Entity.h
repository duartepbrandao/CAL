#ifndef ENTITY_H_
#define ENTITY_H_


#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


class Entity {
protected:
	string name;
	static int id; //starts at 1
	int thisID;
	Entity* pair;
	bool paired;
	vector <int> preferencesID;
	vector <Entity*> preferences;

public:
	Entity();
	~Entity();
	Entity(string name,int oldId,vector <Entity*> preferences,vector <int> preferencesID);
	//getters()
	string getName();
	int getID();
	Entity* getPair();
	bool isPaired();
	vector <Entity*> getPreferences();
	vector <int> getPreferencesID();

	//setters()
	void addToPreferencesID(int id);
	void setName(std::string name);
	void setPair(Entity* entety);
	void setPaired(bool paired);
	void addToPreferences(Entity* preference);
};


#endif /* ENTITY_H_ */
