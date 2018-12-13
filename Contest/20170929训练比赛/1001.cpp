//2017-09-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int digit[20], tot;

int main()
{
	int n;
	while(cin>>n && n){
		int ans = 0, tmp = n;
		tot = 0;
		while(tmp){
			int a = tmp%10;
			if(a >= 9)a -= 2;
			else if(a >= 4)a -= 1;
			digit[tot++] = a;
			tmp /= 10;
		}
		for(int i = tot-1; i >= 0; i--){
			ans *= 8;
			ans += digit[i];	
		}
		cout<<n<<": "<<ans<<endl;
	}

	return 0;
}
