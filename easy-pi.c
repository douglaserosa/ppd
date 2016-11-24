/* -----------------
* Calcula a aproximação para Pi
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
  int N, i, m = 0;
  double x, y, z, pi = 0.0;

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

  return 0;
}