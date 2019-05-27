/****************************************
 * AUTHOR:  Maxime Desmet Vanden Stock  *
 * DATE:    2019-05-26                  *
 * FILE:    ncurses.cpp                 *
 ****************************************/

#include <ncurses.h>
#include <string.h>

using namespace std;

int width, height;

// Setup the screen and assigns width and
// height with the size of the screen.
void setup()
{
    initscr();
    if (has_colors() == false)
    {
        endwin();
        printf("Color not supported");
    }
    start_color();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, height, width);
    refresh();
}

// Changes colors similarly to processing
void color(int fg, int bg)
{
    init_pair(1, fg, bg);
    attron(COLOR_PAIR(1));
}

// Draws text similarly to processing
void text(const char str[], int x, int y)
{
    move(y, x);
    printw("%s", str);
}

// Same as text() but centered
void ctext(const char str[], int x, int y)
{
    move(y, (x-strlen(str))/2);
    printw("%s", str);
}

// Draws a single character
void point(char c=' ', int x=0, int y=0)
{
    move(y, x);
    printw("%s", c);
}

// Draws an horizontal line
void horline(char c = ' ', int x=0, int y=0, int l=0)
{
    for (int i = 0; i < l; ++i)
    {
        move(y, x+i);
        printw("%s", c);
    }
}

int main(int argc, char *argv[])
{
    setup();
    color(5, 4);
    horline(' ', 5, 3, 10);
    color(1, 7);
    ctext("Agrizha", 10, 10);
    refresh();
    getch();
    endwin();

    return 0;
}
