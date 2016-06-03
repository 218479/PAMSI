CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11


start: obj obj/main.o obj/Plansza.o 
	g++ -Wall -pedantic -std=c++11 -o start obj/main.o obj/Plansza.o 

obj:
	mkdir obj

obj/Plansza.o: src/Plansza.cpp inc/Plansza.hh  
	g++ -c ${CXXFLAGS} -o obj/Plansza.o src/Plansza.cpp

obj/main.o: src/main.cpp inc/Plansza.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp



clean:
	rm -f obj/*.o start
