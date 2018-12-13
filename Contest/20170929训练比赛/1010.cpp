//2017-09-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5500;

int arr[N];
int book[10000000];
char str[10];

int change(char ch){
	if('a' <= ch && ch <= 'c')return 2;
	if('d' <= ch && ch <= 'f')return 3;
	if('g' <= ch && ch <= 'i')return 4;
	if('j' <= ch && ch <= 'l')return 5;
	if('m' <= ch && ch <= 'o')return 6;
	if('p' <= ch && ch <= 's')return 7;
	if('t' <= ch && ch <= 'v')return 8;
	if('w' <= ch && ch <= 'z')return 9;
}

int main()
{
	int T, n, m;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			book[arr[i]] = 0;
		}
		for(int i = 0; i < m; i++){
			scanf("%s", str);
			int tmp = 0;
			for(int j = 0; str[j] != '\0'; j++){
				tmp *= 10;
				tmp += change(str[j]);
			}
			//printf("%s -> %d\n", str, tmp);
			book[tmp]++;
		}
		for(int i = 0; i < n; i++){
			printf("%d\n", book[arr[i]]);
		}
	}

	return 0;
}
