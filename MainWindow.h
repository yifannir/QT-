#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "Shape.h"

#include "global.h"
#include <QPainter>
#include <qevent.h>
#include "saver.h"
#include "reader.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
private slots:
	void on_box_clicked();
	void on_line_clicked();
	void on_circle_clicked();
	void on_gon_clicked();
	void on_draw_clicked();
	void on_move_clicked();
	void on_save_clicked();
	void on_read_clicked();

	void saveData(QString path);

	void loadData(QString path);


public:
	int typeShape;
	bool perm;
	int typeAction;
};


