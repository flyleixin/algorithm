```c++

#include <iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxx = 1e5 + 10;
vector<int>e[maxx], res;
int maxlevel = -1;
void dfs(int x, int level) {
    if (level == maxlevel) {
        res.push_back(x);
    }
    if (level > maxlevel) {
        maxlevel = level;
        res.clear();
        res.push_back(x);
    }
    for (int i = 0; i < e[x].size(); i++) {
        dfs(e[x][i], level + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        if (x == -1) {
            root = i;
            continue;
        }
        e[x].push_back(i);
    }
    dfs(root, 1);
    sort(res.begin(), res.end());
    bool fl = true;
    cout << maxlevel << endl;
    for (auto it : res) {
        if (fl) {
            fl = false;
            cout << it;

        }
        else {
            cout << " "<<it;
        }
    }
    return 0;
}

```
