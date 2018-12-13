#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin>>T;
	double R, ans;
	cin>>R;
	int k;
	for(int kase = 1; kase <= T; kase++){
		cin>>k;
		cout<<k<<" ";
		if(k == 1){
			cout<<(int)((2.0/sqrt(3)-1)*R)<<endl;
		}else{
			double w = (2.0*sqrt(3)+1)/11.0;
			ans = (2.0/sqrt(3)-1)*R;
			for(int i = 0; i < k-1; i++)
			  	ans *= w;
			cout<<(int)ans<<endl;
		}
	}
	cin>>k;

	return 0;
}
