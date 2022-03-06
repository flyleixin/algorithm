```
#include<bits/stdc++.h> 
using namespace std;
const int maxn=40;
int fa[110];
//敌对关系
int d[110][110];
int find(int x){
    if(x!=fa[x])
      fa[x] = find(fa[x]);
    return fa[x];
}
void unions(int x,int y){
    if(find(x)!=find(y)){
        fa[find(x)] = find(y);
    } 
}
int main()
{
   int n,m,k;
   cin>>n>>m>>k;
   for(int i = 1; i <= n; i++){
       fa[i] = i;
   }
   for(int i = 1; i <=m;i++){
       int x,y,z;
       cin>>x>>y>>z;
       if(z==-1){
           d[x][y] = d[y][x] = 1;
       }
       if(z==1){
           unions(x,y);
       }
   }
    for(int i = 1;i<=k;i++){
       int a,b;
       cin>>a>>b;
       if(find(a)==find(b)&&d[a][b]==0&&d[b][a]==0)
       cout<<"No problem"<<endl;
       else if(find(a)!=find(b)&&d[a][b]==0&&d[b][a]==0)
       cout<<"OK"<<endl;
       else if(find(a)==find(b)&&d[a][b]==1)
           cout<<"OK but..."<<endl;
       else
       cout<<"No way"<<endl;    
          
       }
    

	return 0; 
}

```
