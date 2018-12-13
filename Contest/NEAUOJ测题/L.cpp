#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int LEN = 100;
int cnt[LEN][30];

int main()
{
	string str;
	int q, l, r;
	char ch;
	while(cin>>str){
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < str.length(); i++){
			cnt[i/LEN][str[i]-'a']++;
		}
		cin>>q;
		while(q--){
			scanf("%d %d %c", &l, &r, &ch);
			l--, r--;
			int L = l/LEN, R = r/LEN, ans = 0;
			if(L == R){
				for(int i = l; i <= r; i++)
				  	if(str[i] == ch)
					  	ans++;
			}else{
				for(int i = l; i < (L+1)*LEN; i++)
				  	if(str[i] == ch)
					  	ans++;
				for(int i = R*LEN; i <= r; i++)
				  	if(str[i] == ch)
					  	ans++;
				for(int i = L+1; i < R; i++)
				  	ans += cnt[i][ch-'a'];
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}
