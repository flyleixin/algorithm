``` c++
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define re register
#define il inline
int  read();
int n, m;
const int N = 5010;
const int M = 200010;
int fa[N];
struct edge {
	int u, v, w;
}e[M];
il bool cmp(edge x, edge y) {
	return x.w < y.w;
}
il int finds(int x) {
	if (x != fa[x]) {
		fa[x] = finds(fa[x]);
	}
	return fa[x];
}
il void unions(int x, int y) {
	int a = finds(x);
	int b = finds(y);
	if (a != b) {
		fa[a] = b;
	}
}
int ans;
il void kruskal() {
	int cnt = 0;
	sort(e, e + m, cmp);
	for (re int i = 1; i <= m; i++) {
		int uu = finds(e[i].u);
		int vv = finds(e[i].v);
		if (finds(uu) == finds(vv))
			continue;
		ans += e[i].w;
		unions(e[i].u,e[i].v);
		cnt++;
		if (cnt == n - 1)
			break;
	}
}
int main() {
	n = read();
	m = read();
	for (re int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (re int i = 1; i <= m; i++) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	kruskal();
	for (int i = 2; i <= n; i++) {
		if (finds(1) != finds(i))
		{
			cout << "orz";
			return 0;
		}
	}
	cout << ans;
	return 0;
}

il int read() {
	re int x = 0, flag = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')
			flag = 1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
	return flag ? x : ~(x - 1);
}

```
