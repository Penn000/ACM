//2017.01.19
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	string light;
	int k[10];
	char l[4] = {'r', 'b', 'y', 'g'};
	int order[4];
	while(cin >> light)
	{
		int cnt = 0;
		memset(order, 0, sizeof(order));
		memset(k, 0, sizeof(k));
		for(int i = 0; i < light.length(); i++)
		{
			if(light[i] != '!')
			{
				if(light[i] == 'R')order[i%4] = 1;
				else if(light[i] == 'B')order[i%4] = 2;
				else if(light[i] == 'Y')order[i%4] = 3;
				else if(light[i] == 'G')order[i%4] = 4;
			}
		}
		for(int i = 0; i < light.length(); i++)
		{
			if(light[i] == '!')
			  	k[order[i%4]]++;
		}
		for(int i = 1; i <= 4; i++)
		  	if(i == 4)cout<<k[i]<<endl;
			else cout<<k[i]<<" ";
	}

    return 0;
}
