#include <bits/stdc++.h>
// #include <iostream>
// #include <limits>

void dMenu() {
  system("clear");
  std::cout << "Aplikasi Sorting Insertion" << "\n";
  std::cout << "1. Memasukkan Data" << "\n";
  std::cout << "2. Menampilkan Data" << "\n";
  std::cout << "3. Sorting" << "\n";
  std::cout << "4. Kata-Kata" << "\n";
  std::cout << "5. Exit" << "\n";
  std::cout << "Masukan angka: ";
}

void SepatahKata() {
  system("clear");
  std::cout << "Hello World " << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

template <typename T> void InsertData(T &data) {
  system("clear");
  if (!data.empty()) {
    data.clear();
  }
  size_t n;

  std::cout << "Masukkan banyak data yang mau dimasukkan: ";
  std::cin >> n;

  for (size_t i = 0; i < n; i++) {
    std::cout << "Masukkan Data[" << i << "]: ";
    int buff;
    std::cin >> buff;
    data.push_back(buff);
  }
}

template <typename T> void PrintData(T &data) {
  system("clear");
  std::cout << "Array: ";
  for (const auto &i : data) {

    std::cout << i << " ";
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

template <typename T> void SortingData(T &data) {
  system("clear");

  size_t n = data.size();
  for (size_t i = 1; i < n; i++) {
    int tmp = data[i];
    size_t j = i;

    while (j > 0 and data[j - 1] > tmp) {
      data[j] = data[j - 1];

      j--;
    }
    data[j] = tmp;
  }

  std::cout << "Sorting data berhasil!" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

using myArray = std::vector<int>;

int main() {
  myArray arr;
  char pl;
  do {
    dMenu();
    std::cin >> pl;
    switch (pl) {
    case '1':
      /* code */
      InsertData<myArray>(arr);
      break;
    case '2':
      /* code */
      PrintData<myArray>(arr);
      break;
    case '3':
      /* code */
      SortingData<myArray>(arr);
      break;
    case '4':
      SepatahKata();
      /* code */
      break;
    case '5':
      /* code */
      break;

    default:
      system("clear");
      std::cout << "Pilihan Tidak Tersedia";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin.get();
      break;
    }

  } while (pl != '5');

  return 0;
}
