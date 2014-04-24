#include "Entity.h"


int Entity::id=1;

Entity::Entity()
{
	thisID = id;
	id++;
	paired=false;
	pair = NULL;
}

Entity::Entity( string name, int oldId, vector <Entity*> preferences,vector <int> preferencesID )
{
	this->name=name;
	thisID=oldId;
	pair= NULL;
	paired=false;
	this->preferences=preferences;
	this->preferencesID = preferencesID;
}

std::string Entity::getName()
{
	return name;
}

int Entity::getID()
{
	return id;
}

Entity* Entity::getPair()
{
	return pair;
}

bool Entity::isPaired()
{
	return paired;
}

std::vector <Entity*> Entity::getPreferences()
{
	return preferences;
}

std::vector <int> Entity::getPreferencesID()
{
	return preferencesID;
}

void Entity::setName( std::string name )
{
	this->name=name;
}

void Entity::setPair( Entity* entety )
{
	this->pair=entety;
}

void Entity::setPaired( bool paired )
{
	this->paired=paired;
}

void Entity::addToPreferences( Entity* preference )
{
	preferences.push_back(preference);
}

Entity::~Entity()
{

}

void Entity::addToPreferencesID( int id )
{
	preferencesID.push_back(id);
}


