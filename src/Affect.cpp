/*
 * Affect.cpp
 *
 *  Created on: Aug 3, 2018
 *      Author: b1-166er
 */

#include <ctime>
#include "Affect.h"

namespace EmotionsModel {

Affect::Affect() {
	// TODO Auto-generated constructor stub

}

void Affect::inStimulus(stimulus* stimulus) {

	mStimuli.push_back(stimulus);
}

//void Affect::run(double arousal, double valence) {
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
}
