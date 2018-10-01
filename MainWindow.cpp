#include "MainWindow.h"
#include <iostream>
#include <fstream>
#include "Rect.h"
#include "Line.h"
#include "cricle.h"
#include "gon.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.save, SIGNAL(clicked()), ui.text, SLOT(on_save_clicked()));
	connect(ui.read, SIGNAL(clicked()), ui.text, SLOT(on_read_clicked()));
	shape = NULL;
}


void MainWindow::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	painter.setBrush(Qt::white);
	painter.drawRect(0, 0, size().width(), size().height());
	
	foreach(Shape * shape, shapeList) {
		shape->draw(painter);
	}
	if (shape) {
		shape->draw(painter);
	}
}


void MainWindow::mousePressEvent(QMouseEvent * event)
{
	mouse_pos = event->pos();
	switch (typeAction)
	{
	case 1:
		//»æÖÆ
		if (shape != NULL && shape->drawisOver() == false) {}
		else
		{
			switch (typeShape)
			{
			case 1:
				shape = new Rect();
				break;
			case 2:
				shape = new Line();
				break;
			case 3:
				shape = new Cricle();
				break;
			case 4:
				shape = new Gon();
			default:
				break;
			}
		}
		if (typeShape != NULL) {
			perm = false;
			shape->dodata_p();
		}
		break;
	case 2:
		//ÒÆ¶¯
		for (int i = 0; i < shapeList.size(); i++)
		{
			if (shapeList[i]->isShot())
			{
				shapeList[i]->doda_p_move();
				break;
			}
		}
		break;
	default:
		break;
	}
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
	mouse_pos = event->pos();
	switch (typeAction)
	{
	case 1:
		if (shape && !perm) {
			shape->dodata_m();
		}
		break;
	case 2:
		for (int i = 0; i < shapeList.size(); i++)
		{
			if (shapeList[i]->isShot())
			{
				shapeList[i]->doda_m_move();
				break;
			}
		}
		break;
	default:
		break;
	}
	update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event)
{
	mouse_pos = event->pos();
	update();
	switch (typeAction)
	{
	case 1:
		shape->dodata_r();
		if (shape->drawisOver())
		{
			perm = true;
			shapeList.push_back(shape);
			break;
		}
	case 2:
		break;
	default:
		break;
	}
	
}

void MainWindow::on_line_clicked()
{
	typeShape = 2;
}

void MainWindow::on_circle_clicked()
{
	typeShape = 3;
}

void MainWindow::on_box_clicked() {
	typeShape = 1;
}

void MainWindow::on_gon_clicked() {
	typeShape = 4;
}

void MainWindow::on_draw_clicked() {
	typeAction = 1;
}

void MainWindow::on_move_clicked() {
	typeAction = 2;
}

void MainWindow::on_save_clicked() {
	typeAction = 3;
	QString strText = ui.text->toPlainText();
	saveData(strText);
}

void MainWindow::on_read_clicked() {
	typeAction = 4;
	QString strText = ui.text->toPlainText();
	loadData(strText);
}


void MainWindow::saveData(QString path) {
	ofstream file;
	file.open(opath, ios::out | ios::binary | ios::ate);
	file.close();
	for (int i = 0; i < shapeList.size(); i++)
	{
		shapeList[i]->save();
	}

}

void MainWindow::loadData(QString path) {

	ifstream infile;
	shapeList.clear();
	shape = NULL;
	infile.open(ipath, ios::in);
	string line;
	vector<string>  words;
	while (getline(infile, line))
	{
		words.push_back(line);
	}
	for (int i = 0; i < words.size();i = i+2)
	{
		Shape *rect = new Rect();
		Shape *li = new Line();
		Shape *cir = new Cricle();
		Shape *gon = new Gon();
		int a = atoi(words[i].c_str());
		switch (a)
		{
		case 1:		
			rect->load(words[i+1]);
			shapeList.append(rect);
			break;
		case 2:			
			li->load(words[i + 1]);
			shapeList.append(li);
			break;
		case 3:			
			cir->load(words[i + 1]);
			shapeList.append(cir);
			break;
		case 4:
			gon->load(words[i + 1]);
			shapeList.append(gon);
			break;
		}
	}
	infile.close();
	update();
}