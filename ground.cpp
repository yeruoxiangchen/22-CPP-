#include"ground.h"



char map[12][12];
const std::string rootdir = "E:\\Qt\\docments\\WarofTank\\picture\\";
void ini_map()
{
	//0�յ�1·2ǽ3ˮ4Ӳǽ5���6�з�������
	//;//��map����ʼ����
	//��ʼ��˼·��
	//ֱ��ָ����ͼ��ʽ
/*
	2 2 2 2 2 2 2 2 2 2 2 2
	2 6 1 1 1 6 1 1 1 1 6 2
	2 1 2 2 2 1 2 2 2 2 1 2
	2 2 2 2 2 1 2 2 2 2 2 2
	2 2 2 2 1 6 1 2 2 2 2 2
	2 2 2 3 3 1 3 3 2 2 2 2
	2 2 2 2 3 1 3 2 2 2 2 2
	2 2 2 2 2 2 2 2 2 2 2 2
	2 2 2 2 3 3 3 2 2 2 2 2
	2 2 2 2 2 5 2 2 2 2 2 2
	2 2 2 2 2 2 2 2 2 2 2 2
	2 2 2 2 2 0 2 2 2 2 2 2

*/
	std::ifstream file;

	file.open("E:\\Qt\\docments\\WarofTank\\map\\1.txt");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			file >> map[i][j];
		}
	}
	file.close();

	

}