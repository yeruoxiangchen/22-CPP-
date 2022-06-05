#ifndef GROUND_H
#define GROUND_H
#include<fstream>
#include<iostream>
#include<QCoreApplication>
#include <string>
#include <QCoreApplication>
#include <QMessageBox>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include<QIcon>
#include<QPixmap>
#include <QtWidgets/QApplication>
#include<iostream>
#define WT 600
#define HT 600
#define SIZE 50
//1.对数组初始化，0123输入进map
// 2.构建窗口，画图，画墙、路、水、硬墙---》QPainter
//0终点1路2墙3水
extern char map[12][12];
extern const std::string rootdir;
void ini_map();
enum Face { up0, down0, left0, right0 };


#endif //GROUND_H