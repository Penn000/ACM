#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string str;

int main()
{
	while(cin>>n>>m>>str){
		int l, r;
		char c1, c2;
		while(m--){
			cin>>l>>r>>c1>>c2;
			l--, r--;
			for(int i = l; i <= r; i++)
			  	if(str[i] == c1)
				  	str[i] = c2;
		}
		cout<<str<<endl;
	}

	return 0;
}
