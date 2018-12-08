/*
 * EmotionsModel.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: b1-166er
 */

#include "EmotionsModelLib.h"
#include "IPerson.h"

#include <algorithm>

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

void EmotionsModelLib::Start() {

	for (auto person : mPersons)
	{
		mPersonAffectThreadList.push_back (std::thread (&IPerson::Run, person));
	}

	//std::for_each(mPersonAffectThreadList.begin(), mPersonAffectThreadList.end(), std::mem_fn(&std::thread::join));
}

void EmotionsModelLib::Stop() {

	for (auto person : mPersons)
	{
		person->isRunning = false;
	}

}

} /* namespace EmotionsModel */

