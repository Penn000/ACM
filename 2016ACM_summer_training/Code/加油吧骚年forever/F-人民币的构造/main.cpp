#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int N = 100005;
int qian[15] = {1, 2, 7, 21, 63, 189, 1701, 5103, 15309, 45927};
int sum[15] = {1, 3, 10, 31, 94, 283, 1984, 7087, 22396, 68323, 999999};
bool book[N];

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i = 0; i < 10; i++)
		{
			if(sum[i]>=n)
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}

	return 0;
}
