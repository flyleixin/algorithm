```c++
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int fa[10010];
int find(int x) {
	if (x != fa[x]) {
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		if(x==1){
		    unions(y,z);
		    
		}
		else if(x==2){
		    if(find(y)==find(z)){
		        cout<<"Y"<<endl;
		        
		    }
		    else{
		        cout<<"N"<<endl;
		    }
		}

	}

}
```
