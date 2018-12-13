//2016.8.17
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 10005;
const int M = 80;
char grid[N][M];
int nex[N];

int gcd(int a, int b)
{
	return b==0?a:gcd(b, a%b);
}

int lcm(int a, int b)
{
	return a/gcd(a, b)*b;
}

void getNext(int pos, int n, int fg)//构造next[]数组，fg为标记，0为行，1为列
{
	nex[0] = -1;
	for(int i = 0, fail = -1; i < n;)
	{
		if(fg == 0 && (fail == -1 || grid[pos][i] == grid[pos][fail]))
		{
			i++, fail++;
			nex[i] = fail;
		}else if(fg == 1 && (fail == -1 || grid[i][pos] == grid[fail][pos]))
		{
			i++, fail++;
			nex[i] = fail;
		}else fail = nex[fail];
	}
}

int main()
{
	int n, m, clen, rlen;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		clen = rlen = 1;
		for(int i = 0; i < n; i++)
			scanf("%s", grid[i]);
		for(int i = 0; i < n; i++)//用最小公倍数找到循环块的宽度
		{
			getNext(i, m, 0);
			rlen = lcm(rlen, m-nex[m]);//m-nex[m]为该行最小循环节的长度
			if(rlen>=m){
				rlen = m; break;
			}
		}
		for(int i = 0; i < m; i++)//用最小公倍数找到循环块的高度
		{
			getNext(i, n, 1);
			clen = lcm(clen, n-nex[n]);//n-nex[n]为该列最小循环节的长度
			if(clen>=n){
				clen = n; break;
			}
		}
		printf("%d\n", clen*rlen);
	}
	return 0;
}
