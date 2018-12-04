/*
 * Personality.h
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 *
 *  A 'ConcreteProduct' class
 */

#ifndef PERSONALITY_H_
#define PERSONALITY_H_

#include "IAffect.h"

namespace EmotionsModel {

class Personality: public IAffect {
public:
	// Constructor calls abstract Factory method
	Personality();
	Personality(double affectAdjustmentFactor) : IAffect(affectAdjustmentFactor) {};
	Personality(double arousal, double valence) { mArousal = arousal; mValence = valence; }; // personality initialization specific to this class
	//void run(double arousal, double valence);
	void inStimulus(stimulus* stimulus);
	~Personality() {};
};

} /* namespace EmotionsModel */

#endif /* PERSONALITY_H_ */
