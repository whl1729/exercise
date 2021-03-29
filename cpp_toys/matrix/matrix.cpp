#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> vec_int_2d;

void generate_matrix(int size, vec_int_2d& matrix) {
  for (int i = 0; i < size; i++) {
    std::vector<int> vec;
    for (int j = 0; j < size; j++) {
      vec.push_back(rand() % 10000);
    }
    matrix.push_back(vec);
  }
}

void init_matrix(int size, vec_int_2d& matrix) {
  for (int i = 0; i < size; i++) {
    matrix.push_back(std::vector<int>(size, 0));
  }
}

void matrix_multiply(const vec_int_2d& a, const vec_int_2d& b, vec_int_2d& c) {
  int size = a.size();
  for (int i = 0; i < size; i++) {
    for (int k = 0; k < size; k++) {
      for (int j = 0; j < size; j++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

int main(int argc, char *argv[]) {
  using std::chrono::duration_cast;
  using std::chrono::seconds;

  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  int size = std::atoi(argv[1]);
  std::cout << "RAND_MAX = " << RAND_MAX << std::endl;

  vec_int_2d a, b, c;

  std::cout <<"generate two matrixs" << std::endl;

  generate_matrix(size, a);
  generate_matrix(size, b);
  init_matrix(size, c);

  std::cout << "start " << size << " * " << size << " matrix multiplication" << std::endl;
  const auto start = std::chrono::system_clock::now();
  matrix_multiply(a, b, c);
  const auto end = std::chrono::system_clock::now();
  const auto elapsed = duration_cast<seconds>(end - start);

  std::cout << size << " * " << size << " matrix multiplication costs "
            << elapsed.count() << " seconds." << std::endl;

  return 0;
}
