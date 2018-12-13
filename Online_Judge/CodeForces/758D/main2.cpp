//2016.01.21
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
	ll n;
	string k;
	while(cin>>n>>k)
	{
		cnt = 0;
		ll tmp = n, base;
		int len_of_n = 0, high;
		while(tmp)
		{
			len_of_n++;
			high = tmp%10;
			tmp/=10;
		}
		memset(dig, 0, sizeof(dig));
		tmp = 0, base = 1;
		for(int i = k.length()-1; i >= 0; i--)
		{
			if(k[i]=='0')
			{
				int pos = i;
				while(k[pos] == '0')pos--;
				int num_of_zero = i-pos;
				if(tmp!=0 && ((k[pos]-'0')*pow(10, num_of_zero+fun_len(tmp))+tmp>=n))dig[cnt++] = tmp;
				else if(tmp!=0){
					tmp = (k[pos]-'0')*pow(10, num_of_zero+fun_len(tmp))+tmp;
					base = pow(10, fun_len(tmp));
					i = pos;
					if(i==0){dig[cnt++] = tmp; break;}
					continue;
				}
				if(num_of_zero<len_of_n-1){
					tmp = (k[pos]-'0')*pow(10, num_of_zero);
					base = pow(10, num_of_zero+1);
				}
				else{
					tmp = (k[pos]-'0')*pow(10, len_of_n-1);
					int zero = num_of_zero-len_of_n+1;
					if(tmp>=n){
						tmp/=10;
						zero++;
					}
					for(int j = 0; j < zero; j++)dig[cnt++] = 0;
					base*=10;
				}
				if(pos == 0){dig[cnt++] = tmp; break;}
				i = pos-1;
				if(k[i] == '0'){i++;continue;}
			}
			if(tmp+base*(k[i]-'0')>=n)
			{
				dig[cnt++] = tmp;
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
		for(int i = 0; i < cnt; i++)
		{
			ans += base*dig[i];
			base*=n;
		}
		cout<<ans<<endl;
	}

    return 0;
}
