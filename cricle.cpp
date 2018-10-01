#include "cricle.h"
#include <math.h>
#include <fstream>
#include <iostream>

Cricle::Cricle()
{
	type = 3;
}


Cricle::~Cricle()
{
}

void Cricle::draw(QPainter & painter)
{
	QRectF rectangle1(m_start_point.x(), m_start_point.y(), m_end_point.x()- m_start_point.x(), m_end_point.y()- m_start_point.y());
	painter.drawArc(rectangle1,0,360*16);
}

bool Cricle::isShot()
{
	if (mouse_pos.x() >= fmin(m_start_point.x(), m_end_point.x()) && mouse_pos.y() >= fmin(m_start_point.y(), m_end_point.y()) && mouse_pos.x() <= fmax(m_start_point.x(), m_end_point.x()) && mouse_pos.y() <= fmax(m_start_point.y(), m_end_point.y()))
	{
		return true;
	}
	return false;
}

void Cricle::dodata_p()
{
	m_start_point = mouse_pos;
	m_end_point = mouse_pos;
}

void Cricle::dodata_m()
{
	m_end_point = mouse_pos;
}

void Cricle::dodata_r()
{
	m_end_point = mouse_pos;
}

void Cricle::doda_m_move()
{
	m_start_point = mouse_pos - temp_mouse_press + m_start_point;
	m_end_point = mouse_pos - temp_mouse_press + m_end_point;
	temp_mouse_press = mouse_pos;
}

void Cricle::doda_p_move()
{
	temp_mouse_press = mouse_pos;
}

bool Cricle::drawisOver()
{
	if (m_start_point != m_end_point)
	{
		return true;
	}
	return false;
}

int Cricle::getType()
{
	return type;
}

void Cricle::save()
{
	ofstream outfile;
	outfile.open(opath, ios::out | ios::app);
	outfile << type << endl;
	outfile << m_start_point.x() << " " << m_start_point.y() << " " << m_end_point.x() << " " << m_end_point.y() << endl;
	outfile.close();
}

void Cricle::load(string data)
{
	vector<int> nums;
	// string->char *

	char *s_input = (char *)data.c_str();
	const char * split = " ";
	// ÒÔ¶ººÅÎª·Ö¸ô·û²ð·Ö×Ö·û´®
	char *p = strtok(s_input, split);

	int a;
	while (p != NULL)
	{
		// char * -> int
		sscanf(p, "%d", &a);
		nums.push_back(a);
		p = strtok(NULL, split);
	}
	m_start_point = QPoint(nums[0], nums[1]);
	m_end_point = QPoint(nums[2], nums[3]);
}
