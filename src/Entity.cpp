#include "Entity.h"

Entity::Entity()
{
	//ID
	paired=false;
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


