#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, a;
	while(cin>>n){
		int ji = 0;
		int ou = 0;
		while(n--){
			scanf("%d", &a);
			if(a&1)ji++;
			else ou++;
		}
		printf("%d %d\n", ji, ou);
	}

	return 0;
}
