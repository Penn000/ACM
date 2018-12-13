//2016.10.06
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110005;
char str[N], s[N<<1];
int a[N<<1];


//s为待求字符串，len为字符串长度，a[i]为以s[i]为中心的最长回文串的长度的一半。若s为前后添加过特殊字符的字符串，则返回值为原来字符串种最长回文串的长度。
int manacher(char *s, int *a, int len)
{
	a[0] = 0;
	int ans = 0, j;
	for(int i = 0; i < len; )
	{
		while(i-a[i]>0 && s[i+a[i]+1]==s[i-a[i]-1])
		  	a[i]++;
		if(ans < a[i])ans = a[i];
		j = i+1;
		while(j<=i+a[i] && i-a[i]!=i+i-j-a[i+i-j]){
			a[j] = min(a[i+i-j], i+a[i]-j);
			j++;
		}
		a[j] = max(i+a[i]-j, 0);
		i = j;
	}
	return ans;
}

int main()
{
	int len;
	while(scanf("%s", str)!=EOF)
	{
		len = 2*strlen(str)+1;
		for(int i = 0; str[i] != '\0'; i++)//将字符串每一位中间插入一个特殊字符
		{
			s[i+i] = '\0';
			s[i+i+1] = str[i];
		}
		s[len-1] = '\0';
		printf("%d\n", manacher(s, a, len));
	}

    return 0;
}
