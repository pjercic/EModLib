/*
 * Gusher.h
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#ifndef GUSHER_H_
#define GUSHER_H_

#include "IPerson.h"

namespace EmotionsModel {

class Gusher: public IPerson {
public:
	// Constructor calls abstract Factory method
	Gusher();
	virtual ~Gusher() {};
};

} /* namespace EmotionsModel */

#endif /* GUSHER_H_ */
