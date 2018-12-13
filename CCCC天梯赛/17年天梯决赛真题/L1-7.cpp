#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while(cin>>n){
		string str;
		int a, b;
		while(n--){
			cin>>str>>a>>b;
			if(a >= 15 && a <= 20 && b >= 50 && b <= 70)continue;
			else cout<<str<<endl;
		}
	}

	return 0;
}
