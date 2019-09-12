#include <stdio.h>
#include "PDCurses/curses.h"

#include "func.h"

int main(int avgc, char ** avgv)
{
    // WINDOW * ponit;
    // init(); // 调用配置方法

    while(1)
    {
        mvprintw(LINES - 1, COLS - 20, "Producted by Jack");
    }
    return 0;
}

// 初始化配置

