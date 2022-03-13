```c++

#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int Tree[N],idx;
int n,post[N];
void build(int u)   //后序遍历建树操作
{
    if(u>n) return ;
    build(u<<1);    //左孩子
    build(u<<1|1);  //右孩子
    Tree[u]=post[++idx];    //根节点
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&post[i]);
    build(1);
    for(int i=1;i<=n;i++)
    {
        if(i!=1) cout<<" ";
        cout<<Tree[i];
    }
    return 0;
}



```
