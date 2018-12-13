//2017-09-03
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int N = 100000;

char wenhao[10] = {'a', 'b', 'c', 'd', 'e'};
int position[5], tot, ans, len;
map<string, int> mp, book;
map<string, int>::iterator iter;
char parten[N];
string str;

void dfs(int step) {
    if (step == len) {
        parten[tot] = '\0';
        string tmp(parten);
        iter = mp.find(tmp);
        if (iter != mp.end() && book.find(tmp) == book.end()){
            ans += iter->second;
            book.insert(make_pair(tmp, 1));
        }
        return;
    }
    if (str[step] == '?') {
        for (int i = 0; i < 5; i++) {
            parten[tot++] = wenhao[i];
            dfs(step + 1);
            tot--;
        }
        dfs(step + 1);
    } else {
        parten[tot++] = str[step];
        dfs(step + 1);
        tot--;
    }
}
int main() {
    //freopen("inputG.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        while (n--) {
            cin >> str;
            mp[str]++;
        }
        while (m--) {
            book.clear();
            tot = 0;
            ans = 0;
            cin >> str;
            len = str.length();
            dfs(0);
            cout << ans << endl;
        }
        mp.clear();
        book.clear();
    }

    return 0;
}
