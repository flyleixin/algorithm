```c++
#include<iostream>
#include<vector>
#define maxx 500100
using namespace std;
int n, m;
vector<int > edge[maxx];
int a[maxx];
void dfs(int x, int k) {
	if (a[x]) return;
	a[x] = k;
	for (int i = 0; i < edge[x].size(); i++)
		dfs(edge[x][i], k);
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		edge[v].push_back(u);
	}
	for (int i = n; i >= 1; i--)
		dfs(i, i);
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}
```
