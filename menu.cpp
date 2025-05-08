#include <bits/stdc++.h>


using myArray = std::vector<int>;

void dMenu();

template <typename T> void InsertData(T &data);

template <typename T> void PrintData(T &data);

template <typename T> void SortingData(T &data);

void SepatahKata();


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

template <typename T> void InsertData(T &data) {
  PrintData<myArray>(data);

  // if (!data.empty()) {
  //   data.clear();
  // }
  std::string buff;
  size_t i = data.size();
  std::cout << std::endl << "Silahkan masukkan data (tekan enter tanpa mengisi data untuk mengakhiri)" << std::endl;

  do {
    std::cout << "Masukkan Data[" << i << "]: ";
    std::getline(std::cin, buff);

    if (buff.empty()) {
      return;
    }

    data.push_back(stoi(buff));
    i++;
  } while (1);
}

template <typename T> void PrintData(T &data) {
  system("clear");

  if(data.empty()) {
    std::cout << "Data anda kosong!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return;
  }

  std::cout << "Array: ";
  for (const auto &i : data) {
    std::cout << i << "  ";
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}

template <typename T> void SortingData(T &data) {
  system("clear");

  if(data.empty()){
    std::cout << "Data anda kosong, silahkan isi terlebih dahulu!" <<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return;
  }

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

void SepatahKata() {
  system("clear");
  std::cout << "Hello World " << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}
