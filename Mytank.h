#pragma once
#ifndef MYTANK_H
#define MYTANK_H
#include"Tank.h"
#include"ground.h"
class Mytank :public Tank
{
public:
	bool ismove;//�Ƿ��ƶ�
	Mytank();
	void settankdir();
	void Faceto(Face)override;
};


#endif // !MYTANK_H
