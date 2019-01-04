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
	
	double GetArousal() { return mArousal; };
	double GetValence() { return mValence; };
	
	virtual void inStimulus(stimulus* stimulus) = 0;

	virtual void run(IAffect* affect) {

        // TODO: Harmonic Spring Oscilator
        // TODO: Timed stimulus
        // Spring system based emotions - Hooks Law

        // If top affective object, there is no forward object, just stimulus if exists (wall) and backward object if exists
        if (affect == nullptr)
        {
            double resultingForceStimulusArousal = 0;
            double resultingForceStimulusValence = 0;

            if (!mStimuli.empty())
            {
                for (auto& stimulus : mStimuli) {

                    resultingForceStimulusArousal += stimulus->mArousal;
                    resultingForceStimulusValence += stimulus->mValence;

                    // Consume stimulus
                    delete stimulus;
                    stimulus = nullptr;
                }

                mStimuli.clear();
                resultingForceStimulusArousal = mAffectAdjustmentFactor * (resultingForceStimulusArousal - mArousal);
                resultingForceStimulusValence = mAffectAdjustmentFactor * (resultingForceStimulusValence - mValence);
            }

            double resultingForceBackwardArousal = 0;
            double resultingForceBackwardValence = 0;

            if (mAffectiveObjectDriven)
            {
                resultingForceBackwardArousal = - mAffectiveObjectDriven->mAffectAdjustmentFactor * (mArousal - mAffectiveObjectDriven->mArousal);
                resultingForceBackwardValence = - mAffectiveObjectDriven->mAffectAdjustmentFactor * (mValence - mAffectiveObjectDriven->mValence);
            }

            double arousalDifference = resultingForceStimulusArousal + resultingForceBackwardArousal;
            double valenceDifference = resultingForceStimulusValence + resultingForceBackwardValence;

            mArousal = lerpSlow(mArousal, mArousal + arousalDifference, mAffectAdjustmentFactor);
            mValence = lerpSlow(mValence, mValence + valenceDifference, mAffectAdjustmentFactor);
        }
        // If lower hierarchy affective object, there is a backward object and forward object if exists
        else
        {
            double resultingForceForwardArousal = mAffectAdjustmentFactor * (affect->mArousal - mArousal);
            double resultingForceForwardValence = mAffectAdjustmentFactor * (affect->mValence - mValence);

            double resultingForceBackwardArousal = 0;
            double resultingForceBackwardValence = 0;

            if (mAffectiveObjectDriven)
            {
                resultingForceBackwardArousal = - mAffectiveObjectDriven->mAffectAdjustmentFactor * (mArousal - mAffectiveObjectDriven->mArousal);
                resultingForceBackwardValence = - mAffectiveObjectDriven->mAffectAdjustmentFactor * (mValence - mAffectiveObjectDriven->mValence);
            }

            double arousalDifference = resultingForceForwardArousal + resultingForceBackwardArousal;
            double valenceDifference = resultingForceForwardValence + resultingForceBackwardValence;

            mArousal = lerpSlow(mArousal, mArousal + arousalDifference, mAffectAdjustmentFactor);
            mValence = lerpSlow(mValence, mValence + valenceDifference, mAffectAdjustmentFactor);
        }

        if (mAffectiveObjectDriven) mAffectiveObjectDriven->run(this);
	};

    // TODO: Fix lerping based on epsilon values close to zero
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
