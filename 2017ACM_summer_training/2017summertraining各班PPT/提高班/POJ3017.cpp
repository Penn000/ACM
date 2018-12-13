/*************************************************************************
    > File Name: POJ3017.cpp
    > Author: wmg_1007
    > Mail: wmg_1007@163.com
    > Created Time: 六  8/ 5 19:19:18 2017
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
using namespace std;

typedef long long LL;
const int maxn = 100005;

int n;
LL m;
int A[maxn];
LL f[maxn];

deque <pair<int, int> > Q;
multiset <LL> S;

void init(void)
{
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	while (!Q.empty())
		Q.pop_front();
	S.clear();
}

int main() 
{
	while (scanf("%d %lld", &n, &m) != EOF) {
		init();

		// definition
		LL sum = 0;
		int pos = 0;
		bool succ = true;

		// perform the algorithm
		for (int i = 0; i < n; i++) {
			// update sum & pos
			sum += A[i];
			while (sum > m)
				sum -= A[pos++];

			// no answer, break loop & print -1
			if (pos > i) {
				succ = false;
				break;
			}

			// tail 
			while (!Q.empty() && A[i] > Q.back().second) {
				pair<int, int> Qback = Q.back();
				Q.pop_back();
				if (!Q.empty())
					S.erase(S.find(f[Q.back().first] + Qback.second));
			}

			// push back i
			if (!Q.empty()) {
				S.insert(f[Q.back().first] + A[i]);
			}
			Q.push_back(make_pair(i, A[i]));

			// head
			while (!Q.empty() && Q.front().first < pos) {
				pair<int, int> Qfront = Q.front();
				Q.pop_front();
				if (!Q.empty())
					S.erase(S.find(f[Qfront.first] + Q.front().second));
			}

			// calculate f[i]
			f[i] = (pos == 0 ? 0 : f[pos - 1]) + Q.front().second;
			if (!S.empty())
				f[i] = min(f[i], *(S.begin()));
		}
		if (succ)
			cout << f[n - 1] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
