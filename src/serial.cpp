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

#include "serial.h"

serialIO::serialIO() {
    this->serialPort = NULL;
    this->baud = 0;
    this->sep = '\n';
}

serialIO::serialIO(char *p, int rate) {
    this->serialPort = p;
    this->setBaud(rate);
    this->sep = '\n';
}

int serialIO::setBaud(int baud) {
    switch(baud) {
    case 4800: this->baud=B4800; break;
    case 9600: this->baud=B9600; break;
#ifdef B14400
    case 14400: this->baud=B14400; break;
#endif
    case 19200: this->baud=B19200; break;
#ifdef B28800
    case 28800: this->baud=B28800; break;
#endif
    case 38400: this->baud=B38400; break;
    case 57600: this->baud=B57600; break;
    case 115200: this->baud=B115200; break;
    default: return -1;
    }
    return 0;
}




















