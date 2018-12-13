//2016.9.30
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105

using namespace std;

int len[N];

int main()
{
	int n, k, len_of_ans, low_ans, high_ans;
	string str;
	while(scanf("%d%d", &n, &k)!=EOF)
	{
		memset(len, 0, sizeof(len));
		for(int i = 0; i < n; i++)
		{
			cin>>str;
			len[str.length()]++;
		}
		cin>>str;
		len_of_ans = str.length();
		low_ans = high_ans = 0;
		int cnt = 0;
		for(int i = 1; i < len_of_ans; i++)
		{
			cnt += len[i];
		}
		low_ans = cnt/k*5 + cnt + 1;
		high_ans = (cnt+len[len_of_ans]-1)/k*5+cnt+len[len_of_ans];
		cout<<low_ans<<" "<<high_ans<<endl;
	}

    return 0;
}
