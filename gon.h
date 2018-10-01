#pragma once
#include "Shape.h"
#include "global.h"
class Gon :
	public Shape
{
public:
	Gon();
	~Gon();
	void draw(QPainter & painter);
	bool isShot();
	void dodata_p();
	void dodata_m();
	void dodata_r();
	void doda_m_move();
	void doda_p_move();
	bool drawisOver();
	int getType();
	void save();
	void load(string data);

public:
	QPoint m_start_point, m_end_point, temp_mouse_press;
	QList<QPoint> gon_point_list;
	int type;
};

