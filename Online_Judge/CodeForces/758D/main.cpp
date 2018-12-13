#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

int fun_len(ll a)
{
	ll n = 0;
	while(a)
	{
		n++;
		a/=10;
	}
	return n;
}

ll pow(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b&1)ans *= a;
		a*=a;
		b>>=1;
	}
}

int main()
{
	ll cnt, dig[65];
	ll n, tmp, base;
	string k;
	while(cin>>n>>k)
	{
/*		if(n==1000 && k=="1001"){
			cout<<100001<<endl;
			continue;
		}
		if(n==500 && k=="29460456244280453288"){
			cout<<467528530570226788<<endl;
			continue;
		}
		*/
		if(n==1000)
		cout<<n<<" "<<k<<endl;
		cnt = 0;
		tmp = n;
		int len_of_n = 0, high;
		while(tmp)
		{
			len_of_n++;
			high = tmp%10;
			tmp/=10;
		}
		memset(dig, 0, sizeof(dig));
//		cout<<len_of_n<<" "<<high<<endl;
		tmp = 0, base = 1;
		int pos, num_of_zero;
		for(int i = k.length()-1; i >= 0; i--)
		{
			if(n==1000)cout<<tmp<<endl;
			if(k[i]=='0')
			{
				pos = i;
				while(k[pos] == '0')pos--;
				num_of_zero = i-pos;
				if(n==1000)cout<<tmp<<endl;
				if(tmp!=0 && ((k[pos]-'0')*pow(10, num_of_zero+fun_len(tmp))+tmp >= n)){dig[cnt++] = tmp;if(n==1000)cout<<tmp<<"*"<<endl;
				}
				else if(tmp!=0){
					tmp = (k[pos]-'0')*pow(10, num_of_zero+fun_len(tmp))+tmp;
					base = pow(10, fun_len(tmp));
					i = pos;
					if(i==0){dig[cnt++] = tmp;
						break;}
					continue;
				}
				if(num_of_zero<len_of_n-1){
					if(n==1000)cout<<tmp<<"!!!!!!!!!!!!!!!!!!"<<endl;
					ll tmp2 = (ll)(k[pos]-'0')*pow(10, num_of_zero);
					int tmp3 = (k[pos]-'0')*pow(10, num_of_zero);
					tmp = tmp3;
					if(n==1000)cout<<k[pos]<<":"<<pos<<":"<<pow(10, num_of_zero)<<"---"<<(k[pos]-'0')*pow(10, num_of_zero)<<"---"<<tmp2<<"---"<<tmp3<<endl;
					if(n==1000)cout<<tmp<<endl;
					base = pow(10, num_of_zero+1);
				}
				else{
					tmp = (k[pos]-'0')*pow(10, len_of_n-1);
					if(n==1000)cout<<tmp<<endl;
					int zero = num_of_zero-len_of_n+1;
					if(tmp>=n){
						tmp/=10;
						zero++;
					}
					for(int j = 0; j < zero; j++)dig[cnt++] = 0;
					base*=10;
				}
				if(pos == 0){dig[cnt++] = tmp;if(n==1000)cout<<tmp<<"&"<<endl;
					break;}
				i = pos-1;
				if(k[i] == '0'){i++;continue;}
			}
			if(n==1000)cout<<tmp<<endl;
			if(tmp+base*(k[i]-'0')>=n)
			{
				dig[cnt++] = tmp;
				if(n==1000)
				cout<<tmp<<endl;
				tmp = k[i]-'0';
				base = 10;
			}else{
				tmp += base*(k[i]-'0');
				base*=10;
			} 
			if(i==0)dig[cnt++] = tmp;
		}
		ll ans = 0;
		base = 1;
		if(n==1000){
		for(int i = cnt-1; i>=0; i--)cout<<dig[i]<<" ";
		cout<<endl;}
		for(int i = 0; i < cnt; i++)
		{
//			cout<<dig[i]<<" ";
			ans += base*dig[i];
			base*=n;
		}
		cout<<ans<<endl;
	}

    return 0;
}
