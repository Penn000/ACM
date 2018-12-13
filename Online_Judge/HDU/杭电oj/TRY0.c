#include<stdio.h>

int main()
{
    int n,i,j,num,money,s,temp;
    int y[6]={100,50,10,5,2,1};
    while(scanf("%d",&n)!=EOF && n!=0)
    {
        num=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&money);
            for(j=0;j<6;j++)
            {
                s=money/y[j];temp=money%y[j]; num+=s;
                if(temp==0) break;
                money=temp;
            }
        }
        printf("%d\n",num);
    }
}
