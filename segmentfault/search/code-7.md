```c++
#include <bits/stdc++.h> 
using namespace std;

vector<int> vec[100000];//存关系图 
bool vis[100000];//标记五服以内的亲属 
char sex[100000];//记录性别 
bool flag;//标记情侣是否为近亲 

void Dfs(int x,int num)//num表示第几代，从0开始 
{
	if(num>=4) return;  //超过五代直接退出 
	for(int i=0;i<vec[x].size();i++){
		if(!vis[vec[x][i]]){
			vis[vec[x][i]]=1;//标记出现的人 
			Dfs(vec[x][i],num+1); 
		}
		else flag=1;//五服之内出现一样的人 
	}
}
int main() 
{
	int T;
	cin>>T;
	while(T--){
		int t,fa,ma;
		char ch;
		cin>>t>>ch>>fa>>ma;
		sex[t]=ch;
		if(fa!=-1){ //-1不用保存，避免数据处理不当导致数组越界 
			vec[t].push_back(fa);//保存双亲 
			sex[fa]='M';//记录父亲性别 
		}
		if(ma!=-1){
			vec[t].push_back(ma);
			sex[ma]='F';
		}
	}
	cin>>T;
	while(T--){
		int x,y;
		cin>>x>>y; 
		if(sex[x]==sex[y]) cout<<"Never Mind"<<endl; //同性 
		else{
			memset(vis,0,sizeof(vis)); 
			vis[x]=1;  
			vis[y]=1;
			flag=0;
			Dfs(x,0);
			Dfs(y,0);
			if(flag)//被标记过说明这两人为近亲 
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
	}
	return 0;
}


```
