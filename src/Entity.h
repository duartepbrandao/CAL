#include <iostream>
#include <string.h>
#include <vector>


class Entity {
private:
	std::string name;
	int id; //will this be needed?
	Entity* pair;
	bool paired;
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
	void setName(std::string name);
	void setPair(Entity* entety);
	void setPaired(bool paired);
	void addToPreferences(Entity* preference);
};