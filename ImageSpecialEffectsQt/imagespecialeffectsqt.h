#ifndef IMAGESPECIALEFFECTSQT_H
#define IMAGESPECIALEFFECTSQT_H

#include <QtWidgets/QMainWindow>
#include "ui_imagespecialeffectsqt.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include "myRGB.h"
#include "funclib.h"
#include "balanceDialog.h"
#include "textImageDialog.h"

class ImageSpecialEffectsQt : public QMainWindow
{
	Q_OBJECT

public:
	ImageSpecialEffectsQt(QWidget *parent = 0);
	~ImageSpecialEffectsQt();
	void updateImage();
	void balanceRGB(int r,int g,int b);
	QImage *image,*displayImage;
public slots:
	void updateSize(int coeff);
	void transformDisplayImage(int coeff=-1);
	void openFile();
	void saveFile();
	void doGray();
	void doEdgeDetection();
	void undoZoom();
	void openBalanceDialog();
	void openTextImageDialog();
private:
	Ui::ImageSpecialEffectsQtClass ui;
	bool _isLoaded; double _zoom;
};

#endif // IMAGESPECIALEFFECTSQT_H
