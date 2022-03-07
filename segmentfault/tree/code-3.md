```c++
#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
 string  mid,pre;
void build(int lmid,int rmid,int  lpre,int rpre){
    if(lmid>rmid) return ;
    int fa = lmid;
    while(mid[fa]!=pre[lpre]) fa++;
    int len = fa-lmid;
    // build(lpre + 1, lpre + len, lmid, fa - 1);
   //  build(lpre + len + 1, rpre, fa + 1, rmid);
    //D-BAC-EGF 先 
    //ABC-D-EFG 中 
    build(lmid,fa-1,lpre+1,lpre+len);
    build(fa+1,rmid,lpre+len+1,rpre);
    cout<<pre[lpre];
}
int main(){
    ios::sync_with_stdio(false);
   
    while(cin>>pre>>mid){
    
    int len = mid.size()-1;
    build(0,len,0,len);
    cout<<endl;
}
    return 0;
} 

```
