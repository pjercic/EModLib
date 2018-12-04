/*
 * Mood.h
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 *
 *  A 'ConcreteProduct' class
 */

#ifndef MOOD_H_
#define MOOD_H_

#include "IAffect.h"

namespace EmotionsModel {

class Mood: public IAffect {
public:
	// Constructor calls abstract Factory method
	Mood();
	Mood(double affectAdjustmentFactor) : IAffect(affectAdjustmentFactor) {};
	Mood(double affectAdjustmentFactor, IAffect* affectiveObjectDriven) : IAffect(affectAdjustmentFactor, affectiveObjectDriven) {};
	//void run(double arousal, double valence);
	void inStimulus(stimulus* stimulus);
	~Mood() {};

	// TODO Factory Method implementation Create
};

} /* namespace EmotionsModel */

#endif /* MOOD_H_ */
