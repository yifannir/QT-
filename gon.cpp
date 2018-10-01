#include "gon.h"

#include <fstream>
#include <iostream>
Gon::Gon()
{
	type = 4;
}


Gon::~Gon()
{
}

void Gon::draw(QPainter & painter)
{
	for (int i = 0; i < gon_point_list.size()-1; i++)
	{
		painter.drawLine(gon_point_list[i], gon_point_list[i+1]);
	}
}

bool Gon::isShot()
{
	return false;
}

void Gon::dodata_p()
{
	if (gon_point_list.isEmpty())
	{
		m_start_point = mouse_pos;
		//设置最后的临时位
		gon_point_list.append(m_start_point);
	}
	gon_point_list.append(mouse_pos);
	m_end_point = mouse_pos;
}

void Gon::dodata_m()
{
	
	m_end_point = mouse_pos;
	gon_point_list.last() = m_end_point;
}

void Gon::dodata_r()
{
	m_start_point = m_end_point;
	m_end_point = mouse_pos;
	int is_over = (int)pow(gon_point_list.last().x() - m_end_point.x(), 2) + pow(gon_point_list.last().y() - m_end_point.y(), 2);
	if (is_over < 10 && gon_point_list.size() >2)
	{
		//松开时的点是否加入
		//gon_point_list.append(m_end_point);
	}
	gon_point_list.append(m_end_point);
}

void Gon::doda_m_move()
{
}

void Gon::doda_p_move()
{
}

bool Gon::drawisOver()
{
	int is_over = (int)pow(gon_point_list.last().x() - gon_point_list.first().x(), 2) + pow(gon_point_list.last().y() - gon_point_list.first().y(), 2);
	if (is_over < 10 && gon_point_list.size() >2)
	{
		return true;
	}
	return false;
}

int Gon::getType()
{
	return type;
}

void Gon::save()
{
	ofstream outfile;
	outfile.open(opath, ios::out | ios::app);
	outfile << type << endl;
	for (int i = 0; i < gon_point_list.size(); i++)
	{
		outfile << gon_point_list[i].x() << " " << gon_point_list[i].y() << " ";
	}
	outfile << endl;
	
	outfile.close();
}

void Gon::load(string data)
{
	vector<int> nums;
	// string->char *

	char *s_input = (char *)data.c_str();
	const char * split = " ";
	// 以逗号为分隔符拆分字符串
	char *p = strtok(s_input, split);

	int a;
	while (p != NULL)
	{
		// char * -> int
		sscanf(p, "%d", &a);
		nums.push_back(a);
		p = strtok(NULL, split);
	}
	for (int i = 0; i < nums.size(); i = i +2)
	{
		gon_point_list.append(QPoint(nums[i], nums[i + 1]));
	}
}
