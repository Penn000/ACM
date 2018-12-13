//2018-08-11
#include <iostream>
#include <cstring>
#define ll long long

using namespace std;

int main(){
    ll T, n, m, a, b, c, kase = 0, maximum, minimum;
    cin>>T;
    while(T--){
        cin>>n>>m>>a>>b>>c;
		if(a < c)swap(a, c);

		maximum = (n-m-1)*max(a, b);
		ll tmp1 = (m/2)*(a+c);
		ll tmp2 = (m/2)*(b+b);
		maximum += max(tmp1, tmp2);
		if(m&1)maximum += max(b, c);

		minimum = (m-1)*min(b, c);
		tmp1 = (n-m)/2*(a+c);
		tmp2 = (n-m)/2*(b+b);
		minimum += min(tmp1, tmp2);
		if((n-m)&1)minimum += min(a, b);

        cout<<"Case #"<<++kase<<": "<<maximum<<" "<<minimum<<endl;
    }

    return 0;
}
