//2016.8.2
//http://acm.hust.edu.cn/vjudge/contest/125415#problem/A
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long a[3];
	while(cin >> a[0] >> a[1] >> a[2])
	{
		sort(a, a+3);
		if(a[2] > 2*(a[0]+a[1]))cout << a[0]+a[1] << endl;
		else cout << (a[0]+a[1]+a[2])/3 << endl;
	}

	return 0;
}
