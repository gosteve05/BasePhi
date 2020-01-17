CC = g++
CFLAGS = -Wall --std=c++11
OBJECTS = Phi.o BigInt.o

Phi: $(OBJECTS) #OBJECTS refers to this
	$(CC) $(CFLAGS) -o Phi $(OBJECTS) -lsfml-graphics -lsfml-window -lsfml-system

Phi.o: Phi.cpp BigInt.h BigInt.cpp #needs space after colon
	$(CC) $(CFLAGS) -c Phi.cpp -o Phi.o

clean:
	rm Phi $(OBJECTS)
#NEW STUFF BELOW
#file1 changed to Phi. Phi.h changed to Phi.cpp.
#file2 changed to BigInt.
#"g++ -c -g -std=c++11" changed to "$(CC) $(CFLAGS)"
#-pthread deleted after those
#Phi.o: main.cpp Phi.cpp BigInt.cpp
#$(CC) $(CFLAGS) -pthread Phi.cpp main.cpp
#
#BigInt.o: main.cpp BigInt.h BigInt.cpp
#$(CC) $(CFLAGS) -pthread BigInt.cpp main.cpp
#
#main.o: main.cpp
#$(CC) $(CFLAGS) -pthread main.cpp
#
#Output: main.o Phi.o BigInt.o Phi.cpp BigInt.h
#g++ -g -std=c++11 -pthread main.o Phi.o BigInt.o -o Output
#
#clean:
#rm *.o Output