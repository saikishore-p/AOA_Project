all: MarsBase

MarsBase: main.o Task1.o Task2.o Task3A.o Task3B.o Task4.o Task5.o Task6.o
	g++ main.o Task1.o Task2.o Task3A.o Task3B.o Task4.o Task5.o Task6.o -o MarsBase

main.o: main.cpp
	g++ -c main.cpp

Task1.o: Task1.cpp header.h
	g++ -c Task1.cpp

Task2.o: Task2.cpp header.h
	g++ -c Task2.cpp

Task3A.o: Task3A.cpp header.h
	g++ -c Task3A.cpp

Task3B.o: Task3B.cpp header.h
	g++ -c Task3B.cpp

Task4.o: Task4.cpp header.h
	g++ -c Task4.cpp

Task5.o: Task5.cpp header.h
	g++ -c Task5.cpp

Task6.o: Task6.cpp header.h
	g++ -c Task6.cpp

clean:
	rm -rf *.o MarsBase