# use g++ with C++11 support
# no support for gdb, I can always add -g in CXXFLAGS later
CXXFLAGS?=-Wall -pedantic -O0 -std=c++11

all: ecws

ecws: ecws.o
	g++ -o ecws $(CXXFLAGS) ecws.o

ecws.o: ecws.cpp
	g++ -c $(CXXFLAGS) ecws.cpp

clean:
	rm -f *.exe *.o
