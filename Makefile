all: myprog

myprog: myprog.o
	g++ -lm -o myprog myprog.o

myprog.o: myprog.cpp
	g++ -O -c myprog.cpp

clean:
	rm -f myprog *.o
