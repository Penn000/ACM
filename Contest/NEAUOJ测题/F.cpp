#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, a;
	while(cin>>n){
		int ans = 0;
		while(n--){
			cin>>a;
			if(a % 3 == 0)ans++;
		}
		cout<<ans<<endl;
	}


	return 0;
}
