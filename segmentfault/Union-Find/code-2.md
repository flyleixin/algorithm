```c++

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n,h,r;
int fa[10010];
int bottom[10010];
int top[10010];
struct node{
    ll x,y,z;
}dong[10001];
bool pd(node a,node b){
    ll d;
    d = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    if(d<=4*r*r){
        return true;
    }
    else 
    return false;
}
int find(int x){
    if(x!=fa[x]){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unions(int x,int y){
    if(find(x)!=find(y)){
        fa[find(x)] = find(y);
    }
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
	    cin>>n>>h>>r;
	    ///tot1记录与顶面相交的洞有几个
	    //tot2//记录与底面相交的洞有几个
	    int tot1 = 0,tot2 = 0;
	    memset(fa,0,sizeof(fa));
	    //并查集初始化
	    for(int i = 1;i<=n;i++){
	        fa[i] = i;
	    }
	    for(int i = 1; i <= n; i++){
	        cin>>dong[i].x>>dong[i].y>>dong[i].z;
	        //判断这个点是否与顶面相交
	        if(dong[i].z+r>=h){
	            top[++tot1] = i;
	            
	        }
	        //判断这个点是否与底面相交
	        if(dong[i].z - r <= 0){
	            bottom[++tot2] = i;
            }
            //枚举之前的洞是否与这个洞相交，如果相交则合并集合
            for(int j = 1; j <= i; j++){
                if(pd(dong[i],dong[j])){
                    unions(i,j);
                }
            }
            
            
            
	    }
	    
	    int flag = 0;
	    //看看每一个中是否有洞连接上下面
	    for(int i = 1; i <= tot1; i++){
	        for(int j = 1; j <= tot2;j++){
	            if(find(top[i])==find(bottom[j])){
	                flag  = 1;
	                goto label;
	            }
	        }
	    }
	    label:
	        if(flag == 1){
	            cout<<"Yes"<<endl;
	            
	        }
	        else
	        cout<<"No"<<endl;
	   
	}



}
```
