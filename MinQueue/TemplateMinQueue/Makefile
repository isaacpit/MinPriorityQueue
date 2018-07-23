all: TemplateMain

TemplateMain: TemplateMain.o
	g++ -std=c++11 -o TemplateMain TemplateMain.o

TemplateMain.o: TemplateMain.cpp TemplateMinQueue.h TemplateDoublyLinkedList.h
	g++ -std=c++11 -c TemplateMain.cpp 

clean:
	rm *.o TemplateMain
