#include <iostream>
#include <cstdio>
#include <cstring>
#define N 100005

using namespace std;

char s1[N], s2[N];
int nex[N], ex[N], len1, len2;

void exkmp(char a[], char b[], int nex[], int ex[])
{
	int i, j, p;
	for(i = 0, j = 0, p = -1; a[i] != '\0'; i++, j++, p--)
	{
		if(p == -1){
			j = 0;
			do{
				p++;
			}while(a[i+p] != '\0' && a[i+p] == b[i+p]);
			ex[i] = p;
		}else if(nex[j] < p)ex[i] = nex[j];
		else if(nex[j] > p)ex[i] = p;
		else{
			j = 0;
			while(a[i+p]!='\0' && a[i+p] == b[i+p])
			  	p++;
			ex[i] = p;
		}
	}
	ex[i] = 0;
}

bool smaller(int i, int j)
{
	if(ex[j] < (i-j))return s1[j+ex[j]]<s2[ex[j]];
	if(nex[i-j] < len2-i+j)return s2[nex[i-j]]<s2[i-j+nex[i-j]];
	if(nex[len2-i+j]<(i-j))return s2[len2-i+j + nex[len2-i+j]] < s2[nex[len2-i+j]];
	return false;
}

int main()
{
	while(scanf("%s%s", s1, s2)!=EOF)
	{
		len1 = strlen(s1);
		len2 = strlen(s2);
		nex[0] = 0;
		exkmp(s2+1, s2, nex, nex+1);
		exkmp(s1, s2, nex, ex);
		int pos = 0;
		for(int i = 0; i < len1; i++)
			if(smaller(i+1, pos))pos = i+1;
//		cout<<pos<<endl;
		for(int i = 0; i < pos; i++)
		  	printf("%c", s1[i]);
		printf("%s", s2);
		for(int i = pos; i < len1; i++)
		  	printf("%c", s1[i]);
		printf("\n");
	}

    return 0;
}
