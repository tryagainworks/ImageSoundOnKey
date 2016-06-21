#include "myqwidget.h"


myQWidget::myQWidget(QWidget *parent) : QWidget(parent)
{
	qsrand(1);
	fnLoadImagePaths();
	fnLoadSoundPaths();
}

void myQWidget::keyPressEvent(QKeyEvent *event)
{
	if(!blnWidgetsCreated)
	{
		fnCreateWidgets();
		intNoOfControls = vecLbl.count();
		this->setFocus();
		blnWidgetsCreated=true;
	}
	else
	{
		fnAction();
	}
}

void myQWidget::fnAction()
{

	qDebug()<<QString::number(qrand()%intNoOfControls);
	qDebug()<<QString::number(qrand()%intNoOfImage);
	qDebug()<<QString::number(qrand()%intNoOfSounds);

	QPixmap pix(vecImgPth[qrand()%intNoOfImage]);
	vecLbl[qrand()%intNoOfControls]->setPixmap(pix);
	if(!(mplayer.state()==QMediaPlayer::PlayingState))
	{
		mplayer.setMedia(QUrl::fromLocalFile(vecSoundPth[qrand()%intNoOfSounds]));
		mplayer.play();
	}
}

void myQWidget::fnLoadImagePaths()
{
	QDir dir(qApp->applicationDirPath()+"/Baby_Images");
    QStringList strLst= dir.entryList(QStringList("*.jpeg"), QDir::Files);
	for(QString str : strLst)
	{
		qDebug()<<dir.absolutePath()+"/"+str;
		vecImgPth.push_back(dir.absolutePath()+"/"+str);
	}
	intNoOfImage = vecImgPth.count();
}

void myQWidget::fnLoadSoundPaths()
{
	QDir dir(qApp->applicationDirPath()+"/Sounds");
    QStringList strLst= dir.entryList(QStringList("*.mp3"), QDir::Files);
	for(QString str : strLst)
	{
		qDebug()<<dir.absolutePath()+"/"+str;
		vecSoundPth.push_back(dir.absolutePath()+"/"+str);
	}
	intNoOfSounds = vecSoundPth.count();
}

void myQWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	qDebug()<<"Double clicked";
}

void myQWidget::showEvent(QShowEvent *event)
{

}

void myQWidget::fnCreateWidgets()
{
	QGridLayout *grd = new QGridLayout(this);
	int iCount=0, iRow=0,iCol=0;

	while(true)
	{
		iCount++;

		QLabel *lbl = new QLabel("1",this);
		lbl->setFixedSize(intFixedSize,intFixedSize);
		lbl->setScaledContents(true);
		lbl->setStyleSheet("QLabel { background-color : gray; color : blue; }");
		if(this->width()-(intFixedSize*iCol)<intFixedSize)
		{
			iRow++;
			iCol=0;
		}
		if(this->height()-(intFixedSize*(iRow+1))<intFixedSize)
		{
			delete lbl;
			break;
		}
		grd->addWidget(lbl,iRow,iCol++);
		vecLbl.push_back(lbl);
	}
	this->setLayout(grd);
}
