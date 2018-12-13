#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100005;
char str[N], sum[N];

int judge(int l, int r)
{
	for(int i = l; i <= r ; i++)
	{
		if(str[i] != '0')break;
		else l++;

	}
	for(int i = r; i >= l; i--)
	{
		if((str[i]-'0')%2)r--;
		else break;

	}
	if(l > r)return 0;
	int x = (sum[r] - sum[l] + str[l] -'0')%3;
	if(x == 0){
		return r-l+1;
	}else if(x == 1){
		int cnt1 = 0, cnt2 = 0;
		for(int i = l+1; i < r; i++){
			if((str[i]-'0')%3==1)cnt1++;
			else if((str[i]-'0')%3==2)cnt2++;
		}
		if(cnt1>=1)return r-l;
		else if(cnt2>=2) return r-l-1;
		else return max(judge(l+1, r), judge(l, r-1));
	}else{
		int cnt1 = 0, cnt2 = 0;
		for(int i = l+1; i < r; i++){
			if((str[i]-'0')%3==1)cnt1++;
			else if((str[i]-'0')%3==2)cnt2++;

		}
		if(cnt2>=1)return r-l;
		else if(cnt1>=2) return r-l-1;
		else return max(judge(l+1, r), judge(l, r-1));
	}
}

int main()
{
	int l, r;
	while(scanf("%s", str)!=EOF)
	{
		getchar();
		l = 0;
		r = strlen(str)-1;
		for(int i = 0; i <= r ; i++)
		{
			if(str[i] != '0')break;
			else l++;
		}
		if(l > r){
			printf("1\n");
			continue;
		}
		for(int i = r; i >= l; i--)
		{
			if((str[i]-'0')%2)r--;
			else break;
		}
		sum[l] = str[l]-'0';
		for(int i = l+1; i <= r; i++)
		  sum[i] = sum[i-1] + (str[i]-'0');
		int ans = judge(l, r);
		if(ans <= 0)printf("-1s\n");
		else printf("%d\n", ans);
	}

	return 0;
}
