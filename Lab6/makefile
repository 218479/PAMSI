
all: prog

prog: obj/main.o obj/Test.o obj/IDrzewo_Czerwono_Czarne.o obj/Drzewo_Czerwono_Czarne.o obj/stoper.o

	g++ -Iinc -Wall -pedantic -o program obj/main.o obj/Test.o obj/IDrzewo_Czerwono_Czarne.o obj/Drzewo_Czerwono_Czarne.o obj/stoper.o


obj/main.o: src/main.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/main.o src/main.cpp

obj/Test.o: src/Test.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Test.o src/Test.cpp

obj/Drzewo_Czerwono_Czarne.o: src/Drzewo_Czerwono_Czarne.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/Drzewo_Czerwono_Czarne.o src/Drzewo_Czerwono_Czarne.cpp

obj/IDrzewo_Czerwono_Czarne.o: src/IDrzewo_Czerwono_Czarne.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/IDrzewo_Czerwono_Czarne.o src/IDrzewo_Czerwono_Czarne.cpp

obj/stoper.o: src/stoper.cpp
	g++ -c -Iinc -Wall -pedantic -o obj/stoper.o src/stoper.cpp










clean:
	rm -f obj/*.o
