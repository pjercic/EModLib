#include "mainwindow.h"
#include <QGridLayout>
#include "stimulus.h"

PlusMinus::PlusMinus(QWidget *parent)
	: QWidget(parent) {

	mEmotionModel = new EmotionsModel::EmotionsModelLib();

	QPushButton *plsBtn = new QPushButton("+", this);
	QPushButton *minBtn = new QPushButton("-", this);

	QStringList personTypes = { "Person", "Empath", "Intellectual", "Gusher", "Rock" };

	// Create and position the button
	mCreatePerson = new QPushButton("Create Person", this);
	mCreatePerson->setEnabled(false);

	mPersonType = new QComboBox();
	mPersonType->addItems(personTypes);

	// Create and position the button
	mStimulate = new QPushButton("Stimulate", this);
	mStimulate->setEnabled(false);

	mArousal = new QSpinBox(this);
	mArousal->setEnabled(false);

	// Create and position the button
	mRun = new QPushButton("Run", this);
	mRun->setEnabled(false);

	mEmotion = new QLabel("0", this);
	mEmotion->setEnabled(false);

	QGridLayout *grid = new QGridLayout(this);
	grid->addWidget(plsBtn, 0, 0);
	grid->addWidget(minBtn, 0, 1);
	grid->addWidget(mPersonType, 1, 0);
	grid->addWidget(mCreatePerson, 1, 1);
	grid->addWidget(mArousal, 2, 0);
	grid->addWidget(mStimulate, 2, 1);
	grid->addWidget(mRun, 3, 0);
	grid->addWidget(mEmotion, 3, 1);

	setLayout(grid);

	connect(plsBtn, &QPushButton::clicked, this, &PlusMinus::OnPlus);
	connect(minBtn, &QPushButton::clicked, this, &PlusMinus::OnMinus);
	//connect(mPersonType, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged(int)), mCreatePerson, &QPushButton::setEnabled);
	connect(mPersonType, SIGNAL(currentIndexChanged(int)), this, SLOT(OnSelectPersonType(int)));
	connect(mCreatePerson, &QPushButton::clicked, this, &PlusMinus::OnCreatePerson);
	//connect(mArousal, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), mEmotion, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
	connect(mStimulate, &QPushButton::clicked, this, &PlusMinus::OnStimulate);
	connect(mRun, &QPushButton::clicked, this, &PlusMinus::OnRun);

}

void PlusMinus::OnPlus() {

	int val = mEmotion->text().toInt();
	val++;
	mEmotion->setText(QString::number(val));
}

void PlusMinus::OnMinus() {

	int val = mEmotion->text().toInt();
	val--;
	mEmotion->setText(QString::number(val));
}

void PlusMinus::OnSelectPersonType(int index) {

	if (index != 0)
		mCreatePerson->setEnabled(true);
}
void PlusMinus::OnCreatePerson() {

	mPersonID = mEmotionModel->createPerson(EmotionsModel::PersonLabel::EmpathType);

	// factory create person from combobox
	mStimulate->setEnabled(true);

	mArousal->setEnabled(true);

	// Create and position the button
	mRun->setEnabled(true);

	mEmotion->setEnabled(true);
}

void PlusMinus::OnStimulate() {

	// send stimulus to library
	mEmotionModel->inStimulus(mPersonID, mArousal->text().toDouble(), mArousal->text().toDouble());
}

void PlusMinus::OnRun() {

	// run for a second to see the values changing
	std::clock_t timerStart = std::clock();
	double duration = 0;

	while (duration < 1) {
		mEmotionModel->run();
		duration = (std::clock() - timerStart) / (double)CLOCKS_PER_SEC;
	}
	
	mEmotion->setText(QString(mEmotionModel->getEmotion(mPersonID)));
}