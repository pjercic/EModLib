/*
 * EmotionsModel.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: b1-166er
 */

#include "EmotionsModelLib.h"
#include "IPerson.h"

namespace EmotionsModel {

EmotionsModelLib::EmotionsModelLib() {
	// TODO Auto-generated constructor stub

}

void EmotionsModelLib::inStimulus(int persId, double arousal, double valence) {

	mPersons[persId]->inStimulus(new stimulus(arousal, valence));
}

EmotionLabel EmotionsModelLib::getEmotion(int persId) {

	if (mPersons.empty() || persId > mPersons.size())
		return EmotionLabel::None;

	return mPersons[persId]->getEmotion();
}

IAffect* EmotionsModelLib::getAffect(int persId) {

	if (mPersons.empty() || persId > mPersons.size())
		return NULL;

	return mPersons[persId]->getAffect();
}

int EmotionsModelLib::createPerson(PersonLabel type) {

	mPersons.push_back(PeopleFactory::getPerson(type));
	return mPersons.size() - 1;
}

void EmotionsModelLib::run() {

	for (auto person : mPersons) {

		person->mAffect->run(person->mAffect->GetArousal(), person->mAffect->GetValence());
	}
}

} /* namespace EmotionsModel */

