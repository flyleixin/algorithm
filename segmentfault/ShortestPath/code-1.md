``` c++
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
#define mp(x,y) make_pair(x,y)
using namespace std;
const int N = 1e5 + 5, M = 5e5 + 5;
int n, m, s;
int head[N], to[M], nxt[M], val[M], cnt = 0;
int dist[N], vis[N];

priority_queue< pair<int, int> > q;//第一个长度，第二个节点编号

void add(int u, int v, int w) {
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}
void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
q.push(mp(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i], w = val[i];
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(mp(-dist[v], v));
            }
        }


    }
}
int main() {
    cin >> n >> m >> s;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) {
   
            cout << dist[i] << " ";
        
      
    }
    return 0;
}
```
