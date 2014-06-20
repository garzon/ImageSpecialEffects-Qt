#include "imagespecialeffectsqt.h"

#define caller(funcname,var) { QImage *del=var;var=funcname(var);delete del; }
#define CALLER(funcname) caller(funcname,image);transformDisplayImage();


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

void ImageSpecialEffectsQt::transformDisplayImage(int coeff){
	lastImage=displayImage; ui.pushButton_13->setEnabled(true);
	double zoom;
	if(coeff==-1){
		zoom=_zoom;
	}else{
		zoom=coeff/10.0;
		_zoom=zoom;
	}
	displayImage=transform(image,zoom);
	updateImage();
}

void ImageSpecialEffectsQt::balanceRGB(int r,int g,int b){
	long x,y,w=image->width(),h=image->height(); 
	myRGB<> delta(r,g,b);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			myRGB<> sum;
			sum+=image->pixel(x,y);
			sum+=delta;
			sum.trim();
			image->setPixel(x,y,sum.toQRGB());
		}
	}
	transformDisplayImage();
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
	ui.btnTextImage->setEnabled(true);
	ui.pushButton_6->setEnabled(true);
	ui.pushButton_7->setEnabled(true);
	ui.pushButton_8->setEnabled(true);
	ui.pushButton_9->setEnabled(true);
	ui.pushButton_10->setEnabled(true);
	ui.pushButton_11->setEnabled(true);
	ui.pushButton_12->setEnabled(true);
	ui.pushButton_13->setEnabled(false);
	_isLoaded=true;
	transformDisplayImage();
}

void ImageSpecialEffectsQt::undo(){
	image=lastImage;
	lastImage=new QImage();
	undoZoom();
	transformDisplayImage();
	ui.pushButton_13->setEnabled(false);
}

void ImageSpecialEffectsQt::saveFile(){
	QString path=QFileDialog::getSaveFileName();
	image->save(path);
}

void ImageSpecialEffectsQt::doNoLightness(){
	CALLER(noLightnessRGB);
}

void ImageSpecialEffectsQt::doBinarize(){
	CALLER(binarize);
}

void ImageSpecialEffectsQt::doLab(){
	CALLER(lab);
}

void ImageSpecialEffectsQt::doGray(){
	CALLER(gray);
}

void ImageSpecialEffectsQt::doSalience(){
	CALLER(salience);
}

void ImageSpecialEffectsQt::updateSize(int coeff){
	transformDisplayImage(coeff);
}

void ImageSpecialEffectsQt::undoZoom(){
	ui.horizontalSlider->setValue(10);
}

void ImageSpecialEffectsQt::openBalanceDialog(){
	balanceDialog *w=new balanceDialog(this);
	w->show();
}

void ImageSpecialEffectsQt::openTextImageDialog(){
	textImageDialog *w=new textImageDialog(this);
	w->show();
}

void ImageSpecialEffectsQt::doNoiseReduce(){
	long i;
	for(i=0;i<10;i++)
		caller(noiseReduce,image);
	transformDisplayImage();
}

void ImageSpecialEffectsQt::doEdgeDetection(){
	doNoiseReduce();
	delete image;
	image=edgeDetection(displayImage);
	undoZoom();
	transformDisplayImage();
}

void ImageSpecialEffectsQt::doEdgeSmoothing(){
	caller(binarize,image);
	caller(edgeSmoothing,image);
	transformDisplayImage();
}

// ------------ DELETE ----------------

ImageSpecialEffectsQt::~ImageSpecialEffectsQt()
{
	if(_isLoaded){
		delete image;
		delete displayImage;
	}
}

