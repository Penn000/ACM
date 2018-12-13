#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include <conio.h>
#define N 1000

int main(void)
{
    int x = 360, y = 160, driver = VGA, mode = VGAHI;
    int num = 20, i;
    int top, bottom;
    initgraph(&dirver, &mode, "");
    top = y - 30;
    bottom = y- 30;
    for(i = 0; i < num; i++)
    {
        ellipse(250, 250, 0, 360, top, bottom);
        top -= 5;
        bottom += 5;
    }

    getch();

    return 0;
}
