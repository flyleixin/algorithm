```c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N = 5010;
const int M = 200010;
int head[N], to[M*2], val[M*2], nex[M*2], cnt = 0;
int vis[N], dist[N];

int n, m;

struct node
{
	int first, second;
	friend bool operator<(node x, node y) { return x.first > y.first; }
};
priority_queue<node> q;
void add(int u, int v, int w) {
	to[++cnt] = v;
	val[cnt] = w;
	nex[cnt] = head[u];
	head[u] = cnt;
}
int tot, ans;
node tmp;
void  prim() {
	memset(dist, 0x3f, sizeof(dist));
	tmp.first = 0;
	dist[1] = 0;
	tmp.second = 1;
	q.push(tmp);
	while (!q.empty() && tot < n) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		ans += dist[u];
		tot++;
		for (int i = head[u]; i; i = nex[i]) {
			if (val[i] < dist[to[i]]) {
				dist[to[i]] = val[i];
				tmp.first = dist[to[i]];
				tmp.second = to[i];
				q.push(tmp);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);

	}
	prim();
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << "orz";
			return 0;
		}
	}
	cout << ans;
	return 0;
}
```
