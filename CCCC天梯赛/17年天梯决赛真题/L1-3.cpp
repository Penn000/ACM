#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100;

int S[N], E[N];

int main()
{
	int n;
	cin>>n;
	int id, hh, ss;
	char op;
	while(n--){
		memset(S, -1, sizeof(S));
		memset(E, -1, sizeof(E));

		int maxId = 0;
		int cnt = 0, avg = 0;
		while(scanf("%d %c %d:%d", &id, &op, &hh, &ss)){
			if(id == 0)break;
			maxId = max(maxId, id);
			if(op == 'S'){
				S[id] = hh*60+ss;
			}else if(op == 'E'){
				if(S[id]!=-1){
					E[id] = hh*60+ss;
					cnt++;
					avg += E[id]-S[id];
					S[id] = -1;
				}
			}
		}
		if(cnt == 0){printf("0 0\n");continue;}
		double tmp = avg*1.0/cnt;
		avg /= cnt;
		if(tmp > avg*1.0)avg++;
		printf("%d %d\n", cnt, avg);
	}

	return 0;
}
