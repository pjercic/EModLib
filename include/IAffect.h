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

	virtual void run(IAffect* affect) {

		for (auto& stimulus : mStimuli) {

			mArousal += lerpSlow(mArousal, stimulus->mArousal, mAffectAdjustmentFactor);
			mValence += lerpSlow(mValence, stimulus->mValence, mAffectAdjustmentFactor);
		}

		if (affect != nullptr)
		{
			mArousal += lerpSlow(mArousal, affect->GetArousal(), mAffectAdjustmentFactor);
			mValence += lerpSlow(mValence, affect->GetValence(), mAffectAdjustmentFactor);

			mAffectiveObjectDriven->run(affect);
		}
		else
		{
			mArousal += lerpSlow(mArousal, GetArousal(), mAffectAdjustmentFactor);
			mValence += lerpSlow(mValence, GetValence(), mAffectAdjustmentFactor);

			mAffectiveObjectDriven->run(this);
		}
	};

	template <typename T>
		inline T lerpSlow(T v0, T v1, T t) {
		// (1-t)*v0 + t*v1
		return (1 - t)*v0 + t * v1;
	}

	template <typename T>
		inline T lerpFast(T v0, T v1, T t) {
		//fma(t, v1, fma(-t, v0, v0))
		return fma(t, v1, fma(-t, v0, v0));
	}

	virtual ~IAffect() { delete mAffectiveObjectDriven;}; // implemented base class destructor that always gets called.
};

} /* namespace EmotionsModel */

#endif /* IAFFECT_H_ */
