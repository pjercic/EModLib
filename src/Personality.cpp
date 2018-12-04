/*
 * Personality.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 */

#include <ctime>
#include "Personality.h"

namespace EmotionsModel {

Personality::Personality() {
	// TODO Auto-generated constructor stub

}

void Personality::inStimulus(stimulus* stimulus) {

	mStimuli.push_back(stimulus);
}

//void Personality::run(double arousal, double valence) {
//
//	for (auto& stimulus : mStimuli) {
//
//		mArousal += 0.1 * (stimulus->mArousal - mArousal);
//		mValence += 0.1 * (stimulus->mValence - mValence);
//	}
//
//	if (!mStimuli.empty()) {
//
//		mArousal += 0.1 * (arousal - mArousal);
//		mValence += 0.1 * (valence - mValence);
//	}
//
//	if (mAffectiveObjectDriven)
//		mAffectiveObjectDriven->run(arousal, valence);
//}

} /* namespace EmotionsModel */
