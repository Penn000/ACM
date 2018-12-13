//2016.9.4
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#define N 100005

using namespace std;

char s1[N][12], s2[N][12], str[25];
map<long long, int> Hash;

long long F(char* s)//把字符串hash成一个26进制数
{
	int len = strlen(s);
	long long h = 0;
	for(int i = 0; i < len; i++)
		h = h*26+(s[i]-'a');
	return h;
}

int main()
{
	int cnt = 0;
	while(gets(str))
	{
		if(str[0] == '\0')break;
		sscanf(str,"%s%s", s1[cnt], s2[cnt]);
		long long h = F(s2[cnt]);
		Hash[h] = cnt;
		cnt++;
	}
	while(gets(str))
	{
		if(str[0] == '\0')break;
		long long h = F(str);
		if(Hash.find(h)!=Hash.end())//map按key查找，失败返回end
		printf("%s\n", s1[Hash[h]]);
		else printf("eh\n");
	}

    return 0;
}
