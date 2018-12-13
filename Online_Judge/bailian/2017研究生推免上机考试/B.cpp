#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main()
{
	while(cin>>str){
		int x = 0, cnt = 1;
		for(int i = 0; i < 11; i++){
			if(i == 1 || i== 5)continue;
			x += (str[i]-'0')*cnt;
			cnt++;
		}
		x %= 11;
		if(x == str[12]-'0'){
			cout<<"Right"<<endl;
		}else{
			str[12] = x+'0';
			cout<<str<<endl;
		}
	}

	return 0;
}
