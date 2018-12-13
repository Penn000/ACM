#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
string str;
int n, k, book[30], l[30], r[30];

int main()
{
	while(cin>>n>>k>>str){
		memset(book, 0, sizeof(book));
		memset(l, INF, sizeof(l));
		memset(r, 0, sizeof(r));
		for(int i = 0; i < n; i++){
			book[str[i]-'A'] = 1;
			l[str[i]-'A'] = min(l[str[i]-'A'], i);
			r[str[i]-'A'] = max(r[str[i]-'A'], i);
		}
		//for(int i = 0; i < 2; i++)
		//  	cout<<l[i]<<" "<<r[i]<<endl;
		int num = 0;
		for(int i = 0; i < 26; i++)
		  	num += book[i];
		int ans = 0;
		for(int i = 0; i < 26; i++){
			int cnt = 0;
			for(int j = 0; j < 26; j++){
				if((l[i] < l[j] && l[j] < r[i])
				 ||(l[i] < r[j] && r[j] < r[i]))
				  	cnt++;
			}
			ans = max(ans, cnt);
			if(cnt == 0 && book[i])num--;
		}
		//cout<<ans<<endl;
		if(ans <= k && num <= k)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

	return 0;
}
