/*
 * Rock.h
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#ifndef ROCK_H_
#define ROCK_H_

#include "IPerson.h"

namespace EmotionsModel {

class Rock: public IPerson {
public:
	// Constructor calls abstract Factory method
	Rock();
	virtual ~Rock() {};
};

} /* namespace EmotionsModel */

#endif /* ROCK_H_ */
