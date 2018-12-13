#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11000;
int cnt[30][N];
char str[N];

int main()
{
	int q, l, r;
	char ch;
	while(~scanf("%s", str)){
		int n = strlen(str);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++){
			cnt[str[i]-'a'][i] = 1;
		}
		for(int i = 0; i < 26; i++){
			for(int j = 1; j < n; j++){
				cnt[i][j] += cnt[i][j-1];
			}
		}
		scanf("%d", &q);
		while(q--){
			scanf("%d %d %c", &l, &r, &ch);
			l--, r--;
			if(l == 0)//cout<<cnt[ch-'a'][r]<<endl;
				printf("%d\n", cnt[ch-'a'][r]);
			else// cout<<cnt[ch-'a'][r]-cnt[ch-'a'][l-1]<<endl;
				printf("%d\n", cnt[ch-'a'][r]-cnt[ch-'a'][l-1]);
		}
	}

	return 0;
}
