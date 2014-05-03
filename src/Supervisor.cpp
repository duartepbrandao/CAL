/*
* Superviso.cpp
*
*  Created on: 3 de Abr de 2014
*      Author: ei10060
*/

#include "Supervisor.h"

Supervisor::Supervisor() : Entity() {}

Supervisor::Supervisor( Supervisor* copyEntity ):Entity(copyEntity->getName(),copyEntity->getID(),copyEntity->getPreferences(),copyEntity->getPreferencesID())
{
	this->maxSupervisions=copyEntity->getMaxSupervisions();
}


void Supervisor::setMaxSupervisions( int max )
{
	this->maxSupervisions=max;
}

int Supervisor::getMaxSupervisions()
{
	return maxSupervisions;
}

int Supervisor::getCost( Entity* thesis )
{
	for (unsigned i = 0; i < preferences.size(); i++)
	{	
		if (thesis->getID()==preferences[i]->getID())
		{	
			return i+1;
		}
	}
	return INT_MAX;
}
