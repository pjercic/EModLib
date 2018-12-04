/*
 * EmotionsModel.h
 *
 *  Created on: Aug 1, 2018
 *      Author: b1-166er
 */

#ifndef EMOTIONSMODELLIB_H_
#define EMOTIONSMODELLIB_H_

#include <vector>
#include "IPerson.h"
#include "IAffect.h"
#include "stimulus.h"
#include "PeopleFactory.h"

namespace EmotionsModel {

// factory
// distance changed listener event

class EmotionsModelLib {

	private:
		std::vector<IPerson*> mPersons;

	public:
		EmotionsModelLib();
		virtual ~EmotionsModelLib() { for (auto person : mPersons) delete person;  };

		void inStimulus(int persId, double arousal, double valence);
		EmotionLabel getEmotion(int persId);
		IAffect* getAffect(int persId);
		int createPerson(PersonLabel type); // implement if want to keep record of all persons
		void run();
	};

} /* namespace EmotionsModel */

#endif /* EMOTIONSMODELLIB_H_ */
