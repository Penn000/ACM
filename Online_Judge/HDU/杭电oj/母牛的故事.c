/*��һͷĸţ����ÿ�������һͷСĸţ��
ÿͷСĸţ�ӵ��ĸ���ͷ��ʼ��ÿ�����Ҳ��һͷСĸţ��
����ʵ���ڵ�n���ʱ�򣬹��ж���ͷĸţ��*/

/*�ݹ�˼�룬 �����ţΪȥ���ţ��������ǰ��ţ�� ����ǰ��ţ����һֻСţ */

    #include <stdio.h>
    #include <stdlib.h>

    int main(void)
    {
        int n;
        while(scanf("%d", &n) != EOF)
        {
            if(n == 0)
                continue;
            int i , num[56];
            num[0] = 1;
            num[1] = 2;
            num[2] = 3;
            for(i = 3; i < n; i++)
            {
                num[i] = num[i-1] +num[i-3];
            }

            printf("%d\n", num[n-1]);
        }
        return 0;
    }
