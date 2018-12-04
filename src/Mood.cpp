/*
 * Mood.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 */

#include <ctime>
#include "Mood.h"

namespace EmotionsModel {

Mood::Mood() {
	// TODO Auto-generated constructor stub

}

void Mood::inStimulus(stimulus* stimulus) {

	mStimuli.push_back(stimulus);
}

//void Mood::run(double arousal, double valence) {
//
//	double secondsPassed;
//	bool flag = true;
//
//	while(flag) {
//
//		secondsPassed = (clock() - mTimer) / CLOCKS_PER_SEC;
//		if(secondsPassed >= 100) {
//
//			 flag = false;
//		}
//	}
//}

} /* namespace EmotionsModel */
