#include<cstdio>
#include<string>
#include <cstring>
#include<iostream>
#include <queue>
using namespace std;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char a[30][30];
int vis[30][30];
int i, j, w, h, x, y, s;
int  bfss(int sx, int sy);
int main()
{
	ios::sync_with_stdio(false);
	while (cin>>w>>h)
	{
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		s = 1;
		if (w == 0 && h == 0)
			break;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@')
				{
					x = i; y = j;
				}
			}
		}
		
		cout << bfss(x, y) << endl;
	}
}
struct nodes {
	int x, y;
	nodes(int nx, int ny) {
		x = nx;
		y = ny;
	}
};
int  bfss(int sx, int sy) {
	int res = 1;
	queue<nodes>q;
	q.push(nodes(sx, sy));
	vis[sx][sy] = 1;
	while (!q.empty()) {
		nodes tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = tmp.x + dir[i][0];
			int yy = tmp.y + dir[i][1];
			if (0 <= xx && xx < h && 0 <= yy && yy < w && !vis[xx][yy] && a[xx][yy] == '.')
			{
				vis[xx][yy] = 1;
				q.push(nodes(xx, yy));
				res++;
			}
		}
	}
	return res;
}
inline int read() {
	int x = 0, flag = 1;
	char c = getchar();
	while (c < '0' && c>'9') {
		if (c == '-') {
			flag = 0;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return flag ? x : ~(x - 1);
}
