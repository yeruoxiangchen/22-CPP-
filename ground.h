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
//1.�������ʼ����0123�����map
// 2.�������ڣ���ͼ����ǽ��·��ˮ��Ӳǽ---��QPainter
//0�յ�1·2ǽ3ˮ
extern char map[12][12];
extern const std::string rootdir;
void ini_map();
enum Face { up0, down0, left0, right0 };


#endif //GROUND_H