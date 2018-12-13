//2017-08-11
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int n;
multiset<int> ms;
vector< pair<int, int> > line, ans;

void init()
{
    ms.clear();
    line.clear();
    ans.clear();
}

int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    while(scanf("%d", &n)!=EOF)
    {
        init();
        int l, r, h;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &h, &l, &r);
            line.push_back(make_pair(l, h));
            line.push_back(make_pair(r, -h));
        }
        sort(line.begin(), line.end());
        vector< pair<int, int> >::const_iterator it, iter;
        it = line.begin();
        int height = 0;
        ms.insert(height);
        while(it != line.end()){
            iter = it;
            do{
                if(iter->second > 0)
                    ms.insert(iter->second);
                else
                    ms.erase(ms.find(-iter->second));
                iter++;
            }while(iter != line.end() && iter->first == it->first);
            if(*ms.rbegin() != height){
                ans.push_back(make_pair(it->first, height));
                ans.push_back(make_pair(it->first, height = *ms.rbegin()));
            }
            it = iter;
        }
		printf("%d\n", (int)ans.size());
        for(it = ans.begin(); it != ans.end(); it++){
            printf("%d %d\n", it->first, it->second);
        }
    }
}
