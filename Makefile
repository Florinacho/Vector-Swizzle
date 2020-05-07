CC=g++
CFLAGS=-O3
LFLAGS=-O3
CFILES=main.cpp
LFILES=main.o
OUTPUT=a.out

all: ${LFILES}
	${CC} ${LFLAGS} ${CFILES} -o ${OUTPUT} 

main.o: main.cpp
	${CC} ${CFLAGS} -c main.cpp -o main.o

clean:
	rm -rf ${LFILES}
	rm -rf ${OUTPUT} 
