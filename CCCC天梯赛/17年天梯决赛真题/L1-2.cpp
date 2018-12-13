#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int mm, dd, yyyy;
	while(~scanf("%d-%d-%d", &mm, &dd, &yyyy)){
		printf("%4d-%02d-%02d\n", yyyy, mm, dd);
	}

	return 0;
}
