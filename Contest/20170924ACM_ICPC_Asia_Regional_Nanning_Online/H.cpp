#include <iostream>
#include <iomanip>
#include <set>
#include <string>

using namespace std;

set<string> se;
string str;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tot = 0, cnt = 0;
	while(cin >> str){
		if(str == "END"){
			cout << "Hit ratio = " << setiosflags(ios::fixed) << setprecision(2) << 100.0 * cnt / tot << "%" << endl;
			break;
		}
		tot++;
		str.pop_back();
		if(se.find(str) == se.end()){
			cout << "MISS" << endl;
			se.insert(str);
		}else{
			cout << "HIT" << endl;
			cnt++;
		}
	}
	return 0;
}
