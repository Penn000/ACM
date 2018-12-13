//2017-08-10
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000010;
char str[N];
int nex[N];

void getNext(int n)
{
    nex[0] = -1;
    for(int i = 0, fail = -1; i < n;)
    {
        if(fail==-1||str[i]==str[fail])
        {
            i++, fail++;
            nex[i] = fail;
        }else fail = nex[fail];
    }
}

int main()
{
	while(scanf("%s", str)!=EOF)
	{
		if(str[0] == '.')break;
		int n = strlen(str);
		getNext(n);
		int ans = n-nex[n];
		if(n%ans == 0)
			printf("%d\n", n/ans);
		else printf("1\n");
	}

	return 0;
}
