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
		d[i] = false; //单源到各点路径长度的最短路径,先初始化,false代表不可到达
		path[i] = -1;  //最短路径从哪个顶点过来,先初始化
		visited[i] = false;
	}
	int p = y * 12 + x;
	int end = v * 12 + u;
	d[p] = 0; q.push(p);//顶点p入队列
	visited[p] = true; //标记顶点p已被标记
	while (!q.empty())//主过程
	{
		int k = q.front(); q.pop();
		for (int i = 0; i <= 4; i++)
		{	//遍历当前出队列的元素的所有邻接顶点,第一次为遍历顶点u的所有邻接顶点
			//当前出队列的元素即跳出for循环之后,再进入for循环时,本例中,u即为1号元素
			int kx = k % 12; int ky = k / 12;
			int wx = kx + dx[i]; int wy = ky + dy[i];
			int w = wy * 12 + wx;
			if (wx >= 0 && wx <= 11 && wy >= 0 && wy <= 11 && !visited[w] && map[wy][wx] != '3' && map[wy][wx] != '4') //w为u为尚未访问的邻接顶点
			{
				d[w] = d[k] + 1;//路径长度加1
				path[w] = k; //最短路径为k到w
				visited[w] = true;//标记顶点w已被标记
				if (w == end)//如果w到达终点
				{
					swap(empty, q);
					break;
				}
				else
					q.push(w);//顶点w入队列
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