/*
 * Rock.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#include "Rock.h"
#include "Personality.h"

namespace EmotionsModel {

Rock::Rock() {

	mLocation = 0;
	mEmotionLabel = EmotionLabel::Happines;
	mAffect = new Personality(0.1);
}

} /* namespace EmotionsModel */
