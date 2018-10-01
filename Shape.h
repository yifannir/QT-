#pragma once
#include <QPoint>
#include <QPainter>
#include <qevent.h>

class Shape	:public QObject
{
	Q_OBJECT

public:
	Shape();
	~Shape();
	virtual void dodata_p();
	virtual void dodata_m();
	virtual void dodata_r();
	virtual void doda_m_move();
	virtual void doda_p_move();
	virtual void draw(QPainter & painter);
	virtual bool isShot();
	virtual bool drawisOver();
	virtual int getType();
	virtual void save();
	virtual void load(std::string data);
};





