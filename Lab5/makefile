
all: prog

prog: obj/main.o obj/ILista.o obj/ITablica_asocjacyjna.o obj/ITablica_haszujaca.o obj/Lista.o obj/stoper.o obj/Tablica_haszujaca.o obj/Test.o
	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/ILista.o obj/ITablica_asocjacyjna.o obj/ITablica_haszujaca.o obj/Lista.o obj/stoper.o obj/Tablica_haszujaca.o obj/Test.o


obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp

obj/ILista.o: src/ILista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/ILista.o src/ILista.cpp

obj/ITablica_asocjacyjna.o: src/ITablica_asocjacyjna.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/ITablica_asocjacyjna.o src/ITablica_asocjacyjna.cpp

obj/ITablica_haszujaca.o: src/ITablica_haszujaca.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/ITablica_haszujaca.o src/ITablica_haszujaca.cpp

obj/Lista.o: src/Lista.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Lista.o src/Lista.cpp 

obj/stoper.o: src/stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/stoper.o src/stoper.cpp 

obj/Tablica_haszujaca.o: src/Tablica_haszujaca.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Tablica_haszujaca.o src/Tablica_haszujaca.cpp

obj/Test.o: src/Test.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Test.o src/Test.cpp











clean:
	rm -f obj/*.o
