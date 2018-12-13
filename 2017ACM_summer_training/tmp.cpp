#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void ext_gcd(int a, int b, int &d, int &x, int &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        ext_gcd(b, a%b, d, y, x);
        y -= x*(a/b);
    }
}

int mod_inverse(int a, int m)
{
    int x, y,d;
    ext_gcd(a, m, d, x, y);
    return (m + x % m) % m;
}

int main(){
    int MOD = (int)1e9+7;
	cout<<__builtin_popcount(65535)<<endl;
    return 0;
}
