#include <cstdio>
#include <iostream>

using namespace std;


void dMenu(){
system("clear");
cout<<"Aplikasi Tampilan Menu"<<"\n";       
cout<<"1. Menu Pertama"<<"\n";            
cout<<"2. Menu Kedua"<<"\n";            
cout<<"3. Menu Ketiga"<<"\n";           
cout<<"4. Menu Keempat"<<"\n";            
cout<<"5. Exit"<<"\n";           
cout<<"Masukan angka :";        

}

void mPertama(string pesan){
system("clear");
cout<<"hallo saya menu "<<pesan;
}


int main() {
char pl;
do
{
    dMenu();
  cin >> pl;
  switch (pl)
  {
   case '1':
    /* code */
    mPertama("pertama");
    break;
   case '2':
    mPertama("ke- dua");
    /* code */ 
    break;  
   case '3':
    mPertama("ke- tiga");
    /* code */
    break;  
   case '4':
    mPertama("ke- empat");
    /* code */
    break;  
  case '5':
    /* code */
    break;
  
  default:
    system("clear");
    cout<<"Pilihan Tidak Tersedia";
    cin.get();
    break;
  }


} while (pl!='5');
  return 0;
}
