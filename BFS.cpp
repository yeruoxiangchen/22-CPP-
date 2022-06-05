#include"BFS.h"
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
std::vector<int>path(int x, int y, int u, int v)
{
	bool visited[sizeof(map)]; int d[sizeof(map)]; int path[sizeof(map)];
	std::queue<int> empty;
	std::queue<int>q;
	for (int i = 0; i < sizeof(map); ++i)
	{
		d[i] = false; //��Դ������·�����ȵ����·��,�ȳ�ʼ��,false�����ɵ���
		path[i] = -1;  //���·�����ĸ��������,�ȳ�ʼ��
		visited[i] = false;
	}
	int p = y * 12 + x;
	int end = v * 12 + u;
	d[p] = 0; q.push(p);//����p�����
	visited[p] = true; //��Ƕ���p�ѱ����
	while (!q.empty())//������
	{
		int k = q.front(); q.pop();
		for (int i = 0; i <= 4; i++)
		{	//������ǰ�����е�Ԫ�ص������ڽӶ���,��һ��Ϊ��������u�������ڽӶ���
			//��ǰ�����е�Ԫ�ؼ�����forѭ��֮��,�ٽ���forѭ��ʱ,������,u��Ϊ1��Ԫ��
			int kx = k % 12; int ky = k / 12;
			int wx = kx + dx[i]; int wy = ky + dy[i];
			int w = wy * 12 + wx;
			if (wx >= 0 && wx <= 11 && wy >= 0 && wy <= 11 && !visited[w] && map[wy][wx] != '3' && map[wy][wx] != '4') //wΪuΪ��δ���ʵ��ڽӶ���
			{
				d[w] = d[k] + 1;//·�����ȼ�1
				path[w] = k; //���·��Ϊk��w
				visited[w] = true;//��Ƕ���w�ѱ����
				if (w == end)//���w�����յ�
				{
					swap(empty, q);
					break;
				}
				else
					q.push(w);//����w�����
			}
		}
	}
	std::vector<int>Path;
	int size = empty.size(); int k = end;
	while (k != y * 12 + x)
	{
		Path.push_back(k);
		k = path[k];
	}
	std::reverse(Path.begin(), Path.end());
	return Path;
}