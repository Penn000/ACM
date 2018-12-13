//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a, b;
	while(cin>>a>>b)
	{
		int sum = 0, cnt = 0;
		for(int i = a; i <= b; i++)
		{
			sum += i;
			printf("%5d", i);
			cnt++;
			if(cnt == 5 || i == b){
				printf("\n");
				cnt = 0;
			}
		}
		printf("Sum = %d\n", sum);
	}

    return 0;
}
