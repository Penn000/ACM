#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long x, s, n;
	while(cin>>x){
		n = 1;
		for(long long tmp = 1; ; tmp = 10*tmp+1){
			if(tmp % x == 0){
				cout<<tmp/x<<" "<<n<<endl;
				break;
			}
			n++;
		}
	}

	return 0;
}
