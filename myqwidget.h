#ifndef MYQWIDGET_H
#define MYQWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QVector>
#include <qdebug.h>
#include <QKeyEvent>
#include <QGridLayout>
#include <QLabel>
#include <QDir>
#include <QApplication>
#include <QPixmap>
#include <QTransform>
#include <QMediaPlayer>

class myQWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myQWidget(QWidget *parent = 0);

signals:

public slots:

private:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void showEvent(QShowEvent *event);
    int intNoOfControls=0,intNoOfImage=0, intNoOfSounds=0;
    void fnCreateWidgets();
    bool blnWidgetsCreated=false;
    void fnAction();
    QVector<QLabel*> vecLbl;
    QVector<QString> vecImgPth, vecSoundPth;
    void fnLoadImagePaths();
    const int intFixedSize=175;
    QMediaPlayer mplayer;
    void fnLoadSoundPaths();
};

#endif // MYQWIDGET_H
