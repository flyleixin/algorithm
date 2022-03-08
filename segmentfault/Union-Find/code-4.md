```
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
int fa[30010];
int nums[30010];
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);

	}
	return  fa[x];
}
void unions(int x, int y) {
	int  a = find(x), b = find(y);
	if (a != b) {
		fa[a] = b;
		nums[b] += nums[a];
	}
}
int arr[30010];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		nums[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int q;
		cin >> q;
		memset(arr, 0, sizeof(arr));
		for (int j = 1; j <= q; j++) {
			cin >> arr[j];
		}
		for (int j = 2; j <= q; j++) {
			unions(arr[1], arr[j]);
		}


	}
	int maxx = -1;
	for (int i = 1; i <= n; i++) {
		if (nums[i] >= maxx)
			maxx = nums[i];
	}
	cout << maxx;


	return 0;
}
```
