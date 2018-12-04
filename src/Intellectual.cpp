/*
 * Intellectual.cpp
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 */

#include "Intellectual.h"
//#include "IAffect.h"
#include "Mood.h"
#include "Personality.h"

namespace EmotionsModel {

Intellectual::Intellectual() {

	mLocation = 0;
	mEmotionLabel = EmotionLabel::Happines;
	mAffect = new Mood(0.5, new Personality);

}

} /* namespace EmotionsModel */
