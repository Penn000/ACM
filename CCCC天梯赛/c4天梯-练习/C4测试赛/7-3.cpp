#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const char chs[4] = {'G', 'P', 'L', 'T'};

int main()
{
	string str;
	int book[4];
	while(cin>>str){
		memset(book, 0, sizeof(book));
		for(int i = 0; i < str.length(); i++){
			if(str[i] == 'G' || str[i] == 'g')book[0]++;
			if(str[i] == 'P' || str[i] == 'p')book[1]++;
			if(str[i] == 'L' || str[i] == 'l')book[2]++;
			if(str[i] == 'T' || str[i] == 't')book[3]++;
		}
		int sum = 0;
		for(int i = 0; i < 4; i++)
		  sum += book[i];
		while(sum){
			for(int i = 0; i < 4; i++){
				if(book[i]){
					printf("%c", chs[i]);
					book[i]--;
					sum--;
				}
			}
		}
		printf("\n");
	}

	return 0;
}
