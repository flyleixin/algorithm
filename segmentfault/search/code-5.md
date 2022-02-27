```c++
#include<iostream>
using namespace std;
#define max 1001
#define INF 100000

int list[3000];
int lt = 0;
int len = 0;
int visited[max] = { 0 };
int edges[1001][1001];

void dfs(int n,int v)
{
	
	visited[v] = 1;
	list[len] = v;//！！！！！！！！！！！！！！！
	len++;
	lt++;
	for (int w = 1; w <= n; w++)
	{
		if (edges[v][w] != INF&&visited[w] == 0)
		{
			dfs(n, w);
			list[len++] = v;//!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}

int main()
{
	int n, m, s;
	cin >> n >> m >> s;

	for (int i = 0; i <max; i++)
	{
		for (int j = 0; j < max; j++)
			edges[i][j] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edges[a][b] = 1;
		edges[b][a] = 1;
	}
	dfs(n, s);

	if(lt!=n)
		list[len++] = 0;//没有完全走完就在后面添加一个0
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (count == 0)
		{
			cout << list[i]; count++;
		}
		else
			cout << " " << list[i];
	}

}
```
