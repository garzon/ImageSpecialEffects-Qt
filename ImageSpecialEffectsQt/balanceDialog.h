#ifndef BALANCEDIALOG_H
#define BALANCEDIALOG_H

#include <QWidget>
#include "ui_balanceDialog.h"
#include "imagespecialeffectsqt.h"

class ImageSpecialEffectsQt;

class balanceDialog : public QWidget
{
	Q_OBJECT

public:
	balanceDialog(ImageSpecialEffectsQt *win,QWidget *parent = 0);
	~balanceDialog();
private slots:
	void accepted();
	void rejected();
private:
	Ui::balanceDialog ui;
	ImageSpecialEffectsQt *mainWin;
};

#endif // BALANCEDIALOG_H
