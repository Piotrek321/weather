# top-level rule to compile the whole program.
all: prog clean

# program is made of several source files.
prog: main.o WeatherOWM.o FileHandler.o
	g++ main.o WeatherOWM.o FileHandler.o -o prog -lcurl -l json -lboost_iostreams -lboost_system

# rule for file "main.o".inc/WeatherOWM.h
main.o: src/main.cpp 
	g++ -std=c++11 -g -Wall -c src/main.cpp 

# rule for file "WeatherOWM.o".
WeatherOWM.o: src/WeatherOWM.cpp
	g++ -std=c++11 -g -Wall -c src/WeatherOWM.cpp -o WeatherOWM.o

# rule for file "FileHandler.o"
FileHandler.o: src/FileHandler.cpp
	g++ -std=c++11 -g -Wall -c src/FileHandler.cpp -o FileHandler.o
# rule for cleaning files generated during compilations.
clean:
	/bin/rm -f main.o WeatherOWM.o
#g++ -std=c++11 src/main.cpp -o main.o -lcurl -l json -lboost_iostreams -lboost_system

