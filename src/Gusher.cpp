/*
 * Gusher.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#include "Gusher.h"
#include "Affect.h"
#include "Personality.h"

namespace EmotionsModel {

Gusher::Gusher() {

	mLocation = 0;
	mEmotionLabel = EmotionLabel::Fear;
	mAffect = new Affect(0.9, new Personality(0.1));
}

} /* namespace EmotionsModel */
