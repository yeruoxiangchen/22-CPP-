#pragma once
#ifndef BFS_H
#define BFS_H
#include<iostream>
#include<queue>
#include"ground.h"


struct Path { int x; int y; int length; };
std::vector<int>path(int x, int y, int u, int v);



#endif // !BFS_H
