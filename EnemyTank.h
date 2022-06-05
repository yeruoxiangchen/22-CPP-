#pragma once
#ifndef ENEMYTANK_H
#define ENEMYTANK_H

#include"Tank.h"
#include"ground.h"
class EnemyTank :public Tank
{
public:
	bool ismove;// «∑Ò“∆∂Ø
	EnemyTank();
	void settankdir();
	void Faceto(Face)override;
};
#endif // !ENEMYTANK_H
