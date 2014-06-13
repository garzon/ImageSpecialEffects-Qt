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
	myRGB *centerPoint=new myRGB[n];
	long **arr=new long*[h];
	for(x=0;x<h;x++){
		arr[x]=new long[w];
	}
	for(x=0;x<n;x++)
		centerPoint[x].randomize();
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			long mindist=999999999,tmp;
			for(z=0;z<n;z++){
				tmp=centerPoint[z].distance(image->pixel(x,y));
				if(tmp<mindist){
					mindist=tmp;
					arr[y][x]=z;
				}
			}
		}
	}
	long *counter=new long[n];
	for(t=0;t<50;t++){
		for(z=0;z<n;z++){ centerPoint[z].clear(); counter[z]=0; }
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter[arr[y][x]]++;
				centerPoint[arr[y][x]]+=image->pixel(x,y);
			}
		}
		for(z=0;z<n;z++) if(counter[z]) centerPoint[z]/=counter[z]; else centerPoint[z].randomize();
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				long mindist=999999999,tmp;
				for(z=0;z<n;z++){
					tmp=centerPoint[z].distance(image->pixel(x,y));
					if(tmp<mindist){
						mindist=tmp;
						arr[y][x]=z;
					}
				}
			}
		}
	}
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			tmp.push_back(chars[arr[y][x]]);
		}
		tmp.push_back('\n');
	}
	delete [] centerPoint;
	delete [] counter;
	for(x=0;x<w;x++){
		delete [] arr[x];
	}
	delete [] arr;
	ui.textImage->setText(tmp);
}

textImageDialog::~textImageDialog()
{

}
