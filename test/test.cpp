/*
 * test.cpp
 *
 *  Created on: Aug 15, 2018
 *      Author: b1-166er
 */

#define _USE_MATH_DEFINES

#include <cmath>

#include "EmotionsModelLib.h"
#include "PeopleFactory.h"

#include "stimulus.h"
#include "Personality.h"
#include "Mood.h"
#include "Affect.h"

#include "Empath.h"
#include "Gusher.h"
#include "Intellectual.h"
#include "Rock.h"

#include <gtest/gtest.h>

using namespace EmotionsModel;

// Specialized tests for specific features of an object
class PersonalityFixture : public ::testing::Test {

public:
	PersonalityFixture() {
		// initialization code here
		mPersonalityObj = new Personality(1.0, 1.0);
	}

	~PersonalityFixture() {
		// cleanup any pending stuff, but no exceptions allowed
		delete mPersonalityObj;
		mPersonalityObj = NULL;
	}

protected:
	void SetUp() override {
		// code here will execute just before the test ensues 
	}

	void TearDown() override {
		// code here will be called just after the test completes
		// ok to through exceptions from here if need be
	}

	Personality* mPersonalityObj;
	// put in any custom data members that you need 
};

TEST_F(PersonalityFixture, SanityTest) {

	// read
	EXPECT_DOUBLE_EQ(mPersonalityObj->GetArousal(), 1.0);
	EXPECT_DOUBLE_EQ(mPersonalityObj->GetValence(), 1.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    mPersonalityObj->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		mPersonalityObj->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_LT(mPersonalityObj->GetArousal(), 1.0);
	EXPECT_LT(mPersonalityObj->GetValence(), 1.0);

	// update
	mPersonalityObj->inStimulus(new stimulus(-1.0, -1.0));

	// read
	EXPECT_GT(mPersonalityObj->GetArousal(), 0.0);
	EXPECT_GT(mPersonalityObj->GetValence(), 0.0);

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    mPersonalityObj->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		mPersonalityObj->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_LT(mPersonalityObj->GetArousal(), 0.5);
	EXPECT_LT(mPersonalityObj->GetValence(), 0.5);

	// destroy
	delete mPersonalityObj;
	mPersonalityObj = NULL;

	EXPECT_FALSE(mPersonalityObj);
}

TEST_F(PersonalityFixture, PrecisionTest) {

	// read
	ASSERT_DOUBLE_EQ(mPersonalityObj->GetArousal(), 1.0);
	ASSERT_DOUBLE_EQ(mPersonalityObj->GetValence(), 1.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    mPersonalityObj->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		mPersonalityObj->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	ASSERT_DOUBLE_EQ(mPersonalityObj->GetArousal(), 0.5);
	ASSERT_DOUBLE_EQ(mPersonalityObj->GetValence(), 0.5);

	// update
	mPersonalityObj->inStimulus(new stimulus(-1.0, -1.0));

	// read
	ASSERT_DOUBLE_EQ(mPersonalityObj->GetArousal(), 0.5);
	ASSERT_DOUBLE_EQ(mPersonalityObj->GetValence(), 0.5);

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    mPersonalityObj->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		mPersonalityObj->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	ASSERT_LT(mPersonalityObj->GetArousal(), 0.0);
	ASSERT_LT(mPersonalityObj->GetValence(), 0.0);

	// destroy
	delete mPersonalityObj;
	mPersonalityObj = NULL;

	ASSERT_FALSE(mPersonalityObj);
}


// Not working for the abstract and generic types and intercaces, use typed tests
//// A new one of these params is create for each test
//class IAffectFixtureParams : public testing::TestWithParam<const IAffect*>
//{
//public:
//  virtual void SetUp(){}
//  virtual void TearDown(){}
//};
//
//INSTANTIATE_TEST_CASE_P(IAffectFixtureTest, IAffectFixtureParams, ::testing::Values(new Personality(), new Mood()));
//
//TEST_P(IAffectFixtureParams, SanityTest) {
//
//	IAffect* mPersonalityObj = GetParam();
//
//	// read
//	EXPECT_DOUBLE_EQ(mPersonalityObj->GetArousal(), 1.0);
//	EXPECT_DOUBLE_EQ(mPersonalityObj->GetValence(), 1.0);
//
//	// run for a while to see the values changing
//	std::clock_t timerStart = std::clock();
//	double duration = 0;
//
//	while (duration < 5) {
//		mPersonalityObj->run(0.5, 0.5);
//		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
//	}
//
//	// read
//	EXPECT_LT(mPersonalityObj->GetArousal(), 1.0);
//	EXPECT_LT(mPersonalityObj->GetValence(), 1.0);
//
//	// update
//	mPersonalityObj->inStimulus(new stimulus(-1.0, -1.0));
//
//	// read
//	EXPECT_GT(mPersonalityObj->GetArousal(), 0.0);
//	EXPECT_GT(mPersonalityObj->GetValence(), 0.0);
//
//	// run for a while to see the values changing
//	timerStart = std::clock();
//	duration = 0;
//
//	while (duration < 5) {
//		mPersonalityObj->run(0.5, 0.5);
//		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
//	}
//
//	// read
//	EXPECT_LT(mPersonalityObj->GetArousal(), 0.5);
//	EXPECT_LT(mPersonalityObj->GetValence(), 0.5);
//
//	// destroy
//	delete mPersonalityObj;
//	mPersonalityObj = NULL;
//
//	EXPECT_FALSE(mPersonalityObj);
//}

//// A new one of these params is create for each test
//class PersonalityFixtureParams : public testing::TestWithParam<const IAffect*>
//// - or - struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state> // For convenience, you can just derive the fixture class from ::testing::TestWithParam<T>, which itself is derived from both ::testing::Test and ::testing::WithParamInterface<T>
//{
//public:
//  virtual void SetUp(){}
//  virtual void TearDown(){}
//};
//
//INSTANTIATE_TEST_CASE_P(PersonalityParamsTest, PersonalityFixtureParams, ::testing::Values(new Personality(), new Mood(), new Affect()));
// 
//TEST_P(PersonalityFixtureParams, acceptsEekyAffects)
//{
//  ASSERT_TRUE(CallTest(GetParam()));
//}
//
//INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest,
//  testing::Values(
//  account_state{100,50,50,true},
//  account_state{100,200,100,false}
//  ));
//  
//TEST_P(WithdrawAccountTest, FinalBalance)
//{
//  auto as = GetParam();
//  auto success = account->withdraw(as.withdraw_amount);
//  EXPECT_EQ(as.final_balance,account->balance);
//  EXPECT_EQ(as.success,success);
//}


// Typed Tests - perfect for testing interfaces
template <typename T>
class IAffectTest : public ::testing::Test {
	
protected:
	// The ctor calls the factory function to create a prime table
	// implemented by T.
	IAffectTest() : value_(new T(0.5)) {}
	virtual ~IAffectTest() { delete value_; }

	IAffect* value_;
};

using IAffectTypes = ::testing::Types<Personality, Mood, Affect>;
TYPED_TEST_CASE(IAffectTest, IAffectTypes);

TYPED_TEST(IAffectTest, SanityTest) {
	
	// read
	EXPECT_DOUBLE_EQ(this->value_->GetArousal(), 0.0);
	EXPECT_DOUBLE_EQ(this->value_->GetValence(), 0.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_DOUBLE_EQ(this->value_->GetArousal(), 0.5);
	EXPECT_DOUBLE_EQ(this->value_->GetValence(), 0.5);

	// update
	this->value_->inStimulus(new stimulus(-1.0, -1.0));

	// read
	EXPECT_DOUBLE_EQ(this->value_->GetArousal(), 0.5);
	EXPECT_DOUBLE_EQ(this->value_->GetValence(), 0.5);

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_LT(this->value_->GetArousal(), 0.5);
	EXPECT_LT(this->value_->GetValence(), 0.5);

	// destroy
	delete this->value_;
	this->value_ = NULL;

	EXPECT_FALSE(this->value_);
}

TYPED_TEST(IAffectTest, PrecisionTest) {

	// read
	ASSERT_DOUBLE_EQ(this->value_->GetArousal(), 0.0);
	ASSERT_DOUBLE_EQ(this->value_->GetValence(), 0.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	ASSERT_DOUBLE_EQ(this->value_->GetArousal(), 0.5);
	ASSERT_DOUBLE_EQ(this->value_->GetValence(), 0.5);

	// update
	this->value_->inStimulus(new stimulus(-1.0, -1.0));

	// read
	ASSERT_DOUBLE_EQ(this->value_->GetArousal(), 0.5);
	ASSERT_DOUBLE_EQ(this->value_->GetValence(), 0.5);

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	ASSERT_LT(this->value_->GetArousal(), 0.0);
	ASSERT_LT(this->value_->GetValence(), 0.0);

	// destroy
	delete this->value_;
	this->value_ = NULL;

	ASSERT_FALSE(this->value_);
}

template <typename T>
class IPersonTest : public ::testing::Test {
	
protected:
	// The ctor calls the factory function to create a prime table
	// implemented by T.
	IPersonTest() : value_(new T()) {}
	virtual ~IPersonTest() { delete value_; }

	IPerson* value_;
};

using IPersonTypes = ::testing::Types<Empath, Gusher, Intellectual, Rock>;
TYPED_TEST_CASE(IPersonTest, IPersonTypes);

TYPED_TEST(IPersonTest, SanityTest) {
	
	double arrTempTest = 0;
	double valTempTest = 0;

	// read
	EXPECT_DOUBLE_EQ(this->value_->getAffect()->GetArousal(), 0.0);
	EXPECT_DOUBLE_EQ(this->value_->getAffect()->GetValence(), 0.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->getAffect()->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_GT(this->value_->getAffect()->GetArousal(), 0.0);
	EXPECT_GT(this->value_->getAffect()->GetValence(), 0.0);

	// update
	this->value_->inStimulus(new stimulus(-1.0, -1.0));

	// read
	EXPECT_GT(this->value_->getAffect()->GetArousal(), 0.0);
	EXPECT_GT(this->value_->getAffect()->GetValence(), 0.0);

	arrTempTest = this->value_->getAffect()->GetArousal();
	valTempTest = this->value_->getAffect()->GetValence();

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->getAffect()->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_LT(this->value_->getAffect()->GetArousal(), arrTempTest);
	EXPECT_LT(this->value_->getAffect()->GetValence(), valTempTest);

	// destroy
	delete this->value_;
	this->value_ = NULL;

	EXPECT_FALSE(this->value_);
}

TYPED_TEST(IPersonTest, PrecisionTest) {

	double arrTempTest = 0;
	double valTempTest = 0;

	// read
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetArousal(), 0.0);
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetValence(), 0.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->getAffect()->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetArousal(), 0.5);
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetValence(), 0.5);

	// update
	this->value_->inStimulus(new stimulus(-1.0, -1.0));

	// read
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetArousal(), 0.5);
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetValence(), 0.5);

	arrTempTest = this->value_->getAffect()->GetArousal();
	valTempTest = this->value_->getAffect()->GetValence();

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    this->value_->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		this->value_->getAffect()->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	ASSERT_LT(this->value_->getAffect()->GetArousal(), arrTempTest);
	ASSERT_LT(this->value_->getAffect()->GetValence(), valTempTest);

	// destroy
	delete this->value_;
	this->value_ = NULL;

	ASSERT_FALSE(this->value_);
}

TYPED_TEST(IPersonTest, EmotionsLabelEquivalentClassTest) {
	
	// Equivalent class test
	// read
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetArousal(), 0.0);
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetValence(), 0.0);
	
	// enum EmotionLabel { Trust, Happines, Anticipation, Anger, Disgust, Sadness, Suprise, Fear, None };
	double arrVals[] = {0.0, 0.5, 1.0, 0.5, 0.0, -0.5, -1.0, -0.5};
	double valVals[] = {1.0, 0.5, 0.0, -0.5, -1.0, -0.5, 0.0, 0.5};
	
	// run for a while to see the values changing
	std::clock_t timerStart;
	double duration;

	for (int i = 0; i < 8; i++) {
		
		timerStart = std::clock();
		duration = 0;
		
        this->value_->inStimulus(new stimulus(0.5, 0.5));

		while (duration < 5) {
			this->value_->getAffect()->run(nullptr);
			duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
		}

		// read
		EXPECT_EQ(this->value_->getEmotion(), i) << "Equivalent class test";
	}
}

TYPED_TEST(IPersonTest, EmotionsLabelBoundaryVolumeTest) {

	// Equivalent class test
	// read
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetArousal(), 0.0);
	ASSERT_DOUBLE_EQ(this->value_->getAffect()->GetValence(), 0.0);

	// run for a while to see the values changing
	std::clock_t timerStart;
	double duration;

	// Boundary volume test

	// enum EmotionLabel { Trust, Happines, Anticipation, Anger, Disgust, Sadness, Suprise, Fear, None };	
	double radVals[] = { M_PI / 8, 3 * M_PI / 8, (M_PI / 2) + (M_PI / 8), (M_PI / 2) + (3 * M_PI / 8), (M_PI)+(M_PI / 8), (M_PI)+(3 * M_PI / 8), (3 * M_PI / 2) + (M_PI / 8), (3 * M_PI / 2) + (3 * M_PI / 8) };
	// + 0.0,0.0 (should test three points one just before the border, border and just after the border)

	double arrValsBounds[9] = { 0.0 };
	double valValsBounds[9] = { 0.0 };
	for (int i = 0; i < 8; i++) {
		arrValsBounds[i] = sin(radVals[i]);
		valValsBounds[i] = cos(radVals[i]);
	}

	for (int i = 0; i < 8; i++) {

		timerStart = std::clock();
		duration = 0;

        this->value_->inStimulus(new stimulus(0.5, 0.5));

		while (duration < 5) {
			this->value_->getAffect()->run(nullptr);
			duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
		}

		// read
		EXPECT_EQ(this->value_->getEmotion(), i) << "Boundary volume test";
	}
}
//
// Only if you want to keep the test definition template pattern in the header file
// and instantiate tests in the cpp file, when you define the types later on
//template <class T>
//class IAffectTest2 : public IAffectTest<T> {
//};
//
//// Then, declare the test case.  The argument is the name of the test
//// fixture, and also the name of the test case (as usual).  The _P
//// suffix is for "parameterized" or "pattern".
//TYPED_TEST_CASE_P(IAffectTest2);
//
//TYPED_TEST_P(IAffectTest2, SanityTest) {
//
//	EXPECT_GT(this->value_->GetArousal(), 0.0);
//}
//
//TYPED_TEST_P(IAffectTest2, PrecisionTest) {
//
//	EXPECT_GT(this->value_->GetArousal(), 0.0);
//}
//
//REGISTER_TYPED_TEST_CASE_P(IAffectTest2, SanityTest, PrecisionTest);
//
//typedef ::testing::Types<Personality, Mood> IAffectParamTypes;
//INSTANTIATE_TYPED_TEST_CASE_P(MyParam, IAffectTest2, IAffectParamTypes);


// Individual tests
TEST(PersonalityTest, PersonalityInitializationTest) {

	// Create
	Personality* personalityObj = new Personality(1.0, 1.0);

	// read
	EXPECT_DOUBLE_EQ(1.0, personalityObj->GetArousal());
	EXPECT_DOUBLE_EQ(1.0, personalityObj->GetValence());

	// update
	personalityObj->inStimulus(new stimulus(0.5, 0.5));

	// read
	EXPECT_DOUBLE_EQ(0.5, personalityObj->GetArousal());
	EXPECT_DOUBLE_EQ(0.5, personalityObj->GetValence());

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    personalityObj->inStimulus(new stimulus(0.5, 0.5));

	while (duration < 5) {
		personalityObj->run(nullptr);
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

	// read
	EXPECT_GT(0.5, personalityObj->GetArousal());
	EXPECT_GT(0.5, personalityObj->GetValence());

	// destroy
	delete personalityObj;
	//personalityObj = NULL;

	EXPECT_FALSE(personalityObj);

	// read
	//personalityObj->GetArousal();
}

TEST(PeopleFactoryTest, PeopleFactorySanityTest) {

	// Create
	PeopleFactory* peopleFactoryObj = new PeopleFactory();
	
	// enum PersonLabel { IntellectualType, EmpathType, RockType, GusherType };
	// Empath, Gusher, Intellectual, Rock
	IPerson* pers1 = PeopleFactory::getPerson(EmotionsModel::IntellectualType);
	IPerson* pers2 = peopleFactoryObj->getPerson(EmotionsModel::IntellectualType);
	
	// Use GMock
	//EXPECT_EQ(typeid(Intellectual), typeid(std::result_of<Intellectual>::type));
	//It will be checked at compile-time. 
    //::testing::StaticAssertTypeEq<Intellectual, std::result_of(Intellectual)>(); 
	
	EXPECT_TRUE(pers1 != nullptr);
	EXPECT_TRUE(pers2 != nullptr);

	delete pers1;
	delete pers2;

	pers1 = PeopleFactory::getPerson(EmotionsModel::EmpathType);
	pers2 = peopleFactoryObj->getPerson(EmotionsModel::EmpathType);

	EXPECT_TRUE(pers1 != nullptr);
	EXPECT_TRUE(pers2 != nullptr);

	delete pers1;
	delete pers2;

	pers1 = PeopleFactory::getPerson(EmotionsModel::RockType);
	pers2 = peopleFactoryObj->getPerson(EmotionsModel::RockType);

	EXPECT_TRUE(pers1 != nullptr);
	EXPECT_TRUE(pers2 != nullptr);

	delete pers1;
	delete pers2;

	pers1 = PeopleFactory::getPerson(EmotionsModel::GusherType);
	pers2 = peopleFactoryObj->getPerson(EmotionsModel::GusherType);

	EXPECT_TRUE(pers1 != nullptr);
	EXPECT_TRUE(pers2 != nullptr);

	delete pers1;
	delete pers2;

	delete peopleFactoryObj;
	peopleFactoryObj = NULL;
}

TEST(EmotionModelSystemTest, EmotionModelSystemSanityTest) {

	// Create
	EmotionsModelLib* emotionModelObj = new EmotionsModelLib();

	// read
	EXPECT_TRUE(emotionModelObj->getAffect(0) == NULL);

	// create
	int persId = emotionModelObj->createPerson(PersonLabel::EmpathType);
	EXPECT_GE(persId, 0);

	// read
	EXPECT_TRUE(emotionModelObj->getAffect(persId) != NULL);

	// update
	emotionModelObj->inStimulus(persId, -1.0, -1.0);

	// read
	EXPECT_TRUE(emotionModelObj->getAffect(persId) != NULL);

	// destroy
	/*delete mPersonalityObj;
	mPersonalityObj = NULL;

	EXPECT_FALSE(mPersonalityObj);*/
}

TEST(EmotionModelSystemTest, EmotionModelSystemRunTest) {

	// Create
	EmotionsModelLib* emotionModelObj = new EmotionsModelLib();
	int persId = emotionModelObj->createPerson(PersonLabel::EmpathType);

	double arrTempTest = 0;
	double valTempTest = 0;

	// read
	EXPECT_DOUBLE_EQ(emotionModelObj->getAffect(persId)->GetArousal(), 0.0);
	EXPECT_DOUBLE_EQ(emotionModelObj->getAffect(persId)->GetValence(), 0.0);

	// run for a while to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

    emotionModelObj->Start();
	while (duration < 5) {
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}

    emotionModelObj->Stop();

	// read
	EXPECT_DOUBLE_EQ(emotionModelObj->getAffect(persId)->GetArousal(), 0.0);
	EXPECT_DOUBLE_EQ(emotionModelObj->getAffect(persId)->GetValence(), 0.0);

	// update
	emotionModelObj->inStimulus(persId, -1.0, -1.0);

	// read
	EXPECT_DOUBLE_EQ(emotionModelObj->getAffect(persId)->GetArousal(), 0.0);
	EXPECT_DOUBLE_EQ(emotionModelObj->getAffect(persId)->GetValence(), 0.0);

	arrTempTest = emotionModelObj->getAffect(persId)->GetArousal();
	valTempTest = emotionModelObj->getAffect(persId)->GetValence();

	// run for a while to see the values changing
	timerStart = std::clock();
	duration = 0;

    emotionModelObj->Start();
	while (duration < 5) {
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}
    emotionModelObj->Stop();

	// read
	EXPECT_LT(emotionModelObj->getAffect(persId)->GetArousal(), arrTempTest);
	EXPECT_LT(emotionModelObj->getAffect(persId)->GetValence(), valTempTest);

	// destroy
	delete emotionModelObj;
	emotionModelObj = NULL;

	EXPECT_FALSE(emotionModelObj);
}

TEST(PersonalityTest, DISABLE_PersonalityEmotionTest) {

	// Create
	Personality* personalityObj = new Personality(1.0, 1.0);

	// Set affect - in the class definition
	//if (num < 0.0) {
	//	std::cerr << "Error: Negative Input\n";
	//	exit(-1);
	//}

	ASSERT_EXIT(personalityObj->inStimulus(new stimulus(2.0, 2.0)), ::testing::ExitedWithCode(-1), "Error: Negative Input");
}

TEST(PersonFactoryTest, PositiveAffect){

	IPerson* b = PeopleFactory::getPerson(EmotionsModel::EmpathType);
	ASSERT_GT(b->getEmotion(), 0);
	delete b;
	b = NULL;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


