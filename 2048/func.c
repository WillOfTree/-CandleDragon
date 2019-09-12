#include "func.h"

// void draw_point()
// {

// }

void init() 
{
    initscr();
    start_color(); // 设置颜色
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    curs_set(FALSE);
    noecho(); // 不显示
    keypad(stdscr,TRUE); //设可控按键

    // return 1;
}