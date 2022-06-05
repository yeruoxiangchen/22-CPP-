#pragma once
#ifndef BULLET_H
#define BULLET_H

#include"ground.h"

class Bullet
{
public:
	int speed;
	bool flying;//是否在飞行
	Face face;
	QPixmap upimg;
	QPixmap downimg;
	QPixmap leftimg;
	QPixmap rightimg;
	QRect bullrect;//子弹本身的矩形
	void setbullet();
	void setstate(bool);//设置子弹飞行状态
	bool getstate();
	void move();
	void Faceto(Face);
	void paintbullet(QPainter&);//画子弹
	bool ifreach(int, int, int,int);//同坦克
	Bullet();
};



#endif // !BULLET_H
