#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>

#include "EmotionsModelLib.h"

class PlusMinus : public QWidget {

	Q_OBJECT

public:
	PlusMinus(QWidget *parent = 0);

	private slots:
	void OnPlus();
	void OnMinus();
	void OnSelectPersonType(int);
	void OnCreatePerson();
	void OnStimulate();
	void OnRun();

private:
	QPushButton* mCreatePerson;
	QPushButton* mRun;
	QPushButton* mStimulate;
	QComboBox* mPersonType;
	QSpinBox* mArousal;
	//QSpinBox* mValence;
	QLabel* mEmotion;
	// Icon for emotion

	EmotionsModel::EmotionsModelLib* mEmotionModel;
	int mPersonID;
};
#endif // MAINWINDOW_H