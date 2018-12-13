//2017-08-31
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 300010;
char str[N<<1], str2[N];

//最小循环表示
//input: str[2*len] 原串扩展了一倍的串。如原串为“abc”， str为“abcabc”。
//		 len 原串的长度。
//output：ptr 最小循环表示法的起始下标。
int min_representation(int len){
	int i = 0, j = 1, k = 0;
	while(i < len && j < len && k < len){
		if(str[i+k] == str[j+k])k++;
		else{
			if(str[i+k] < str[j+k]) j += k+1;
			else i += k+1;
			k = 0;
			if(i == j)j++;
		}
	}
	return min(i, j);
}

int main()
{
	while(scanf("%s", str2) != EOF){
		int len = strlen(str2);
		for(int i = 0; i < len-1; i++){
			str[i] = (str2[i+1] - str2[i] + 8) % 8 + '0';
			str[i+len] = str[i];
		}
		str[len-1] = (str2[0] - str2[len-1] + 8) % 8 + '0';
		str[len-1+len] = str[len-1];
		int ptr = min_representation(len);
		str[ptr+len] = '\0';
		printf("%s\n", str+ptr);
	}

	return 0;
}
