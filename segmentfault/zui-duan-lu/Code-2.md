```c++
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#define MAXN 0X7FFFFFFF
using namespace std;
struct node {
	int to;
	int weight;
	int next;
}edge[250000];
struct node1 {
	int to;
	int dis;
	int w;
	node1(int a, int b, int c) :to(a), dis(b), w(c) {}
	bool operator <(node1 b)const {
		if (dis != b.dis)
			return dis > b.dis;
		else
			return w < b.w;
	}
};
int cnt, head[600];
int n, m, s, d, save[600];//save为给出的每个城市的救援队数量
void Add(int x, int y, int w) {
	cnt++;
	edge[cnt].to = y;
	edge[cnt].weight = w;
	edge[cnt].next = head[x];
	head[x] = cnt;
}
void Dijkstra(int start, int end) {
	int distance[600], pre[600], count[600], peo[600], book[600];
	//count为道路数量，pre用于打印路径，peo为已经召集的救援队数量
	priority_queue<node1> q;
	for (int i = 0; i < n; i++) {
		distance[i] = MAXN;
	}
	memset(book, 0, sizeof(book));
	memset(pre, -1, sizeof(pre));
	memset(count, 0, sizeof(count));
	distance[start] = 0;
	count[start] = 1;
	peo[start] = save[start];
	//to dis w
	q.push(node1(start, 0, peo[start]));
	while (!q.empty()) {
		node1 t = q.top();
		q.pop();
		if (book[t.to]) {
			continue;
		}
		book[t.to] = 1;
		//t.to--现在的点  edge[i].to----连接的点
		//1--3--2
		for (int i = head[t.to]; i; i = edge[i].next) {
			if (distance[edge[i].to] > distance[t.to] + edge[i].weight) {
				distance[edge[i].to] = distance[t.to] + edge[i].weight;
				//pre[2] = 1;peo[2]=peo[1]+save[2];count[2]=count[1];
				pre[edge[i].to] = t.to;
				peo[edge[i].to] = peo[t.to] + save[edge[i].to];
				count[edge[i].to] = count[t.to];
				q.push(node1(edge[i].to, distance[edge[i].to], peo[edge[i].to]));
			}
			else if (distance[edge[i].to] == distance[t.to] + edge[i].weight) {
				count[edge[i].to] += count[t.to];
				//pre[2]=1;
				if (peo[edge[i].to] < peo[t.to] + save[edge[i].to]) {
					pre[edge[i].to] = t.to;
					peo[edge[i].to] = peo[t.to] + save[edge[i].to];
					q.push(node1(edge[i].to, distance[edge[i].to], peo[edge[i].to]));
				}
			}
		}
	}
	printf("%d %d\n", count[end], peo[end]);
	if (start == end) {
		printf("%d %d\n", start, end);
		return;
	}
	int now = end;
	vector<int> v;
	v.clear();
	do {
		v.push_back(now);
		now = pre[now];
	} while (now != -1);
	for (int i = v.size() - 1; i >= 0; i--) {
		printf("%d%c", v[i], i == 0 ? '\n' : ' ');
	}
	return;
}
int main() {
	int x, y, z;
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++) {
		cin >> x;
		save[i] = x;
	}
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> z;
		Add(x, y, z);
		Add(y, x, z);
	}
	Dijkstra(s, d);
	return 0;
}
```
