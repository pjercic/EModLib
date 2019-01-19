#include "mainwindow.h"
#include <QApplication>
#include <QProgressBar>
#include <QSlider>

/* int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
} */

#include <QPushButton>

#include <QTextStream>
#include <QDate>
#include <QTime>
int main(int argc, char **argv)
{
	QTextStream out(stdout);

	QDate dt1(2015, 4, 12);
	out << "The date is " << dt1.toString() << endl;

	QTime tm1(17, 30, 12, 55);
	out << "The time is " << tm1.toString("hh:mm:ss.zzz") << endl;
   
	QString a = "love";

	// QVector, QList, QStringList, QMap, QSet
	a.append(" chess");
	a.prepend("I ");

	out << a << endl;
	out << "The a string has " << a.count() 
		<< " characters" << endl;

	out << a.toUpper() << endl;    
	out << a.toLower() << endl;

   
	QApplication app (argc, argv);
	 
	PlusMinus window;

	window.resize(300, 190);
	window.setWindowTitle("Plus minus");
	window.show();

	return app.exec();
}
