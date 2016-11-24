/* -----------------
* Calcula a aproximação para Pi
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <math.h>
#include <random>

int NUM_THREADS = 1;
int N;

struct threadStruct {
    int threadNum;
    int m;
};

void* partRandom (void *params) {
    int                 i, from, until;
    double              x, y, z;
    struct threadStruct *args = (struct threadStruct *) params;
    std::random_device  rd;
    std::mt19937        gen(rd());
    std::uniform_int_distribution<int> dist(0, 999999);

    from = args->threadNum * ceil((double) N / NUM_THREADS) + 1;
    until = (args->threadNum  + 1) * ceil((double)N / NUM_THREADS);
    if (args->threadNum == NUM_THREADS - 1) {
        until = N;
    }

    for (i = from; i <= until; i++) {
        x = (double) dist(gen) / dist.max();
        y = (double) dist(gen) / dist.max();
        z = x * x + y * y;
        if (z <= 1) {
            args->m++;
        } 
    }

    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    int             i, m = 0;
    double          pi = 0.0;
    struct timeval  tvStart;
    struct timeval  tvEnd;
    double          temp;

    gettimeofday(&tvStart, NULL);

    if (argc != 3) {
        printf("Usage: easy-pi <num_threads> <num_iter>\n");
        exit(0);
    }

    NUM_THREADS = abs(atoi(argv[1]));
    N = abs(atoi(argv[2]));

    pthread_t           threads[NUM_THREADS];
    struct threadStruct threadParams[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        threadParams[i].threadNum = i;
        threadParams[i].m = 0;
        pthread_create(&threads[i], NULL, partRandom, (void *) &threadParams[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        m += threadParams[i].m;
    }

    pi = (double) m / N * 4;
    printf("Pi = %lf\n", pi);

    gettimeofday(&tvEnd, NULL);
    temp = ((tvEnd.tv_sec + ((double) tvEnd.tv_usec / 1000000)) -
        (tvStart.tv_sec + ((double) tvStart.tv_usec / 1000000)));
    printf("Time: %.4lf seconds.\n", temp);

    return 0;
}