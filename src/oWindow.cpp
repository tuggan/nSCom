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

#include "oWindow.h"

oWindow::oWindow(int height, int width, int xStart,
                 int yStart, bool border) {
    this->height = height;
    this->width = width;
    this->xStart = xStart;
    this->yStart = yStart;
    this->border = border;
}

void oWindow::createWindow() {
    this->bptr = newwin(this->height, this->width, this->xStart, this->yStart);
    this->wptr = newwin(this->height-2, this->width-2,
                        this->xStart+1, this->yStart+1);
    if(this->border)
        box(this->bptr, 0, 0);
    scrollok(this->wptr, true);
    wrefresh(this->bptr);
    wrefresh(this->wptr);
}

void oWindow::printf(const char *p, ...) {
    std::va_list fmtargs;
    char buffer[1024];

    va_start(fmtargs,p);
    vsnprintf(buffer,sizeof(buffer)-1,p,fmtargs);
    va_end(fmtargs);

    wprintw(this->wptr, buffer);
    wrefresh(this->wptr);
}

void oWindow::delLine() {
    move(0, 0);
    wdeleteln(this->wptr);
    wrefresh(this->wptr);
}

oWindow::~oWindow() {

}
















