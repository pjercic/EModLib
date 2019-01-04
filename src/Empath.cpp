/*
 * Empath.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#include "Empath.h"
#include "Affect.h"
#include "Mood.h"
#include "Personality.h"

namespace EmotionsModel {

Empath::Empath() {

	mLocation = 0;
	mEmotionLabel = EmotionLabel::Sadness;
	mAffect = new Affect(0.9, new Mood(0.5, new Personality(0.1)));
}

} /* namespace EmotionsModel */
