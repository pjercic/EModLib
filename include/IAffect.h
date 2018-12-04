/*
 * AffectInterface.h
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 *
 *  The 'Product' abstract class
 */

#ifndef IAFFECT_H_
#define IAFFECT_H_

#include <vector>
#include <ctime>
#include "stimulus.h"

namespace EmotionsModel {

class IAffect {

public:

	clock_t mTimer;
	IAffect* mAffectiveObjectDriven;
	std::vector<stimulus*> mStimuli;
	double mValence;
	double mArousal;
	double mAffectAdjustmentFactor;

	// Constructor calls abstract Factory method
	IAffect() : mTimer(clock()), mAffectiveObjectDriven(NULL), mArousal(0), mValence(0), mAffectAdjustmentFactor(0.0) {}; // empty constructor to build an independent object
	IAffect(double affectAdjustmentFactor) : mTimer(clock()), mAffectiveObjectDriven(NULL), mArousal(0), mValence(0), mAffectAdjustmentFactor(affectAdjustmentFactor) {};
	IAffect(double affectAdjustmentFactor, IAffect* affectiveObjectDriven) : mTimer(clock()), mAffectiveObjectDriven(affectiveObjectDriven), mArousal(0), mValence(0), mAffectAdjustmentFactor (affectAdjustmentFactor) {}; // argument constructor to insert dependancy
	
	double GetArousal() { return mAffectiveObjectDriven ? mAffectiveObjectDriven->GetArousal() + mArousal : mArousal; };
	double GetValence() { return mAffectiveObjectDriven ? mAffectiveObjectDriven->GetValence() + mValence : mValence; };
	
	virtual void inStimulus(stimulus* stimulus) = 0;

	virtual void run(double arousal, double valence) {

		for (auto& stimulus : mStimuli) {

			mArousal += 0.1 * (stimulus->mArousal - mArousal);
			mValence += 0.1 * (stimulus->mValence - mValence);
		}

			mArousal += 0.1 * (arousal - mArousal);
			mValence += 0.1 * (valence - mValence);

		if (mAffectiveObjectDriven)
			mAffectiveObjectDriven->run(arousal, valence);
	};

	virtual ~IAffect() { delete mAffectiveObjectDriven;}; // implemented base class destructor that always gets called.
};

} /* namespace EmotionsModel */

#endif /* IAFFECT_H_ */
