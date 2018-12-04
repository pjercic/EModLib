/*
 * PeopleFactory.cpp
 *
 *  Created on: Aug 5, 2018
 *      Author: b1-166er
 */

#include "PeopleFactory.h"
#include "Intellectual.h"
#include "Empath.h"
#include "Rock.h"
#include "Gusher.h"

namespace EmotionsModel {

PeopleFactory::PeopleFactory() {
	// TODO Auto-generated constructor stub

}

IPerson* PeopleFactory::getPerson(PersonLabel type) {

	switch(type) {
		case 0:{
			return new Intellectual;
			break;
		}
		case 1:{
			return new Empath;
			break;
		}
		case 2:{
			return new Rock;
			break;
		}
		case 3:{
			return new Gusher;
			break;
		}
		default:{
			return NULL;
		}
	}
}

PeopleFactory* PeopleFactory::getInstance() {

	static PeopleFactory instance;
	return &instance;
}

} /* namespace EmotionsModel */
