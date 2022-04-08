### 试题 F: 时间显示
```c++

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	//ios::sync_with_stdio(false);cin.tie(0);
	ll n;
	scanf("%lld",&n);
	n/=1000;
	n%=86400;
	
	int h = n/3600;
	n%=3600;
	int m = n/60;
	int s = n%60;
	printf("%02d:%02d:%02d",h,m,s);
	
	return 0;
} 


```
