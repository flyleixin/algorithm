```c++
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1010;
struct Node
{
    int data, layer;
    Node(int _data, int _layer) : data(_data), layer(_layer) {}
};
int vis[maxn];
vector<int > ve[maxn];
int ans = 0;
void bfs(int x) {
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    queue<Node>q;
    q.push(Node(x, 0));
    ans = 0;
    while (!q.empty()) {
        Node cur = q.front();
        if (cur.layer == 7) {
            break;
        }
        q.pop();
        ans++;
        int curdata = cur.data;
        for (int i = 0; i < ve[cur.data].size(); i++) {
            if (vis[ve[curdata][i]] == 0) {
                q.push(Node(ve[curdata][i], cur.layer + 1));
                vis[ve[curdata][i]] = 1;

            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {

        bfs(i);
        printf("%d: %.2f%%\n", i, 1.0 * ans / n*100);
       // cout << ans << endl;
    }

    return 0;
}



```
