#ifndef __QD3DRenderWidget_H__
#define __QD3DRenderWidget_H__

#include <QObject>
#include <QWidget>
#include <QTimer>

#include "ExampleApplication.h"

class QD3DRenderWidget : public QWidget
{
	Q_OBJECT

public:

	QD3DRenderWidget(QWidget *parent = NULL);
	~QD3DRenderWidget();

	ExampleApplication app;

	virtual QPaintEngine* paintEngine() const { return NULL; } // ‘ –Ì Direct3D ‰÷»æ

	public slots:

	void Idle();


protected:

	QTimer* timer;
	QPoint curMousePt;
	virtual void resizeEvent(QResizeEvent *e);
	virtual void paintEvent(QPaintEvent *e);
	virtual void timerEvent(QTimerEvent *e);

};

#endif