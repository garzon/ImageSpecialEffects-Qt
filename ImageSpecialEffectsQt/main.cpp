#include "imagespecialeffectsqt.h"
#include <QtWidgets/QApplication>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[])
{
	srand(time(0));
	QApplication a(argc, argv);
	ImageSpecialEffectsQt w;
	w.show();
	return a.exec();
}
