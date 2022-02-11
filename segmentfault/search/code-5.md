```c++
#include <iostream>
#include <string>
using namespace std;
//n是多少个数，arr是这n个数，k是目标和
int n,arr[25],k;



// 已经从前i项得到了和sum，然后对于i项之后的进行分支 
bool dfs(int i, int sum) { 
  // 如果前n项都计算过了，则返回sum是否与k相等 
  if (i == n) return sum == k;  
   
  // 不加上a[i]的情况 
  if (dfs(i + 1, sum)) return true; 
   
  // 加上a[i]的情况 
  if (dfs(i + 1, sum + arr[i])) return true; 
   
  // 无论是否加上a[i]都不能凑成k就返回false 
  return false; 
} 
int main(){
    ios::sync_with_stdio(false);
    
    while(cin>>n){
        for(int i = 0;i < n; i++)  cin>>arr[i];
        cin>>k;
        if(dfs(0,0)==true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
```
