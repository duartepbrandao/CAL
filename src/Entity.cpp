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
	return thisID;
}

Entity* Entity::getPair()
{
	return pair;
}

bool Entity::isPaired()
{
	return paired;
}

vector<Entity*> Entity::getPreferences()
{
	return preferences;
}

vector<int> & Entity::getPreferencesID()
{
	return preferencesID;
}

void Entity::setName( std::string name )
{
	this->name=name;
}

void Entity::setPair( Entity* pair )
{
	this->pair=pair;
	if(pair==NULL) paired=false;
	else paired = true;
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

bool Entity::teseGostaAluno(Entity * dissertation){
	vector<int> preferencias = dissertation->getPreferencesID();

	for(int i=0; i<(int)preferencias.size(); i++)
		if(preferencias[i]==(this->getID()))
			return true;

	return false;
}
