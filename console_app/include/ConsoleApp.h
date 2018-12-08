/*
 * MyClass.h
 *
 *  Created on: Aug 6, 2018
 *      Author: b1-166er
 */

#pragma once

#include <vector>
#include "EmotionsModelLib.h"

class ConsoleApp {
public:
	EmotionsModel::EmotionsModelLib emotionModelObj;
	std::vector<int> personsList;

	ConsoleApp();
	virtual ~ConsoleApp();	
};
