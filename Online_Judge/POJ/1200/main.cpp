//2016.9.4
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 16000005

using namespace std;

char str[N];
bool Hash[N];
int id[500];

int main()
{
	int n, nc, ans, cnt;
	while(scanf("%d%d", &n, &nc)!=EOF)
	{
		cnt = ans = 0;
		memset(Hash, false, sizeof(Hash));
		memset(id, -1, sizeof(id));
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len && cnt < nc; i++)//对str出现的字符进行编号，使之转换成数字
		{
			if(id[str[i]] != -1)continue;
			id[str[i]] = cnt++;
		}
		for(int i = 0; i < len-n+1; i++)//把长度为n的子串hash成nc进制数
		{
			int tmp = 0;
			for(int j = i; j < i+n; j++)
				tmp = tmp*nc+id[str[j]];
			if(Hash[tmp])continue;
			ans++;
			Hash[tmp] = true;
		}
		printf("%d\n", ans);
	}

    return 0;
}
