#   Copyright 2013 Dennis Vesterlund
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

CXX=g++
CFLAGS=-c -Wall
SRCDIR=src/
OBJDIR=obj/
INSTALLDIR=install/
PROGNAME=nSCom

all: createdirs $(PROGNAME)

debug: CFLAGS += -DDEBUG -g
debug: all

$(PROGNAME): $(SRCDIR)main.cpp #a_functions.o
	$(CXX) $(SRCDIR)main.cpp -o $@ 

#a_functions.o: $(SRCDIR)a_functions.c
#	$(CC) $(CFLAGS) $(SRCDIR)a_functions.c -o $(OBJDIR)$@

createdirs:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(PROGNAME)

install:
	cp $(PROGNAME) $(INSTALLDIR)
.PHONY: install

uninstall:
	rm $(INSTALLDIR)$(PROGNAME)






