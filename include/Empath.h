/*
 * Empath.h
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#ifndef EMPATH_H_
#define EMPATH_H_

#include "IPerson.h"

namespace EmotionsModel {

class Empath: public IPerson {
public:
	// Constructor calls abstract Factory method
	Empath();
	virtual ~Empath() {};
};

} /* namespace EmotionsModel */

#endif /* EMPATH_H_ */
