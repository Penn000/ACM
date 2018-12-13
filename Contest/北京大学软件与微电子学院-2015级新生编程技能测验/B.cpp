#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000000;

int a[N], b[N], n1, n2;

int main()
{
	n1 = n2 = 0;
	int num;
	char ch;
	while(1){
		scanf("%d", &num);
		a[n1++] = num;
		scanf("%c", &ch);
		if(ch == '.')break;
		scanf("%c", &ch);
	}
	while(1){
		scanf("%d", &num);
		b[n2++] = num;
		scanf("%c", &ch);
		if(ch == '.')break;
		scanf("%c", &ch);
	}
	int p1 = 0, p2 = 0, cnt = 0;
	while(cnt < n1+n2){
		if(a[p1] < a[p2]){
			printf("%d->", a[p1]);
			cnt++;
			p1++;
		}else if(a[p1] > b[p2]){
			printf("%d->", b[p2]);
			cnt++;
			p2++;
		}else{
			printf("%d->%d->", a[p1], b[p2]);
			cnt += 2;
			p1++;
			p2++;
		}
		if(p1 >= n1){
			for(int i = p2; i < n2; i++)
				printf("%d->", b[i]);
			break;
		}
		if(p2 >= n2){
			for(int i = p1; i < n1; i++)
				printf("%d->", a[i]);
			break;
		}
	}
	printf("NULL\n");

	return 0;
}
