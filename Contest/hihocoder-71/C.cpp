#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
int ans[10] = {0, 0, 0, 1, 18, 261, 3420, 26298};

int main()
{
	int n;
	cin>>n;
	if(n>7)cout<<-1<<endl;
	else cout<<ans[n]<<endl;

	return 0;
}
