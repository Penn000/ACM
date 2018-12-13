#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int N = 100000;

char wenhao[10] = {'a', 'b', 'c', 'd', 'e'};
int position[5], tot, ans, len;
map<string, int> mp, book;
map<string, int>::iterator iter;
char parten[N];
string str;

void dfs(int step){
	if(step == len){
		parten[step] = '\0';
		string tmp(parten);
		cout<<tmp<<endl;
		iter = mp.find(tmp);
		if(iter != mp.end())
		  	ans += iter->second;
		return;
	}
	if(str[step] == '?'){
		for(int i = 0; i < 5; i++){
			parten[tot++] = str[step];
			dfs(step+1);
		}
		dfs(step+1);
	}else{
		parten[tot++] = str[step];
		dfs(step+1);
	}
}
int main()
{
//	freopen("inputG.txt", "r", stdin);
	int n, m;
	while(cin>>n>>m){
		while(n--){
			cin>>str;
			mp[str]++;
			book[str] = 0;
		}
		while(m--){
			tot = 0;
			ans = 0;
			cin>>str;
			len = str.length();
			dfs(0);
			cout<<ans<<endl;
		}
	}

	return 0;
}
