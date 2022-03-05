#### 思路如下

首先先写一个函数判断两个洞是否相连，即两洞之间距离是否小于等于球直径**（注意是直径）**。
```c++
struct dong {//为了程序简洁美观，定义一个结构体表示洞的坐标
    double x,y,z;
};
dong p[1001];
bool pd(dong a,dong b) {
    long long d;//d为两洞之间距离的平方
    d=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    if(d<=2*2*r*r) return true;//鉴于sqrt函数精度问题，我们就用平方判断（直径2r的平方）
    else return false;
}
```

第二个难点在于如何判断是否可以穿过奶酪，对此我们可以模拟老鼠钻洞（run函数）见代码：
```c++
void run(int x) {
    if(jud==1) return;//用jud记录是否穿过了奶酪
    if(p[x].z+r>=h) {
        jud=1;
        return;
    }
    for(int i=1; i<=n; i++) {
        if(m[i]==1) continue;//用m数组保存是否走过此洞（1为走过，0为没走过）
        if(pd(p[x],p[i])) {//如果能走
            m[i]=1;//标记为走过
            run(i);//从这个洞往别的洞走
        }
    }
}
```

思考一下，对于这个函数我们要从最下面的一个洞开始走，凡是走过的洞都不会再走，但如果前方不能再走了还会返回这个洞寻找下一个能连接到此洞的洞，
这样的话就可以将每一个能和底边连接到的洞全部判断一遍，只要其中有洞连接到顶端，就用jud记录为1。
因此等会在主函数中我们用循环把能连接到底边的所有洞找到均调用此函数即可。

#### 完整代码：
```c++
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,h,r;
int vis[1010];
struct node{
    double x,y,z;
}dong[1010]; 
int flag = 0;
bool pd(node a,node b){
    ll d;
    d=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    if(d<=2*2*r*r) return true;
    else return false;
    
}
void dfs(int x){
    if(flag==1)
    return ;
    if(dong[x].z+r>=h){
        flag = 1;
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i])
        continue;
        if(pd(dong[x],dong[i])){
            vis[i] = 1;
            dfs(i);
        }
    }
    
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int i = 1; i <= t; i++){
	    cin>>n>>h>>r;
	    flag = 0;
	    memset(vis,0,sizeof(vis));
	    for(int j = 1; j <= n; j++){
	        cin>>dong[j].x>>dong[j].y>>dong[j].z;
	    }
	    for(int j = 1; j <= n; j++){
	        if(dong[j].z<=r){
	            vis[j] = 1;
	            dfs(j);
	        } 
	    }
	    if(flag==1){
	        cout<<"Yes"<<endl;
	        
	    }
	    else
	    cout<<"No"<<endl;
	    
	    
	}


}
```
