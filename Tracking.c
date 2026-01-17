#include <ncurses.h>

int main(void)
{
    initscr();

    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    start_color();
    use_default_colors();

    init_pair(1, COLOR_RED, -1);

    WINDOW *win = newwin(LINES, COLS, 0, 0);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 2, 4, "Budeget Tracker  version 1.0");
    wattroff(win, COLOR_PAIR(1));

    wresfresh(win);
    getch();

    delwin(win);
    endwin();
    return 0;
}