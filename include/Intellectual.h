/*
 * Intellectual.h
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#ifndef INTELLECTUAL_H_
#define INTELLECTUAL_H_

#include "IPerson.h"

namespace EmotionsModel {

class Intellectual: public IPerson {
public:
	// Constructor calls abstract Factory method
	Intellectual();
	virtual ~Intellectual() {};
};

} /* namespace EmotionsModel */

#endif /* INTELLECTUAL_H_ */
