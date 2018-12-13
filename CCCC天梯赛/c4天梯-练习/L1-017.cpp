//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string num;
	while(cin>>num)
	{
		double ans = 100.0;
		int len = num.length();
		if((num[len-1]-'0')%2==0)ans*=2.0;
		if(num[0]=='-'){
			len -= 1;
			ans *= 1.5;
		}
		int cnt = 0;
		for(int i = 0; i < num.length(); i++)
		{
			if(num[i] == '2')cnt++;
		}
		ans *= (cnt*1.0/len);
		printf("%.2f", ans);
		printf("%\n");
	}

    return 0;
}
