#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int random0(int n){
	return ((double)rand() / RAND_MAX*n + 0.5);
}

int main()
{
	int n;
	int x, T = 20;
	while(T--){
		n = random0(20);
		cout<<n<<endl;
		while(n--){
			x = random0(50);
			cout<<x<<" ";
		}
		cout<<endl;
	}


	return 0;
}
