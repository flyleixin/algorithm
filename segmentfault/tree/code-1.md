```c++
#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
int mid[maxn];
int post[maxn];
struct node{
   
	int lson,rson;
}f[maxn];
int build(int lmid,int rmid,int lpost,int rpost){
   
//中序遍历 后序遍历 
//后序遍历确定根 
//先序，后序遍历可以确定根节点。
//中序遍历可以确定左子树和右子树。
	if(lmid>rmid)return 0;
	int root=post[rpost];
	int fa=lmid; 
	while(mid[fa]!=root)fa++;//确定根 
	int len=fa-lmid;//确定左子树长度
	// 7
//   后序：  2 3 1 5 7 6 4
//   中序：  1 2 3 4 5 6 7

	
	f[root].lson=build(lmid,fa-1,lpost,lpost+len-1);//左子树 
	f[root].rson=build(fa+1,rmid,lpost+len,rpost-1);//右子树 
	return root;
}
void bfs(int x)
{
   
	queue<int>q;
	vector<int>v;
	q.push(x);
	while(!q.empty())
	{
   
		int w=q.front();
		q.pop();
		if(!w)break;
		v.push_back(w);
		if(f[w].lson)q.push(f[w].lson);
		if(f[w].rson)q.push(f[w].rson);
	}
	int len=v.size();
	for(int i=0;i<len;i++)
	{
   
		if(i!=len-1)
		printf("%d ",v[i]);
		else cout<<v[i];
	}
	return ;
}
int main()
{
   
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>post[i];//后序 
	for(int i=0;i<n;i++)cin>>mid[i];//中序
	int root=post[n-1];
	build(0,n-1,0,n-1);
	bfs(root);
	return 0; 
}

```
