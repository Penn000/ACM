#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100005;

int book[26];
string str;

int cal(){
	int ans = 0;
	for(int i = 0; i < 26; i++)
	  if(book[i] == 1)ans++;
	return ans;
}

int main()
{
	while(cin>>str){
		int n = str.length();
		int ans = n;
		for(int len = 2; len <= n; len++){
			memset(book, 0, sizeof(book));
			for(int j = 0; j < len; j++)
			  book[str[j]-'a']++;
			ans += cal();
			for(int l = 1; l+len-1 < n; l++){
				int r = l+len-1;
				book[str[l-1]-'a']--;
				book[str[r]-'a']++;
				ans+=cal();
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
