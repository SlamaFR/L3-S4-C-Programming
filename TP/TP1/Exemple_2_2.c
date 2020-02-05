#include <ncurses.h>
#include <unistd.h>

#define DELAI 20000

int main() {
    int x, y;

    initscr();

    x = 0;
    y = 0;
    while (1) {
        clear();

        mvaddch(0, 0, '*');
        mvaddch(0, COLS - 1, '*');
        mvaddch(LINES - 1, 0, '*');
        mvaddch(LINES - 1, COLS - 1, '*');

        mvaddch(y, x, 'o');
        refresh();

        usleep(DELAI);
        x = (x + 1) % COLS;
        y = (y + 1) % LINES;
    }
    endwin();
    return 0;
}