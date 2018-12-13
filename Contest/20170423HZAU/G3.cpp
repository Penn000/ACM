#include <bits/stdc++.h>

using namespace std;

const int Max=1e5+10;
int que[Max];

int main()
{
	int n;
    while(scanf("%d", &n)!=EOF)
    {
        int x,top=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x>=que[top]||top==0)
            {
                que[++top]=x;
            }
            else
            {
                int l=1,r=top,mid,ans;
                ans=0;
                while(l<=r)
                {
                    mid=l+(r-l)/2;
                    if(que[mid]<x) l=mid+1;
                    else r=mid-1,ans=mid;
                }
                que[ans]=x;
            }
        }
        cout<<top<<endl;
    }
    return 0;
}
