#include "balanceDialog.h"

balanceDialog::balanceDialog(ImageSpecialEffectsQt *win,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	mainWin=win;
}

void balanceDialog::rejected(){
	this->close();
	this->~balanceDialog();
}

void balanceDialog::accepted(){
	int r=ui.rSlider->value();
	int g=ui.gSlider->value();
	int b=ui.bSlider->value();
	mainWin->balanceRGB(r,g,b);
	rejected();
}

balanceDialog::~balanceDialog()
{

}
