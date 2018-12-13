//2017-08-22
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
int arr[N];

int main()
{
    int n;
	std::ios::sync_with_stdio(false);
	while(cin>>n){
		long long sum = 0;
		int odd = 0, even = 0;
		for(int i = 0; i < n; i++){
		  	cin>>arr[i];
			sum += arr[i];
			if(arr[i]&1)odd++;
			else even++;
		}
		if(sum & 1)cout<<"First"<<endl;
		else{
			if(odd == 0)cout<<"Second"<<endl;
			else cout<<"First"<<endl;
		}
	}

	return 0;
}
