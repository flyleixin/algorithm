```c++

#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Node {
	int ads,data, next;
};
int main() {
	int n, str, start,  key[10001] = {0};
	map<int, Node> m;
	vector<Node> out[2];
	cin >> start >> n ;
	for (int i = 0; i < n; i++) {
		scanf("%d", &str);         //输入结点数据
		scanf("%d %d", &m[str].data, &m[str].next);
	}
	for (int i = 0; i < n; i++) {  //通过map直接索引start将链表按顺序转到node数组里面
		if (key[abs(m[start].data)] == 0) {
			out[0].push_back({ start,m[start].data ,0 });
			key[abs(m[start].data)] = 1;
		}
		else
			out[1].push_back({ start,m[start].data ,0 });
		start = m[start].next;
		if (start == -1)     //当start被赋值为-1的时候，链表就结束了，更新n的值，测试点1
			n = i + 1;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < out[i].size(); j++) {   //输出
			printf("%05d %d ", out[i][j].ads, out[i][j].data);
			if (j != out[i].size() - 1)
				printf("%05d\n", out[i][j + 1].ads);
			else
				printf("-1\n");  //最后一个结点next为-1
		}
	}
	return 0;
}
```
