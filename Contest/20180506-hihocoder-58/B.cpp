#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000+5;

int dp[N];
int cnt[26];
string str;

int calS(int l, int r){
	memset(cnt, 0, sizeof(cnt));
	for(int i = l; i <= r; i++)
	  cnt[str[i]-'a']++;
	int sum = 0;
	for(int i = 0; i < 26; i++)
	  if(cnt[i] == 1)
		sum++;
	return sum;
}

int dfs(int l, int r){
	if(l > r)return 0;
	if(l == r)return 1;
	dp[l] = dfs(l, r-1)+dfs(l+1, r)+calS(l, r)-calS(l+1,r-1);
	return dp[l];
}

int main()
{
	while(cin>>str){
		int len = str.length();
		int ans = dfs(0, len-1);
		cout<<ans<<endl;
	}

	return 0;
}
