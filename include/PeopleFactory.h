/*
 * PeopleFactory.h
 *
 *  Created on: Aug 5, 2018
 *      Author: b1-166er
 */

#ifndef PEOPLEFACTORY_H_
#define PEOPLEFACTORY_H_

#include "IPerson.h"

namespace EmotionsModel {

enum PersonLabel { IntellectualType, EmpathType, RockType, GusherType };

class PeopleFactory {

public:
	PeopleFactory();
	virtual ~PeopleFactory() {};

	static IPerson* getPerson(PersonLabel type);

	static PeopleFactory* getInstance();
};

} /* namespace EmotionsModel */

#endif /* PEOPLEFACTORY_H_ */
