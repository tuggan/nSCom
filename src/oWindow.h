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

#ifndef OWINDOW_H
#define OWINDOW_H

#include <ncurses.h>
#include <cstdarg>

class oWindow {
private:
    WINDOW *bptr;
WINDOW *wptr;
WINDOW *rptr;
    bool border;
    int height;
    int width;
    int xStart;
    int yStart;

public:
    oWindow(int height, int width, int xStart, int yStart, bool border = true);
    void createWindow();
void printf(const char *p, ...);
void setReturn(WINDOW* w);
    void delLine();
    ~oWindow();
};

#endif

















