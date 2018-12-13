#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;

bool book[N];

int main()
{
	for(int n = 1; n < 100; n++){
		memset(book, 0, sizeof(book));
		for(int i = 1; i <= n; i++){
			int p = i;
			while(p <= n){
				book[p] = !book[p];
				p += i;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		  if(book[i])ans++;
		cout<<n<<": "<<ans<<endl;
	}

	return 0;
}
