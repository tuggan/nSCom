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

#include "iWindow.h"

iWindow::iWindow(int height, int width, int xStart, int yStart) {
    this->height = height;
    this->width = width;
    this->xStart = xStart;
    this->yStart = yStart;
    this->mtx = NULL;
}

void iWindow::createWindow() {
    this->wptr = newwin(this->height, this->width, this->xStart, this->yStart);
}

WINDOW* iWindow::getW(){
    return this->wptr;
}

void iWindow::returnCarrot() {
    wmove(this->wptr, 0, 0);
    wrefresh(this->wptr);
}

void iWindow::startInputWatch() {
    char c;
    while(c != 'q') {
        c = getch();
        if(c != '\n') {
            inputBuffer += c;
            this->updateLine();
        } else {
            inputBuffer.clear();
            this->updateLine();
        }
    }
}

void iWindow::updateLine() {
    if(this->mtx)
        this->mtx->lock();
    wmove(this->wptr, 0, 0);
    wclrtoeol(this->wptr);
//wdeleteln(this->wptr);
//wclear(this->wptr);
    wrefresh(this->wptr);
    if(this->mtx)
        this->mtx->unlock();
    int offset = 0;
    if((offset = (this->inputBuffer.size() - this->width + 4)) < 0 )
        offset = 0;
    this->printf("# %s", this->inputBuffer.substr(offset).c_str());
    //waddstr(this->wptr, this->inputBuffer.substr(offset).c_str());
}

void iWindow::printf(const char *p, ...) {
    std::va_list fmtargs;
    char buffer[1024];

    va_start(fmtargs,p);
    vsnprintf(buffer,sizeof(buffer)-1,p,fmtargs);
    va_end(fmtargs);

    //wprintw(this->wptr, buffer);
    if(this->mtx)
        this->mtx->lock();
    mvwprintw(this->wptr, 0, 0, buffer);
    wrefresh(this->wptr);
    if(this->mtx)
        this->mtx->unlock();
}

void iWindow::setPrintMutex(std::mutex *m) {
    this->mtx = m;
}

iWindow::~iWindow() {
    
}




















