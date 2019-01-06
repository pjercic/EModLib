/*
 * IPerson.h
 *
 *  Created on: Aug 4, 2018
 *      Author: b1-166er
 *
 *  The 'Product' abstract class
 */

#ifndef IPERSON_H_
#define IPERSON_H_

#define _USE_MATH_DEFINES

#include <cmath>
#include <chrono>
#include <thread>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

#include "stimulus.h"
#include "IAffect.h"

namespace EmotionsModel {

// Affective circle start from 0 - think if more feasible to start from 1 and rotate the circle further
enum EmotionLabel { Trust = 0, Happines, Anticipation, Anger, Disgust, Sadness, Suprise, Fear, None };

class IPerson {
public:
	IAffect* mAffect;
	EmotionLabel mEmotionLabel;
	int mLocation;
	bool isRunning;

	IPerson() : mAffect(0), mEmotionLabel(EmotionLabel::None), mLocation(0), isRunning(false) {}; // empty constructor to build an independent object
	virtual ~IPerson() { delete mAffect; }; // implemented base class destructor that always gets called

	virtual void inStimulus (stimulus* stimulus)
	{
		if (mAffect)
				mAffect->inStimulus(stimulus);
	};

	virtual EmotionLabel getEmotion() 
	{
		// Math function that separates affective circle on N equal pieces, where N is the number of emotions
		double rotAffClass = M_PI/8; // Rotate the circle so the first emotional class fits to the beginning  of the affective circle
		double affRad = atan2(mAffect->GetArousal(), mAffect->GetValence()); // Get corrected radians of the interest point
		affRad = affRad >= 0 ? affRad : (2 * M_PI) + affRad; // Fix negative quadrant radians
		double normAffRad = (affRad + rotAffClass) / (2 * M_PI); // Normalize to [0,1] interval
		int emoClass = int(normAffRad * 8); // Calculate the emotional class based on the position on the affective circle for the 8 equidistant emotions
		mEmotionLabel = (EmotionLabel)emoClass;
		return mEmotionLabel;
	};

	virtual IAffect* getAffect() { return mAffect; };

	virtual void Run()
	{
		isRunning = true;
		auto previousTime = std::chrono::high_resolution_clock::now();

		while (isRunning) 
		{
			mAffect->run(nullptr);

			std::chrono::duration<double, std::milli> deltaTime = std::chrono::milliseconds(1000) - (std::chrono::high_resolution_clock::now() - previousTime);
			
			std::this_thread::sleep_for(deltaTime);

			previousTime = std::chrono::high_resolution_clock::now();
		}
	}
};

} /* namespace EmotionsModel */

#endif /* IPERSON_H_ */
