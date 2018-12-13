#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int ec[20] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};
int num[10], tmp[10];

long long sum(int pos)
{
	long long ans = 0;
	for(int i = 0; i < 8; i++)
	  if(i < pos)ans += ec[num[i]];
	  else break;
	return ans;
}

void change(int pos)
{
	for(int i = 7; i > 0; i--)
	  if(num[i] >= 16){
		  num[i] -= 16;
		  num[i-1]+=1;
	  }
	if(num[0] == 16){
		for(int i = 0; i < pos; i++)
		  num[i] = 0;
	}
}

int main()
{
	int T, n;
	char str[10];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		scanf("%s", str);
		for(int i = 0; i < 8; i++)
		{
			if(str[i] == 'A')num[i] = 10;
			else if(str[i] == 'B')num[i] = 11;
			else if(str[i] == 'C')num[i] = 12;
			else if(str[i] == 'D')num[i] = 13;
			else if(str[i] == 'E')num[i] = 14;
			else if(str[i] == 'F')num[i] = 15;
			else num[i] = str[i]-'0';
		}
		for(int i = 0; i < 8; i++)tmp[i] = num[i];	
		long long ans = 0;

		int mod = n%16777216;
		int step = 16777216-num[2]*1048576-num[3]*65536-num[4]*4096-num[5]*256-num[6]*16-num[7];
		for(int i = 0; i < n-mod; i+=16777216)
		{
			ans += sum(1)*step+6*78*1048576+ec[num[1]]*step;
			num[1]+=1;
			change(2);
			ans += sum(1)*(16777216-step)+ec[num[1]]*(16777216-step);
		}

		int mod0 = mod%1048576;
		step = 1048576-num[3]*65536-num[4]*4096-num[5]*256-num[6]*16-num[7];
		for(int i = 0; i < mod-mod0; i+=1048576)
		{
			ans += sum(2)*step+5*78*65536+ec[num[2]]*step;
			num[2]+=1;
			change(3);
			ans += sum(2)*(1048576-step)+ec[num[2]]*(1048576-step);
		}

		int mod1 = mod0%65536;
		step = 65536-num[4]*4096-num[5]*256-num[6]*16-num[7];
		for(int i = 0; i < mod0-mod1; i+=65536)
		{
			ans += sum(3)*step+4*78*4096+ec[num[3]]*step;
			num[3]+=1;
			change(4);
			ans += sum(3)*(65536-step)+ec[num[3]]*(65536-step);
		}

		int mod2 = mod1%4096;
		step = 4096-num[5]*256-num[6]*16-num[7];
		for(int i = 0; i < mod1-mod2; i+=4096)
		{
			ans += sum(4)*step+3*78*256+ec[num[4]]*step;
			num[4]+=1;
			change(5);
			ans += sum(4)*(4096-step)+ec[num[4]]*(4096-step);
		}

		int mod3 = mod2%256;
		step = 256-num[6]*16-num[7];
		for(int i = 0; i < mod2-mod3; i+=256)
		{
			ans += sum(5)*step+2*78*16+ec[num[5]]*step;
			num[5]+=1;
			change(6);
			ans += sum(5)*(256-step)+ec[num[5]]*(256-step);
		}

		for(int i = 0; i < mod3; i++)
		{
			ans += sum(10);
			num[7]+=1;
			change(7);
		}
		printf("%lld\n", ans);/*
		for(int i = 0; i < 8; i++)num[i] = tmp[i];
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			ans += sum(10);
			num[7]+=1;
			change(8);

		}
		printf("%lld\n", ans);*/
	}
	return 0;

}
