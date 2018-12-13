#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool ans[100] = {1, 0, 1, 1, 0, 1, 1, 0, 0, 1};

int main()
{
	int T, a;
	cin>>T;
	for(int k = 0; k < T; k++){
		for(int i = 0; i < 8; i++)
		  	for(int j = 0; j < 9; j++)
			  	cin>>a;
		if(ans[k])cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
