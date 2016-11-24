/* -----------------
* Calcula a aproximação para Pi
*/
#include <iostream>
#include <stdlib.h>
#include <random>

int main(int argc, char** argv) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0, 999999);

  int N, i, m = 0;
  double x, y, z, pi = 0.0;

  if (argc != 2) {
    std::cout << "Usage: m_pi <num_iter>\n";
    exit(0);
  }

  N = abs(atoi(argv[1]));
  

  m = 0;
  for (i = 0; i < N; i++) {
    x = (double) dist(gen) / dist.max();
    y = (double) dist(gen) / dist.max();
    z = x * x + y * y;
    if (z <= 1) {
      m++;
    }
  }
  pi = (double) m / N * 4;
  std::cout << "Pi = " << pi << std::endl;

  return 0;
}