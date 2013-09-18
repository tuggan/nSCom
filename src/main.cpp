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
    oWindow out = oWindow(LINES-2, COLS, 0, 0);
    iWindow in = iWindow(1, COLS, LINES-1, 0);
    out.createWindow();
    in.createWindow();

    out.setReturn(in.getW());
    wprintw(in.getW(), "HelloWorld!");
    wrefresh(in.getW());

    std::thread test(testOutput, out);
    refresh();
    getch();
    test.join();
    closeWindow();
    return 0;
}

void initiateWindow() {
    initscr();
    cbreak();
    noecho();
    refresh();
}

void closeWindow() {
    endwin();
}


void testOutput(oWindow thing) {
    for(int i = 0; i < 2000; i++){
        thing.printf("%d\n", i);
        usleep(250);
    }
}



















