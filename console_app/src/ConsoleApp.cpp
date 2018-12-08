/*
 * MyClass.cpp
 *
 *  Created on: Aug 6, 2018
 *      Author: b1-166er
 */

#include <iostream>
#include "ConsoleApp.h"

using namespace EmotionsModel;

void CreatePerson(ConsoleApp& app)
{
	int nrPersons = 0;
	std::cout << std::endl << "Chose how many:\n";
	std::cin >> nrPersons;

	for (int i = 0; i < nrPersons; i++)
	{
		app.personsList.push_back(app.emotionModelObj.createPerson(PersonLabel::EmpathType));
	}
}

void PrintPersons(ConsoleApp& app)
{
	for (unsigned int i = 0; i < app.personsList.size(); i++)
	{
		std::cout << "PersonId: " << app.personsList[i] << "\tArousal: " << app.emotionModelObj.getAffect(app.personsList[i])->GetArousal() << "\tValence: " << app.emotionModelObj.getAffect(app.personsList[i])->GetArousal() << " Emotion: " << app.emotionModelObj.getEmotion(app.personsList[i]) << std::endl;
	}
}

void StimulatePersons(ConsoleApp& app)
{
	for (unsigned int i = 0; i < app.personsList.size(); i++)
	{
		app.emotionModelObj.inStimulus(app.personsList[i], 0.005, 0.005);
	}
}

void StartSimulation(ConsoleApp& app)
{
	app.emotionModelObj.Start();
}

void StopSimulation(ConsoleApp& app)
{
	app.emotionModelObj.Stop();
}

int main () 
{

	ConsoleApp app;
	bool isRunnig = true;
	int menuChoice = 0;

	do
	{
		std::cout << std::endl
			<< " 1 - Create person\n"
			<< " 2 - Print details for person.\n"
			<< " 3 - Stimulate persons.\n"
			<< " 4 - Start simulation.\n"
			<< " 5 - Stop simulation.\n"
			<< " 6 - Exit program.\n"
			<< " Enter your choice and press return: ";
		std::cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
			CreatePerson(app);
			break;
		case 2:
			PrintPersons(app);
			break;
		case 3:
			StimulatePersons(app);
			break;
		case 4:
			StartSimulation(app);
			break;
		case 5:
			StopSimulation(app);
			break;
		case 6:
			std::cout << "End of Program.\n";
			isRunnig = false;
			break;
		default:
			std::cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
		}
	} 
	while (isRunnig);

	return 0;
}

ConsoleApp::ConsoleApp() {
	// TODO Auto-generated constructor stub

}

ConsoleApp::~ConsoleApp() {
	// TODO Auto-generated destructor stub
}
