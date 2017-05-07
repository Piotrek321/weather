# top-level rule to compile the whole program.
all: prog

# program is made of several source files.
prog: main.o file1.o
	g++ main.o file1.o -o prog -lcurl -l json -lboost_iostreams -lboost_system

# rule for file "main.o".
main.o: src/main.cpp inc/WeatherOWM.h
	g++ -std=c++11 -g -Wall -c src/main.cpp -lcurl -l json -lboost_iostreams -lboost_system

# rule for file "file1.o".
file1.o: src/WeatherOWM.cpp inc/WeatherOWM.h
	g++ -std=c++11 -g -Wall -c src/WeatherOWM.cpp -o file1.o -lcurl -l json -lboost_iostreams -lboost_system

# rule for cleaning files generated during compilations.
#clean:
#        /bin/rm -f prog main.o file1.o file2.o
#g++ -std=c++11 src/main.cpp -o main.o -lcurl -l json -lboost_iostreams -lboost_system

