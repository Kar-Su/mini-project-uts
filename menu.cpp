#include <bits/stdc++.h>

/* 
Program ini hanya di optimalisasi dengan data struktur modern (C++ style) tidak bisa menggunakan array tradisional.
akan tetapi program ini sudah didesain agar developer bisa memanage dengan mudah jika ingin mengganti data struktur traditional (C style).
Desain program ini menggunakan Modular Programming dengan fungsi template Container.
*/

// Data struktur yang digunakan
using myArray = std::vector<int>;

// Deklarasi prototype
void dMenu();

template <typename Container> void InsertData(Container &data);

template <typename Container> void PrintData(Container &data);

namespace SortInsertion{
    template <typename Container> void Ascending(Container& data, const size_t& n);
    template <typename Container> void Descending(Container& data, const size_t& n);
    template <typename Container> void StartSort(Container& data);
}

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
      SortInsertion::StartSort<myArray>(arr);
      break;
    case '4':
      /* code */
    SepatahKata();
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

// Tampilan menu
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

// Memasukkan data
template <typename Container> void InsertData(Container &data) {
    // Mempermudah user untuk melihat data sebelum memasukkan data
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

// Menampilkan data
template <typename Container> void PrintData(Container &data) {
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

// Sorting Insertion bertipe Ascending
template <typename Container> void SortInsertion::Ascending(Container& data, const size_t& n){
    for (size_t i = 1; i < n; i++) {
        int tmp = data[i];
        size_t j = i;

        while (j > 0 and data[j - 1] > tmp) {
            data[j] = data[j - 1];

            j--;
        }
    data[j] = tmp;
    }
}

// Sorting Insertion bertipe Descending
template <typename Container> void SortInsertion::Descending(Container& data, const size_t& n){
    for (size_t i = 1; i < n; i++) {
        int tmp = data[i];
        size_t j = i;

        while (j > 0 and data[j - 1] < tmp) {
            data[j] = data[j - 1];

            j--;
        }
    data[j] = tmp;
    }
}

// Memulai program Sorting Insertion     
template <typename Container> void SortInsertion::StartSort(Container& data){
    system("clear");
    if(data.empty()){
        std::cout << "Data anda kosong!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        return;
    }
    char pl;
    const size_t n = data.size();

    do{
    system("clear");

    std::cout << 
    "Tipe Sorting\n" << 
    "1. Ascending Sort\n" <<
    "2. Descending Sort\n" << 
    "pilih (1/2): ";
    std::cin >> pl;
           
    switch(pl) {
        case '1':
            SortInsertion::Ascending(data, n);
            break;
        case '2':
            SortInsertion::Descending(data, n);
            break;
        default:
        system("clear");
            std::cout << "Input Salah!\n" <<
            "Silahkan ulangi kembali" << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            break;
        }
    } while(pl != '1' and pl != '2');
    system("clear");
    std::cout << "Sorting Berhasil!";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Saya masih pemula
void SepatahKata() {
  system("clear");
  std::cout << "Hello World " << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.get();
}
