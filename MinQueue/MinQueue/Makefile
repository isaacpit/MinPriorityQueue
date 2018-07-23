all: Main

Main: MinQueue.o DoublyLinkedList.o Main.o 
	g++ -std=c++11 MinQueue.o Main.o DoublyLinkedList.o -o Main

DoublyLinkedList.o: DoublyLinkedList.h DoublyLinkedList.cpp
	g++ -std=c++11 -c DoublyLinkedList.cpp 

MinQueue.o: MinQueue.h MinQueue.cpp
	g++ -std=c++11 -c MinQueue.cpp 

Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp

clean:
	rm *.o Main
