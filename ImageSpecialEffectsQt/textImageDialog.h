#ifndef TEXTIMAGEDIALOG_H
#define TEXTIMAGEDIALOG_H

#include <QWidget>
#include "ui_textImageDialog.h"
#include "imagespecialeffectsqt.h"

class ImageSpecialEffectsQt;

class textImageDialog : public QWidget
{
	Q_OBJECT

public:
	textImageDialog(ImageSpecialEffectsQt *win,QWidget *parent = 0);
	~textImageDialog();
private slots:
	void accepted();
private:
	Ui::textImageDialog ui;
	ImageSpecialEffectsQt *mainWin;
};

#endif // TEXTIMAGEDIALOG_H
