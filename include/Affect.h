/*
 * Affect.h
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 *
 *  A 'ConcreteProduct' class
 */

#ifndef AFFECT_H_
#define AFFECT_H_

#include "IAffect.h"

namespace EmotionsModel {

class Affect: public IAffect {

public:
	// Constructor calls abstract Factory method
	Affect();
	Affect(double affectAdjustmentFactor) : IAffect(affectAdjustmentFactor) {};
	Affect(double affectAdjustmentFactor, IAffect* affectiveObjectDriven) : IAffect(affectAdjustmentFactor, affectiveObjectDriven) {};
	//void run(double arousal, double valence);
	void inStimulus(stimulus* stimulus);
	~Affect() {};

	// TODO Factory Method implementation Create
};

} /* namespace EmotionsModel */

#endif /* AFFECT_H_ */
