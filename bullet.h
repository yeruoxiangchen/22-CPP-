#pragma once
#ifndef BULLET_H
#define BULLET_H

#include"ground.h"

class Bullet
{
public:
	int speed;
	bool flying;//�Ƿ��ڷ���
	Face face;
	QPixmap upimg;
	QPixmap downimg;
	QPixmap leftimg;
	QPixmap rightimg;
	QRect bullrect;//�ӵ�����ľ���
	void setbullet();
	void setstate(bool);//�����ӵ�����״̬
	bool getstate();
	void move();
	void Faceto(Face);
	void paintbullet(QPainter&);//���ӵ�
	bool ifreach(int, int, int,int);//̹ͬ��
	Bullet();
};



#endif // !BULLET_H
