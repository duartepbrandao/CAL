/*
 * Supervisor.h
 *
 *  Created on: 3 de Abr de 2014
 *      Author: ei10060
 */

#ifndef SUPERVISOR_H_
#define SUPERVISOR_H_
#include "Entity.h"
#include <iostream>
#include <climits>

using namespace std;

class Supervisor: public Entity {
	int maxSupervisions;
public:
	Supervisor();
	Supervisor(Supervisor* copyEntity);
	void setMaxSupervisions(int max);
	int getMaxSupervisions();
	int getCurrentSupervisions();
	std::vector<Entity*> getSupervisoes();
	void addSupervisao(Entity* &supervisao);
	void removeSupervisao(Entity* &supervisao);
	int getCost(Entity* thesis);

};

#endif /* SUPERVISOR_H_ */
