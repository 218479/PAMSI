
all: prog

prog: obj/main.o obj/Graf.o obj/IGraf.o obj/IKolejka.o obj/ILista.o obj/Kolejka.o obj/Lista.o obj/stoper.o 
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Graf.o obj/IGraf.o obj/IKolejka.o obj/ILista.o obj/Kolejka.o obj/Lista.o obj/stoper.o 


obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp

obj/IKolejka.o: src/IKolejka.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/IKolejka.o src/IKolejka.cpp

obj/ILista.o: src/ILista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/ILista.o src/ILista.cpp

obj/Kolejka.o: src/Kolejka.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Kolejka.o src/Kolejka.cpp

obj/Lista.o: src/Lista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Lista.o src/Lista.cpp

obj/stoper.o: src/stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/stoper.o src/stoper.cpp

obj/Graf.o: src/Graf.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Graf.o src/Graf.cpp

obj/IGraf.o: src/IGraf.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/IGraf.o src/IGraf.cpp





clean:
	rm -f obj/*.o
