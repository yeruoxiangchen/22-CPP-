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
	QPixmap upimg;//���������̹�˵�ͼ��
	QPixmap downimg;
	QPixmap rightimg;
	QPixmap leftimg;
	QRect rect;//̹�˱����ڴ�����ռ�Ĵ�С
	Face face;//����
	Bullet bullet;
	void shot();
	virtual void move();//̹���ƶ�
	virtual void Faceto(Face f);//ȷ��̹�˳���
	virtual void paintTank(QPainter& p);//����̹��
	bool ifreach(int, int, Face);//�ж��Ƿ�Խ��

};
#endif //TANK_H