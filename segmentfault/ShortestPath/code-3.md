```c++

#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n, m, d;
const int maxm = 5000;
const int maxn = 110;
int mp[110][110];
int head[maxn], to[maxm], nex[maxm], val[maxm], tot;
void add(int u, int v, int w) {
	to[++tot] = v;
	val[tot] = w;
	nex[tot] = head[u];
	head[u] = tot;
}


struct node {
	int curu, dist;
	node(int a, int b) : curu(a), dist(b) {

	}

	bool operator < (node q) const {
		return dist > q.dist;
	}
};
int dis[maxn];
int vis[maxn];
int nows, tar;
void dijkstra() {
	priority_queue<node>q;
	memset(dis, 0x3f, sizeof(dis));
	dis[nows] = 0;
	q.push(node(nows, 0));
	while (!q.empty()) {
		int u = q.top().curu;
		q.pop();
		if (vis[u] == 1) {
			continue;
		}
		vis[u] = 1;
		for (int i = head[u]; i; i = nex[i]) {
			int v = to[i];
			if (dis[v] > dis[u] + val[i]) {
				dis[v] = dis[u] + val[i];
				q.push(node(v, dis[v]));
			}
		}
	}

}
int main() {
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, 0);
		add(v, u, 0);
		mp[u][v] = w;
		mp[v][u] = w;

	}
	cin >> d;
	for (int i = 1; i <= d; i++) {
		int uu, vv;
		cin >> uu >> vv;
		for (int j = head[uu]; j; j = nex[j]) {
			if (to[j] == vv)
				val[j] = mp[uu][vv];
		}
		for (int j = head[vv]; j; j = nex[j]) {
			if (to[j] == uu) {
				val[j] = mp[uu][ vv];
			}
		}
	}
	
	cin >> nows >> tar;
	dijkstra();
	cout << dis[tar];
	return 0;
}

```
