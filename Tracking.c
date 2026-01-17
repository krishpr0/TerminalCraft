#include <ncurses.h>

#define TITLE_Y 3

int main(void)
{
    initscr();

    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        return 1;
    }

    start_color();
    use_default_colors();
    init_pair(1, COLOR_CYAN, -1);
    init_pair(2, COLOR_WHITE, COLOR_BLUE);

    WINDOW *win = newwin(LINES, COLS, 0, 0);
    keypad(win, TRUE);
    box(win, 0, 0);

    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 2, 4, "Budeget Tracker  version 1.0");
    wattroff(win, COLOR_PAIR(1));

    mvwprintw(win, TITLE_Y + 3, (COLS - 30) / 2, "1. Add Expense");
    mvwprintw(win, TITLE_Y + 4, (COLS - 30) / 2, "2. View Expenses");
    mvwprintw(win, TITLE_Y + 5, (COLS - 30) / 2, "3. Generate Report");
    mvwprintw(win, TITLE_Y + 6, (COLS - 30) / 2, "4. Exit");

    wresfresh(win);
    getch();

    delwin(win);
    endwin();
    return 0;
}