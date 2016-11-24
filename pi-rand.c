/* -----------------
* Calcula a aproximação para Pi
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char** argv) {
    struct timeval  tvStart;
    struct timeval  tvEnd;
    double          temp;
    int             N, i, m = 0;
    double          x, y, z, pi = 0.0;

    gettimeofday(&tvStart, NULL);

    srand(time(NULL));

    if (argc != 2) {
        printf("Usage: easy-pi <num_iter>\n");
        exit(0);
    }

    N = abs(atoi(argv[1]));

    m = 0;
    for (i = 0; i < N; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1) {
            m++;
        } 
    }
    pi = (double) m / N * 4;
    printf("Pi = %lf\n", pi);

    gettimeofday(&tvEnd, NULL);
    temp = ((tvEnd.tv_sec + ((double) tvEnd.tv_usec / 1000000)) -
        (tvStart.tv_sec + ((double) tvStart.tv_usec / 1000000)));
    printf("Time: %.4lf seconds.\n", temp);

    return 0;
}