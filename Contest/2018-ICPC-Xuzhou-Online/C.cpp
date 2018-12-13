#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int reward[50] = {0, 0, 0, 0, 0, 0, 10000, 36, 720, 360, 80, 252, 108, 72, 54, 180, 72, 180, 119, 36, 360, 1080, 144, 1800, 3600};

int main()
{
	for(int i = 6; i <= 24; i++)
	  cout<<i<<" "<<reward[i]<<endl;


	return 0;
}
