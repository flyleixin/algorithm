```c++
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char a[30][30];
int book[30][30];
int i, j, w, h, x, y, s;
void dfs(int x, int y);
int main()
{
	while (cin>>w>>h)
	{
		memset(a, 0, sizeof(a));
		memset(book, 0, sizeof(book));
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
		dfs(x, y);
		printf("%d\n", s);
	}
}
void dfs(int x, int y)
{
	int k, tx, ty;
	for (k = 0; k < 4; k++)
	{
		tx = x + dir[k][0];
		ty = y + dir[k][1];
		if (tx >= 0 && tx < h && ty >= 0 && ty < w && book[tx][ty] == 0 && a[tx][ty] == '.')
		{
			s++;
			book[tx][ty] = 1;
			dfs(tx, ty);
		}
	}
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
```