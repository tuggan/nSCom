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

    std::mutex printLck;
    
    in.setPrintMutex(&printLck);
    out.setPrintMutex(&printLck);
    
    out.setReturnFunc(std::bind(returnCarrot, in));

    in.startInputWatch();
    std::thread test(testOutput, out);
    refresh();
    test.join();
    closeWindow();
    return 0;
}

void initiateWindow() {
    initscr();
    //cbreak();
    raw();
    noecho();
    //nonl();
    //curs_set(0);
    refresh();
}

void closeWindow() {
    endwin();
}


void testOutput(oWindow thing) {
    for(int i = 0; i < 10000; i++){
        thing.printf("%d\n", i);
        usleep(250);
    }
}

void returnCarrot(iWindow i) {
    i.returnCarrot();
}

void watchInput(iWindow i) {
    i.startInputWatch();
}



















