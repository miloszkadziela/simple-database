all: testmap 

testmap: testmap.o Database.o Employee.o
	g++ -g $^ -o $@

testmap.o: testmap.cpp 
	g++ -g -c -Wall -std=c++11 -pedantic $< -o $@

Database.o: Database.cpp Database.h
	g++ -g -c -Wall -std=c++11 -pedantic $< -o $@
	
Employee.o: Employee.cpp Employee.h
	g++ -g -c -Wall -std=c++11 -pedantic $< -o $@

.PHONY: clean

clean:
	-rm testmap.o Database.o Employee.o testmap