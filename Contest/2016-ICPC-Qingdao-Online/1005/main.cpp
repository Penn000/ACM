//2016.9.17
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		if(n&1)printf("Balanced\n");
		else printf("Bad\n");
	}

    return 0;
}
