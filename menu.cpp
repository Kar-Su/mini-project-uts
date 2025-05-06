#include <cstdlib>
#include <bits/stdc++.h>
#include <limits>

using namespace std;



void dMenu() {
  system("clear");
  cout << "Aplikasi Sorting Insertion" << "\n";
  cout << "1. Memasukkan Data" << "\n";
  cout << "2. Menampilkan Data" << "\n";
  cout << "3. Sorting" << "\n";
  cout << "4. Kata-Kata" << "\n";
  cout << "5. Exit" << "\n";
  cout << "Masukan angka :";
}

void SepatahKata() {
  system("clear");
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Hello World " << endl;
  cin.get();
}

template<typename T>
void InsertData(T& data){
  system("clear");
  size_t n;
  
  cout << "Masukkan banyak data yang mau dimasukkan";
  cin >> n;

  for(size_t i = 0; i < n - 1; i++){
    cout << "Masukkan Data[" << i+1 <<"]: ";
    cin >> data[i];
  }
}


int main() {
  vector<int> arr;
  char pl;
  do {
    dMenu();
    cin >> pl;
    switch (pl) {
    case '1':
      /* code */
      system("clear");
      InsertData(arr);
      break;
    case '2':
      /* code */
      break;
    case '3':
      /* code */
      break;
    case '4':
      SepatahKata();
      /* code */
      break;
    case '5':
      /* code */
      break;

    default:
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      system("clear");
      cout << "Pilihan Tidak Tersedia";
      cin.get();
      break;
    }

  } while (pl != '5');
  return 0;
}
