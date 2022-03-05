```c++
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 100010;
bool vis[MAXN];
//步数 
int d[MAXN];
int n,k;

void bfs(){
	
	queue<int > q;
	vis[n] = 0;
	d[n] = 0;
	q.push(n);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == k){
			cout<<d[u] <<endl;
			return ;
		}
		int x;
		x = u + 1;
		if(x>=0&&x<=100000&&!vis[x]){
			d[x] = d[u] + 1;
			vis[x] = 1;
			q.push(x);
		}
		x = u - 1;
		if(x>=0&&x<=100000&&!vis[x]){
			d[x] = d[u] + 1;
			vis[x] = 1;
			q.push(x);
		}
		x = u * 2;
			if(x>=0&&x<=100000&&!vis[x]){
			d[x] = d[u] + 1;
			vis[x] = 1;
			q.push(x);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);

	cin>>n>>k;
	if(n>k) cout<<n-k<<endl;
    else	bfs();
	
	
	return 0;
}
```
