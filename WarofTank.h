#pragma once
#ifndef WAROFTANK_H
#define WAROFTANK_H
#include <QtWidgets/QMainWindow>
#include"BFS.h"
#include"ground.h"
#include"Mytank.h"
#include"EnemyTank.h"
#pragma execution_character_set("utf-8")//��ֹ�ַ����벻ƥ��

class Widget :public QWidget
{
	Q_OBJECT
private:
	QRect campRect;
	QPixmap wall;
	QPixmap river;
	QPixmap hardwall;
	QPixmap camp;
	QList<EnemyTank>enemies;
	QPainter painter;
	Mytank player;
	QTimer* timer1;
	QTimer* timer2;
	QTimer* timer3;
	QTimer* timer4;
	QTimer* timer5;
	QTimer* timer6;
	int enemynum;
	int life;
public:
	Widget(QWidget* parent = nullptr);
	void buildMyTank();
	void buildEnemyTank();
	~Widget();
	void keyPressEvent(QKeyEvent*) override;//�����¼�
	void keyReleaseEvent(QKeyEvent* event) override;//�ɿ�����
	void ifcollision();
private:
	void build();//������ͼ
	void timebuild();
	void paintEvent(QPaintEvent*) override;
	void Gameover();
public slots:
	void operation();
	void Enemyshot();
	void Bulletmove();
	void repaint();
	void killer();
	void assault();
};


#endif // !WAROFTANK_H
