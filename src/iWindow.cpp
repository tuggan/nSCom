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
    this->ipw = NULL;
}

void iWindow::createWindow() {
    this->wptr = newwin(this->height, this->width, this->xStart, this->yStart);
    this->printf("# ");
}

WINDOW* iWindow::getW(){
    return this->wptr;
}

void iWindow::returnCarrot() {
    wmove(this->wptr, 0, this->inputBuffer.size()-2);
    wrefresh(this->wptr);
}

void iWindow::startInputWatch() {
    this->ipw = new std::thread(&iWindow::inputWatch, this);
}

void iWindow::inputWatch() {
    char c = 0;
    while(c != 27 && c != 3) { // 27 == esc
        c = getch();
        switch(c){
        case '\n':
            inputBuffer.clear();
            break;
        case 26: // C+z
            def_prog_mode();
            endwin();
            system("/bin/bash");
            reset_prog_mode();
            refresh();
            break;
        case 127: // Backspace
            if(this->inputBuffer.size() > 0)
                this->inputBuffer.pop_back();
            break;
        case 27:
            this->inputBuffer = "Waiting for other threads to finish... "
                "(^C+c to exit now, this might break your terminal)";
            break;
        default:
            if(std::isprint(c))
                inputBuffer += c;
            #ifdef DEBUG
            else {
                std::stringstream stream;
                int tmp = c;
                stream << tmp;
                inputBuffer.append(stream.str());
            }
            #endif
            break;
        }
        this->updateLine();
    }
    // @TODO#MAEK THIS BEAUTIFULL!!
    if(c == 3)
        exit(0);
}

void iWindow::updateLine() {
    if(this->mtx)
        this->mtx->lock();
    wmove(this->wptr, 0, 0);
    wclrtoeol(this->wptr);
    wrefresh(this->wptr);
    this->returnCarrot();
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
    if(this->ipw)
        this->ipw->join();
}




















