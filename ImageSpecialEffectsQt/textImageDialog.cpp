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
	QString tmp("");
	QImage *image=mainWin->displayImage;
	long x,y,z,h=image->height(),w=image->width(),t;
	#if CLASSIFY_BY_GRAY_VALUE
	for(y=0;y<image->height();y++){
		for(x=0;x<image->width();x++){
			double delta=255.0/n;
			double now=delta;
			int gray=myRGB::toGray(image->pixel(x,y)),p=0;
			while(true){
				if(gray<=now){
					if(p>=n) p=n-1;
					tmp.push_back(chars[p]);
					break;
				}
				p++;
				now+=delta;
			}
		}
		tmp.push_back('\n');
	}
	#endif
	// clustering method
	long **arr=clustering(image,n);
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			tmp.push_back(chars[arr[y][x]]);
		}
		tmp.push_back('\n');
	}
	for(x=0;x<h;x++){
		delete [] arr[x];
	}
	delete [] arr;
	ui.textImage->setText(tmp);
}

textImageDialog::~textImageDialog()
{

}
