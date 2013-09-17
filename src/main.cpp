/*   Copyright 2013 Dennis Vesterlund
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include "main.h"


int main(int argv, char *argc[]) {
    initiateWindow();
    //printw("Hello World");
    WINDOW *printHere;
    printHere = createOutput();    
    //wprintw(printHere, "Hello World!");
    mvwprintw(printHere, getmaxy(printHere)-2, 1, "Hello?\n");
    wprintw(printHere, "World?");
    wrefresh(printHere);
    getch();
    closeWindow();
    return 0;
}

void initiateWindow() {
    initscr();
    cbreak();
    noecho();
    refresh();
}

WINDOW *createOutput() {
    WINDOW *win;
    win = newwin(LINES-2,COLS,0,0);
    attron(COLOR_RED);
    box(win, 0, 0);
    attroff(COLOR_RED);
    wrefresh(win);
    return win;
}

void closeWindow() {
    endwin();
}


















