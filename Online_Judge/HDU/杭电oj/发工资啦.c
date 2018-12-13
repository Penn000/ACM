    #include <stdio.h>
    #include <stdlib.h>

    int statistics(int salary);

    int main(void)
    {
        int n;

        while(scanf("%d", &n) != EOF)
        {
            if(n == 0)
                continue;
            int *a, i, cnt = 0, sum = 0;
            a = (int *)malloc(n * sizeof(int));
            for(i = 0; i < n; i++)
                scanf("%d", &a[i]);

            for(i = 0; i < n; i++)
               cnt += statistics(a[i]);

            printf("%d\n", cnt);
        }

        return 0;
    }

    int statistics(int salary)
    {
        int cnt = 0, i, s, temp;
        int y[6] = {100, 50, 10, 5, 2, 1};

        for(i = 0; i < 6; i++)
        {
            s = salary / y[i];
            temp = salary % y[i];
            cnt += s;
            if(temp == 0)
                break;
            salary = temp;
        }

        return cnt;
    }
