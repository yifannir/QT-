#include "Line.h"
#include <fstream>
#include <iostream>


void Line::draw(QPainter & painter)
{
	painter.drawLine(m_start_point, m_end_point);
}

bool Line::isShot()
{
	double A, B, C, dis;
	A = m_end_point.y() - m_start_point.y();
	B = m_start_point.x() - m_end_point.x();
	C = m_end_point.x() * m_start_point.y() - m_start_point.x() * m_end_point.y();

	dis = abs(A * mouse_pos.x() + B * mouse_pos.y() + C) / sqrt(A * A + B * B);
	if (dis <= 5 && mouse_pos.x() <= fmax(m_start_point.x(), m_end_point.x()) && mouse_pos.x() >= fmin(m_start_point.x(), m_end_point.x())) {
		return true;
	}
	return false;
}

Line::Line()
{
	type = 2;
}

Line::~Line()
{
}

void Line::dodata_p()
{
	m_start_point = mouse_pos;
	m_end_point = mouse_pos;
}

void Line::dodata_m()
{
	m_end_point = mouse_pos;
}

void Line::dodata_r()
{
	m_end_point = mouse_pos;
}

void Line::doda_m_move()
{
	m_start_point = mouse_pos - temp_mouse_press + m_start_point;
	m_end_point = mouse_pos - temp_mouse_press + m_end_point;
	temp_mouse_press = mouse_pos;
}

void Line::doda_p_move()
{
	temp_mouse_press = mouse_pos;
}

bool Line::drawisOver()
{
	if (m_start_point != m_end_point)
	{
		return true;
	}
	return false;
}

int Line::getType()
{
	return type;
}

void Line::save()
{
	ofstream outfile;
	outfile.open(opath, ios::out | ios::app);
	outfile << type << endl;
	outfile << m_start_point.x() << " " << m_start_point.y() << " " << m_end_point.x() << " " << m_end_point.y() << endl;
	outfile.close();
}

void Line::load(string data)
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
