// 2018-06-30
// POJ1248
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long n;
string str;
bool ok, vis[20];
int ans[10], idx[10];

void dfs(int step){
	if(ok)return;
	if(step >= 5){
		if(ans[0]-ans[1]*ans[1]+ans[2]*ans[2]*ans[2]-ans[3]*ans[3]*ans[3]*ans[3]+ans[4]*ans[4]*ans[4]*ans[4]*ans[4]==n){
			ok = true;
			for(int i = 0; i < 5; i++)
			  cout<<str[idx[i]];
			cout<<endl;
		}
		return;
	}
	for(int i = str.length()-1; i >= 0; i--){
		if(!vis[i]){
			vis[i] = true;
			ans[step] = str[i]-'A'+1;
			idx[step] = i;
			dfs(step+1);
			vis[i] = false;
		}
	}
}

int main()
{
	while(cin>>n>>str){
		if(str == "END")break;
		sort(str.begin(), str.end());
		memset(vis, false, sizeof(vis));
		ok = false;
		dfs(0);
		if(!ok){
			cout<<"no solution"<<endl;
		}
	}

	return 0;
}
