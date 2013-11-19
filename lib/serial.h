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

#ifndef SERIAL_H
#define SERIAL_H

#include <termios.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

class serialIO {
private:
    char *serialPort;
    int serialFD;
    speed_t baud;
    char sep;
    void (*readCallBack)(char*);
    
public:
    serialIO();
    serialIO(char *p, int rate);
    int setSerialPort(char *p);
    int setBaud(int baud);
    int setSeparator(char c);
    int setReadCallback(void (*readCallBack)(char*));
    int openCon();
    int closeCon();
    char *readUntillSep();
    ~serialIO();
};






#endif













