#include "imagespecialeffectsqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ImageSpecialEffectsQt w;
	w.show();
	return a.exec();
}
