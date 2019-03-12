#include "QD3DRenderWidget.h"
# pragma execution_character_set("utf-8")

QD3DRenderWidget::QD3DRenderWidget(QWidget*parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_PaintOnScreen, true);
	setAttribute(Qt::WA_NativeWindow, true);
	setMouseTracking(true); // ÔÊÐíÊó±êÒÆ¶¯

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start();

}

QD3DRenderWidget::~QD3DRenderWidget()
{

}

void QD3DRenderWidget::Idle()
{

}

void QD3DRenderWidget::resizeEvent(QResizeEvent * e)
{
}

void QD3DRenderWidget::paintEvent(QPaintEvent * e)
{
	if (app.m_initialized)
	{
		app.m_engine->renderOneFrame();
		update();
	}
}

void QD3DRenderWidget::timerEvent(QTimerEvent* e)
{

}
