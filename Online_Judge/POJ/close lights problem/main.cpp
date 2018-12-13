#include <iostream>
#include <cstdio>
using namespace std;

bool guess();
void enumerate();
int puzzle[6][8], press[6][8];

int main()
{
    int cases, i, r, c;
    scanf("%d", &cases);
    for ( r=0; r<6; r++ )
        press[r][0] = press[r][7] = 0;
    for ( c=1; r<7; r++ )
        press[0][c] = 0;
    for (i=0; i<cases; i++)
    {
        for(r=1; r<6; r++)
            for(c=1; c<7; c++)
                scanf("%d", &puzzle[r][c]);
        enumerate ();
        printf("PUZZLE #%d\n",  i+1);
        for(r=1; r<6; r++)
        {
            for(c=1; c<7; c++)
                printf("%d ", press[r][c]);
            printf("\n");
        }
    }


    return 0;
}

bool guess()
{
    int c, r;
    for(r = 1; r < 5; r++)
        for(c = 1; c < 7; c++)
            press[r+1][c] = (puzzle[r][c]+press[r][c]+
                             press[r-1][c]+ press[r][c-1]+press[r][c+1]) %2;

    for(c=1; c<7; c++)
        if ((press[5][c-1] + press[5][c] + press[5][c+1] + press[4][c]) %2 != puzzle[5][c] )
            return(false);
    return(true);
}

void enumerate()
{
    int c;
    bool success;
    for ( c=1; c<7; c++)
        press[1][c] = 0;
    while(guess()==false)
    {
        press[1][1]++;
        c = 1;
        while (press[1][c] > 1)
        {
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }
    return;
}

