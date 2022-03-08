```c++

#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
int fa[510];
int mp[510][510];
int visted[510];
int nums[30010];
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return  fa[x];
}
bool  unions(int x, int y) {
	int  a = find(x), b = find(y);
	if (a != b) {
		fa[a] = b;
		return true;
	}
	else
		return false;
}
int arr[30010];
int main() {
	stack<int>st;
	stack<string>sts;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		mp[u][v] = 1;
		mp[v][u] = 1;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		st.push(x);
		visted[x] = 1;

	}
	//未攻占的城市用并查集联合起来
	for (int i = 0; i < n; i++) {
		if (visted[i] == 1) continue;
		for (int j = 0; j < n; j++) {
			if (visted[j] == 0 && mp[i][j] == 1) {
				unions(i, j);
			}
		}
	}
	//每并入一个被攻占的城市，统计该城市并入城市圈中，多出来几条路，
	//如过大于1，则该输出红色警报.

	for (int i = 0; i < k; i++) {
		int tmp = st.top();
		st.pop();
		visted[tmp] = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (visted[i] == 0 && mp[tmp][i] == 1) {
				if (unions(tmp, i) == true) {
					cnt++;
				}
			}
		}

		if (cnt > 1) {
			char arr[100];
			sprintf(arr, "Red Alert: City %d is lost!\n", tmp);
			sts.push(arr);
		}
		else {
			char arr[100];
			sprintf(arr,"City %d is lost.\n", tmp);
			sts.push(arr);
		}
	}
	while (!sts.empty()) {
		cout << sts.top();
		sts.pop();
	}
	if (n == k)
		cout << "Game Over.";
	return 0;
}
```
