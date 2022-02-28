```c++
#include <iostream>
using namespace std;
int main() {
    int n, m, k;
    bool book[100010] = {false};
    cin >> n;
    while (n--) {
        cin >> m;
        if (m == 1) cin >> k;
        else {
            while (m--) {
                cin >> k;
                book[k] = true;
            }
        }
    }
    cin >> n;
    bool flag = false;
    while (n--) {
        cin >> k;
        if (book[k] == false) {
            if (flag == true) cout << " ";
            printf("%05d", k);
            flag = true;
            book[k] = true;
        }
    }
    if (flag == false) cout << "No one is handsome";
    return 0;
}
```
