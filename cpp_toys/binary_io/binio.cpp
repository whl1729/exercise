#include <fstream>
#include <iostream>
#include <vector>

const float pi = 3.1415926;

void write_binary_file() {
  std::ofstream out_file("./bin/float.bin", std::ios::binary);
  std::vector<float> buffer;
  for (int i = 1; i < 9; i++) {
    buffer.push_back(pi * i);
  }

  out_file.write(reinterpret_cast<char*>(&buffer[0]), buffer.size() * sizeof(buffer[0]));

  out_file.close();
}

void read_binary_file() {
  std::ifstream in_file("./bin/float.bin", std::ios::binary | std::ios::ate);
  std::streamsize file_size = in_file.tellg();
  std::cout << "file_size=" << file_size << std::endl;
  in_file.seekg(0, std::ios::beg);

  std::vector<float> buffer(file_size/sizeof(float));
  if (!in_file.read(reinterpret_cast<char*>(&buffer[0]), file_size)) {
    std::cout << "in_file.read error!" << std::endl;
    return;
  }

  for (float elem: buffer) {
    std::cout << elem << ' ';
  }

  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  write_binary_file();

  std::cout << "write_binary_file ends." << std::endl;

  read_binary_file();

  std::cout << "read_binary_file ends." << std::endl;

  return 0;
}
