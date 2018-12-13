#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int a[4];
	while(1)
	{
		for(int i = 0; i < 4; i++)
		  	scanf("%d", &a[i]);
		sort(a, a+4);
		do{
			for(int i = 0; i < 4; i++)cout<<a[i];
			cout<<endl;
		}while(next_permutation(a, a+4));
	}
    return 0;
}
