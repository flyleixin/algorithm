```c++
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, arr[10010], sum[10010], result = -1, head, ends,tail;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	int lowest = 0;
	for (int end = 1; end <= n; end++) {
		//end-它前面的数据
		if (sum[end] - sum[lowest] > result) {
			result = sum[end] - sum[lowest];
			//开始的数据
			head = arr[lowest + 1];
			//j结尾的数据
			tail = arr[end];
		}
		//一开始这里难理解
		/*
		实际上这里就是找出lowest的最小值
		这样sum[end]-sum[lowest]才是最小值
		*/
		if (sum[lowest] > sum[end])
			lowest = end;
	}
	if (result < 0)
		cout << 0 << " " << arr[1] << " " << arr[n];
	else
		cout << result << " " << head << " " << tail;


}
```
