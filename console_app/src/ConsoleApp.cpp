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
    unsigned int nrPersons = 0;
    int type = 0;

    std::cout << "IntellectualType - 0 " << std::endl;
    std::cout << "EmpathType - 1" << std::endl;
    std::cout << "RockType - 2" << std::endl;
    std::cout << "GusherType - 3" << std::endl;
    std::cout << "Choose personality type: ";
    std::cin >> type;
	std::cout << std::endl << "Chose how many: ";
	std::cin >> nrPersons;

    std::cout << "Persons added from ID: " << app.personsList.empty() ? 0 : app.personsList.back();

	for (unsigned int i = 0; i < nrPersons; i++)
	{        
		app.personsList.push_back(app.emotionModelObj.createPerson(static_cast<PersonLabel>(type)));
	}

    std::cout << " till ID: " << app.personsList.back();
}

void PrintPersons(ConsoleApp& app)
{
    std::cout << "ID" << "\tAr" << "\tVa" << "\tEm" << std::endl;
	for (unsigned int i = 0; i < app.personsList.size(); i++)
	{
		std::cout << app.personsList[i] << "\t" << app.emotionModelObj.getAffect(app.personsList[i])->GetArousal() << "\t" << app.emotionModelObj.getAffect(app.personsList[i])->GetArousal() << "\t" << app.emotionModelObj.getEmotion(app.personsList[i]) << std::endl;
	}
}

void StimulatePersons(ConsoleApp& app)
{
    double x,y = 0.0;

    std::cout << std::endl << "Define arousal: ";
    std::cin >> x;
    std::cout << std::endl << "Define valence: ";
    std::cin >> y;

	for (unsigned int i = 0; i < app.personsList.size(); i++)
	{
		app.emotionModelObj.inStimulus(app.personsList[i], x, y);
	}

    std::cout << app.personsList.size() << " stimulated with " << "arousal: " << x << "valence: " << y << std::endl;
}

void StartSimulation(ConsoleApp& app)
{
	app.emotionModelObj.Start();
    app.mSimulationStarted = true;
    std::cout << "Simulation started." << std::endl;
}

void StopSimulation(ConsoleApp& app)
{
	app.emotionModelObj.Stop();
    app.mSimulationStarted = false;
    std::cout << "Simulation stopped." << std::endl;
}

int main () 
{

	ConsoleApp app;
	bool isRunnig = true;
	int menuChoice = 0;

	do
	{
		std::cout << std::endl
			<< " 1 - Create person(s)\n"
			<< " 2 - Print details for persons.\n"
			<< " 3 - Stimulate person(s).\n"
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
            if (app.mSimulationStarted) 
                StopSimulation(app);

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

ConsoleApp::ConsoleApp() : mSimulationStarted(false) {
	// TODO Auto-generated constructor stub

}

ConsoleApp::~ConsoleApp() {
	// TODO Auto-generated destructor stub
}
