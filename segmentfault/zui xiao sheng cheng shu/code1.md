给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500,
1≤m≤1e5,
图中涉及边的边权的绝对值均不超过 10000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6

题解：
```c++

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 510;
int dist[N];
int g[N][N];
bool st[N];//标记这个点是否被加入
int n, m;

int prim() {
    
	memset(dist, 0x3f3f3f3f, sizeof dist);
	int res = 0;
	for (int i = 0; i < n; i++) {
    //初始没有点在集合中
		int t = -1;
		for (int j = 1; j <= n; j++) {
    
			if (!st[j] && (dist[j] < dist[t] || t == -1)) {
    
				t = j;
			}
		}
	if (i && dist[t] == 0x3f3f3f3f)return 0x3f3f3f3f;
	//没有联通点 即不构成最小生成树
	if (i) res += dist[t];
	//要先更新res 
	//如果在下面for循环后加可能会因为负边自环的问题导致res不对 
	st[t] = true;
	//更新的是点到集合的距离 这也就是和dijkstra算法的区别所在
	for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
	}
	return res;
}
int main() {
    
	cin >> n >> m;
	memset(g, 0x3f3f3f3f, sizeof g);//初始化
	while (m--) {
    
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);//存储无向图
	}
	int t = prim();
	if (t == 0x3f3f3f3f)puts("impossible");
	else cout << t << endl;
}

```
