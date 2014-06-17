#include "textImageDialog.h"

textImageDialog::textImageDialog(ImageSpecialEffectsQt *win,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose, true);
	mainWin=win;
}

void textImageDialog::accepted(){
	QString chars(ui.outputChar->text());
	long n=chars.length();
	if(n==0){
		QMessageBox::warning(this,"Error!","Please input the characters to output!",QMessageBox::StandardButton::Cancel);
		return;
	}
	QString *tmp=image2Text(mainWin->displayImage,&chars);
	ui.textImage->setText(*tmp);
	delete tmp;
}

textImageDialog::~textImageDialog()
{

}
