/*
 * stimulus.cpp
 *
 *  Created on: Jul 28, 2018
 *      Author: b1-166er
 */

#include "stimulus.h"

using namespace EmotionsModel;

stimulus::stimulus(double arousal, double valence) {

	mArousal = arousal;
	mValence = valence;
}

stimulus::~stimulus() {
	// TODO Auto-generated destructor stub
}
