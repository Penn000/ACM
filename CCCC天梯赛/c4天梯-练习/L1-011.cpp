//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

bool book[300];

int main()
{
	char s1[10005], s2[10005];
	while(gets(s1))
	{
		gets(s2);
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		memset(book, 0, sizeof(book));
		for(int i = 0; i < l2; i++)
		  	book[s2[i]] = 1;
		for(int i = 0; i < l1; i++)
		  	if(!book[s1[i]])
			  	printf("%c", s1[i]);
		printf("\n");
	}

    return 0;
}
