#include "imagespecialeffectsqt.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include "myRGB.h"
#include "balanceDialog.h"

// --------------- CONSTRUCTOR ---------------------

ImageSpecialEffectsQt::ImageSpecialEffectsQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	_isLoaded=false;
	_zoom=1;
}

// ------------- MEMBER FUNCTIONS ------------------

void ImageSpecialEffectsQt::updateImage(){
	ui.label->setPixmap(QPixmap::fromImage(*displayImage));
}

void ImageSpecialEffectsQt::transform(int coeff){
	delete displayImage; double zoom;
	if(coeff==-1){
		zoom=_zoom;
	}else{
		zoom=coeff/10.0;
		_zoom=zoom;
	}
	long x,y,i,j,w=(long)(image->width()/zoom),h=(long)(image->height()/zoom);
	displayImage=new QImage(w,h,QImage::Format::Format_ARGB32);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			long b=(long)(x*zoom),c=(long)(y*zoom);
			myRGB sum; long area=0;
			for(i=b;i<b+zoom;i++){
				for(j=c;j<c+zoom;j++){
					sum+=image->pixel(i,j);
					area++;
				}
			}
			sum/=area;
			displayImage->setPixel(x,y,sum.toQRGB());
		}
	}
	updateImage();
}

void ImageSpecialEffectsQt::balanceRGB(int r,int g,int b){
	long x,y,w=image->width(),h=image->height(); 
	myRGB delta(r,g,b);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			myRGB sum;
			sum+=image->pixel(x,y);
			sum+=delta;
			sum.trim();
			image->setPixel(x,y,sum.toQRGB());
		}
	}
	transform();
}

// ------------ SLOTS -----------------

void ImageSpecialEffectsQt::openFile(){
	image=new QImage (QFileDialog::getOpenFileName());
	displayImage=new QImage(*image);
	ui.horizontalSlider->setEnabled(true);
	ui.pushButton_4->setEnabled(true);
	ui.pushButton_3->setEnabled(true);
	ui.pushButton_2->setEnabled(true);
	ui.pushButton_5->setEnabled(true);
	_isLoaded=true;
	transform();
}

void ImageSpecialEffectsQt::saveFile(){
	QString path=QFileDialog::getSaveFileName();;
	image->save(path);
}

void ImageSpecialEffectsQt::gray(){
	long x,y,w=image->width(),h=image->height();
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			myRGB sum;
			sum+=image->pixel(x,y);
			sum.vmul(0.3,0.59,0.11);
			long avg=sum.r+sum.g+sum.b;
			image->setPixel(x,y,qRgb(avg,avg,avg));
		}
	}
	transform();
}

void ImageSpecialEffectsQt::updateSize(int coeff){
	transform(coeff);
}

void ImageSpecialEffectsQt::undoZoom(){
	ui.horizontalSlider->setValue(10);
}

void ImageSpecialEffectsQt::openBalanceDialog(){
	balanceDialog *w=new balanceDialog(this);
	w->show();
}

// ------------ DELETE ----------------

ImageSpecialEffectsQt::~ImageSpecialEffectsQt()
{
	if(_isLoaded){
		delete image;
		delete displayImage;
	}
}
