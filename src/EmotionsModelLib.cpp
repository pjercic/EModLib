/*
 * EmotionsModel.cpp
 *
 *  Created on: Aug 1, 2018
 *      Author: b1-166er
 */

#include "EmotionsModelLib.h"
#include "IPerson.h"

#include <algorithm>
/*
extern "C" {
    float TestMultiply(float a, float b)
    {
        return a * b;
    }

    float TestDivide(float a, float b)
    {
        if (b == 0) {
            return 0;
            //throw invalid_argument("b cannot be zero!");
        }

        return a / b;
    }
}
*/
EmotionsModel::EmotionsModelLib* gEModLib = nullptr;

// Enternal Unmanaged API
extern "C"
{
    __declspec (dllexport) void Instantiate()
    {
        if (!gEModLib)
            gEModLib = new EmotionsModel::EmotionsModelLib();
    }

    __declspec (dllexport) void inStimulus(int persId, double arousal, double valence)
    {
        gEModLib->inStimulus(persId, arousal, valence);
    }

    __declspec (dllexport) int getEmotion(unsigned int persId)
    {
        return gEModLib->getEmotion(persId);
    }

    __declspec (dllexport) double getArousal(unsigned int persId)
    {
        return gEModLib->getAffect(persId)->GetArousal();
    }

    __declspec (dllexport) double getValence(unsigned int persId)
    {
        return gEModLib->getAffect(persId)->GetValence();
    }

    __declspec (dllexport) int createPerson(int type)
    {
        return gEModLib->createPerson(static_cast<EmotionsModel::PersonLabel>(type));
    }

    __declspec (dllexport) void Start()
    {
        return gEModLib->Start();
    }

    __declspec (dllexport) void Stop()
    {
        return gEModLib->Stop();
    }
}

namespace EmotionsModel {

EmotionsModelLib::EmotionsModelLib() {
	// TODO Auto-generated constructor stub

}

void EmotionsModelLib::inStimulus(int persId, double arousal, double valence) {

	mPersons[persId]->inStimulus(new stimulus(arousal, valence));
}

EmotionLabel EmotionsModelLib::getEmotion(unsigned int persId) {

	if (mPersons.empty() || persId > mPersons.size())
		return EmotionLabel::None;

	return mPersons[persId]->getEmotion();
}

IAffect* EmotionsModelLib::getAffect(unsigned int persId) {

	if (mPersons.empty() || persId > mPersons.size())
		return NULL;

	return mPersons[persId]->getAffect();
}

int EmotionsModelLib::createPerson(PersonLabel type) {

	mPersons.push_back(PeopleFactory::getPerson(type));
	return int(mPersons.size() - 1);
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

