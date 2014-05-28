/*
 * Superviso.cpp
 *
 *  Created on: 3 de Abr de 2014
 *      Author: ei10060
 */

#include "Supervisor.h"

Supervisor::Supervisor() :
		Entity() {
}

std::vector<Entity*> Supervisor::getSupervisoes() {
	return supervisoes;
}
void Supervisor::addSupervisao(Entity* &supervisao) {
	supervisoes.push_back(supervisao);
}
void Supervisor::removeSupervisao(Entity* &supervisao) {
	for (std::vector<Entity*>::iterator it = supervisoes.begin();
			it != supervisoes.end();) {
		if ((*it)->getID() == supervisao->getID())
			supervisoes.erase(it);
		else
			it++;
	}
}
