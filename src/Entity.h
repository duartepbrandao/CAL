#ifndef ENTITY_H_
#define ENTITY_H_


#include <iostream>
#include <string.h>
#include <vector>


class Entity {
protected:
	std::string name;
	static int id; //starts at 1
	int thisID;
	Entity* pair;
	bool paired;
	std::vector <int> preferencesID;
	std::vector <Entity*> preferences;

public:
	Entity();
	~Entity();

	//getters()
	std::string getName();
	int getID();
	Entity* getPair();
	bool isPaired();
	std::vector <Entity*> getPreferences();

	//setters()
	void addToPreferencesID(int id);
	void setName(std::string name);
	void setPair(Entity* entety);
	void setPaired(bool paired);
	void addToPreferences(Entity* preference);
};


#endif /* ENTITY_H_ */
