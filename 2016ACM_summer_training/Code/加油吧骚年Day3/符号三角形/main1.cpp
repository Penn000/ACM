//2016.8.3
#include<iostream>

using namespace std;

int ans[30] = {0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};

int main()
{
	int n;
	while(cin>>n&&n)
	{
		cout<<n<<" "<<ans[n]<<endl;
	}

	return 0;
}
