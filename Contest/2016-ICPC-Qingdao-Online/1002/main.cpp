//2016.9.17
#include <iostream>
#include <cstdio>

using namespace std;

double sum[54000];

int main()
{
	int n;
	double ans;
	ans = 0;
	sum[0] = 0;
	for(int i = 1; i <= 53000; i++)
	{
		ans += (1.0/i)*(1.0/i);	
		sum[i] = ans;
	}
	string s;
	while(cin>>s)
	{
		int len = s.length();
		n = 0;
		for(int i = 0; i < len; i++)
		{
			n = n*10+s[i]-'0';
			if(n > 120000)break;
		}
		if(n >= 110291)ans = 1.64493;
		else if(n >= 52447)ans = 1.64492;
		else ans = sum[n];
		printf("%.5lf\n", ans);
	}

    return 0;
}
