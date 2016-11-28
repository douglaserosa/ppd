CFLAGS		= -Wall
PTHREADS	= -lpthread
MATH		= -lm
C11			= -std=c++11
APPS 		= pi-rand pi-uniform-distribution parallel-pi-rand parallel-pi-uniform-distribution

all: $(APPS)

pi-rand: pi-rand.c
	gcc $(CFLAGS) pi-rand.c -o pi-rand $(MATH)

parallel-pi-rand: parallel-pi-rand.c
	gcc $(CFLAGS) parallel-pi-rand.c -o parallel-pi-rand $(PTHREADS) $(MATH)

pi-uniform-distribution: pi-uniform-distribution.cpp
	g++ $(CFLAGS) pi-uniform-distribution.cpp -o pi-uniform-distribution $(MATH) $(C11)

parallel-pi-uniform-distribution: parallel-pi-uniform-distribution.cpp
	g++ $(CFLAGS) parallel-pi-uniform-distribution.cpp -o parallel-pi-uniform-distribution $(PTHREADS) $(MATH) $(C11)

clean:
	rm -f *.o $(APPS) 
