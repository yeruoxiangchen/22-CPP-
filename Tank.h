#pragma once
#ifndef TANK_H
#define TANK_H
#include<QPixmap>
#include<QPainter>
#include"bullet.h"

class Tank
{
public:
	int speed;
	QPixmap upimg;//各个方向的坦克的图像
	QPixmap downimg;
	QPixmap rightimg;
	QPixmap leftimg;
	QRect rect;//坦克本身在窗口中占的大小
	Face face;//方向
	Bullet bullet;
	void shot();
	virtual void move();//坦克移动
	virtual void Faceto(Face f);//确定坦克朝向
	virtual void paintTank(QPainter& p);//绘制坦克
	bool ifreach(int, int, Face);//判断是否越界

};
#endif //TANK_H