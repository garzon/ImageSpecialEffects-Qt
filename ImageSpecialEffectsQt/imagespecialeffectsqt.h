#ifndef IMAGESPECIALEFFECTSQT_H
#define IMAGESPECIALEFFECTSQT_H

#include <QtWidgets/QMainWindow>
#include "ui_imagespecialeffectsqt.h"

class ImageSpecialEffectsQt : public QMainWindow
{
	Q_OBJECT

public:
	ImageSpecialEffectsQt(QWidget *parent = 0);
	~ImageSpecialEffectsQt();
	void updateImage();
	void balanceRGB(int r,int g,int b);
public slots:
	void updateSize(int coeff);
	void transform(int coeff=-1);
	void openFile();
	void saveFile();
	void gray();
	void undoZoom();
	void openBalanceDialog();
private:
	Ui::ImageSpecialEffectsQtClass ui;
	bool _isLoaded; double _zoom;
	QImage *image,*displayImage;
};

#endif // IMAGESPECIALEFFECTSQT_H
