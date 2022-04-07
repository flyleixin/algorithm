```c++


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 2e5 + 10;
int head[maxn], to[maxm], val[maxm], nex[maxm], cnt = 0, vis[maxn], dis[maxn];

int n, m, s;
void add(int u, int v, int w) {
	to[++cnt] = v;
	val[cnt] = w;
	nex[cnt] = head[u];
	head[u] = cnt;
}

struct node {
	int cur;
	int dist;
	bool operator < (const node& t)const {
		return dist > t.dist;
	}
	node(int cur, int dist) {
		this->cur = cur;
		this->dist = dist;
	}
};
priority_queue<node>q;

void dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push(node(s, 0));
	while (!q.empty()) {
		node newone = q.top();
		q.pop();
		int uu = newone.cur;
		if (vis[uu] == 1) {
			continue;
		}
		vis[uu] = 1;
		for (int i = head[newone.cur]; i; i = nex[i]) {
			int vv = to[i];
			int ww = val[i];
			if (dis[uu] + ww < dis[vv]) {
				dis[vv] = dis[uu] + ww;
				q.push(node(vv, dis[vv]));
			}
		}

	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	return 0;
}


```
