//2016.9.8
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ull unsigned long long

using namespace std;

const int N = 100005;
char s1[N], s2[N];
int len1, len2;
ull h1[N], h2[N], a[N], Pow[N];

ull get_hash(ull *h, int l, int r)
{
	return h[r]-h[l]*Pow[r-l];
}

bool solve(int len)
{
	int cnt = 0;
	for(int i = len; i <= len1; i++)
	  	a[cnt++] = get_hash(h1, i-len, i);
	sort(a, a+cnt);
	for(int i = len; i <= len2; i++)
	{
		ull h = get_hash(h2, i-len, i);
		if(binary_search(a, a+cnt, h))
		  	return true;
	}
	return false;
}

int main()
{
	scanf("%s%s", s1, s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	int l = 0, r = max(len1, len2), mid;
	Pow[0] = 1;
	for(int i = 1; i <= r; i++)
	  	Pow[i] = Pow[i-1]*131;
	h1[0] = h2[0] = 0;
	for(int i = 0; i < len1; i++)
	  	h1[i+1] = h1[i]*131+s1[i];
	for(int i = 0; i < len2; i++)
	  	h2[i+1] = h2[i]*131+s2[i];
	while(l < r)
	{
		mid = (l+r)>>1;
		if(solve(mid+1))l = mid+1;
		else r = mid;
	}
	printf("%d\n", l);

    return 0;
}
