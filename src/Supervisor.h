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

class Supervisor: public Entity {
	std::vector<Entity*> supervisoes;
public:
	Supervisor();
	std::vector<Entity*> getSupervisoes();
	void addSupervisao(Entity* &supervisao);
	void removeSupervisao(Entity* &supervisao);

};

#endif /* SUPERVISOR_H_ */
