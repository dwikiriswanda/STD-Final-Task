#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>

#include<stdlib.h>

using namespace std;

#include "listMataKuliah.h"

#include "listMahasiswa.h"

#include "listRelasi.h"

string mahasiswa;
string matakuliah;
listMahasiswa LP;
listMataKuliah LC;
listRelasi LR;
addressMataKuliah C;
addressMahasiswa P;
addressRelasi R;
int pilih;
char yesno;

void tambahmahasiswa() {
  void menu();
  cout << " Masukkan Nama Mahasiswa: ";
  cin >> mahasiswa;
  addressMahasiswa d;
  d = findElm(LP, mahasiswa);
  if (d == NULL) {
    P = alokasiMahasiswa(mahasiswa);
    insertFirst(LP, P);
  } else {
    cout << endl;
    cout << " Mahasiswa Sudah Terdaftar" << endl;
    tambahmahasiswa();
  }
  cout << endl;
  cout << " Tambahkan Mahasiswa Lagi? (y / n): ";
  cin >> yesno;
  if ((yesno == 'Y') || (yesno == 'y')) {
    tambahmahasiswa();
  } else if ((yesno == 'N') || yesno == 'n') {
    system("cls");
    menu();
  } else {
    cout << " Maaf, Inputan Salah" << endl;
    cout << endl;
    tambahmahasiswa();
  }
}

void tambahmatakuliah() {
  void menu();
  cout << " Masukkan Nama Mata Kuliah: ";
  cin >> matakuliah;
  addressMataKuliah d;
  d = findElm(LC, matakuliah);
  if (d == NULL) {
    C = alokasiMataKuliah(matakuliah);
    insertLast(LC, C);
  } else {
    cout << endl;
    cout << " Mata Kuliah Sudah Terdaftar" << endl;
    tambahmatakuliah();
  }
  cout << endl;
  cout << " Tambahkan Mata Kuliah Lagi? (y / n): ";
  cin >> yesno;
  if ((yesno == 'Y') || (yesno == 'y')) {
    tambahmatakuliah();
  } else if ((yesno == 'N') || yesno == 'n') {
    system("cls");
    menu();
  } else {
    cout << " Maaf, Inputan Salah" << endl;
    cout << endl;

    tambahmatakuliah();
  }
}

void lihatmahasiswa() {

  printInfo(LP);

}

void lihatmatakuliah() {

  printInfo(LC);

}

void hapusdatamahasiswa() {
  void menu();
  cout << endl;
  cout << " Masukkan Nama Mahasiswa: ";
  cin >> mahasiswa;
  addressMahasiswa d;
  d = findElm(LP, mahasiswa);
  if (d != NULL) {
    P = findElm(LP, mahasiswa);
    R = findElmParent(LR, P);
  } else {
    cout << endl;
    cout << " Mahasiswa Tidak Terdaftar" << endl;
    hapusdatamahasiswa();
  }
  while (R != NULL) {
    delRelasiP(LR, R);
    R = findElmParent(LR, P);
  }
  del(LP, P);
  system("cls");
  menu();
}

void hapusdatamatakuliah() {
  void menu();
  cout << endl;
  cout << " Masukkan Nama Mata Kuliah: ";
  cin >> matakuliah;
  addressMataKuliah d;
  d = findElm(LC, matakuliah);
  if (d != NULL) {
    C = findElm(LC, matakuliah);
    R = findElmChild(LR, C);
  } else {
    cout << endl;
    cout << " Mata Kuliah Tidak Terdaftar" << endl;
    hapusdatamatakuliah();
  }

  while (R != NULL) {
    delRelasiC(LR, R);
    R = findElmChild(LR, C);
  }
  del(LC, C);
  system("cls");
  menu();
}

void mahasiswadanmatakuliah() {

  void menu();
  cout << " Masukkan Nama Mahasiswa: ";
  cin >> mahasiswa;
  P = findElm(LP, mahasiswa);
  cout << " Masukkan Nama Mata Kuliah: ";
  cin >> matakuliah;
  C = findElm(LC, matakuliah);
  R = alokasiRelasi(P, C);
  insertFirst(LR, R);
  cout << endl;
  cout << " Relasikan Data Lagi? (y / n): ";
  cin >> yesno;
  if ((yesno == 'Y') || (yesno == 'y')) {
    mahasiswadanmatakuliah();
  } else if ((yesno == 'N') || yesno == 'n') {
    system("cls");
    menu();
  } else {
    cout << "Maaf, Inputan Salah" << endl;
    cout << endl;
    mahasiswadanmatakuliah();
  }
}

void datamahasiswadanmatakuliah() {
  void menu();

  printInfo(LR);
  cout << endl;
  system("pause");
  system("cls");
  menu();

}

void datamahasiswamatakuliahtertentu() {
  void menu();
  cout << " Nama Mata Kuliah: ";
  cin >> matakuliah;
  R = first(LR);
  cout << "====================================================================================================" << endl;
  cout << "\t\t\t    Data Mahasiswa yang Mengambil Mata Kuliah " << matakuliah << endl;
  cout << "====================================================================================================" << endl;

  while ((R != NULL)) {
    if ((info(matakuliah(R)) == matakuliah)) {
      cout << " - " << info(mahasiswa(R)) << endl;
    }
    R = next(R);
  }
  cout << endl;
  system("pause");
  menu();
}

void datamatakuliahmahasiswatertentu() {
  void menu();
  cout << " Nama Mahasiswa: ";
  cin >> mahasiswa;
  R = first(LR);
  cout << "====================================================================================================" << endl;
  cout << "\t\t\t    Data Mata Kuliah yang Diambil Mahasiswa " << mahasiswa << endl;
  cout << "====================================================================================================" << endl;

  while (R != NULL) {
    if (info(mahasiswa(R)) == mahasiswa) {
      cout << " - " << info(matakuliah(R)) << endl;
    }
    R = next(R);
  }
  cout << endl;
  system("pause");
  menu();

}

void matakuliahpalingbanyak() {
  // Menampilkan 5 data matakuliah yang paling banyak
  void menu();
  cout << "====================================================================================================" << endl;
  cout << "\t\t\t\t     Jumlah Peminat Mata Kuliah" << endl;
  cout << "====================================================================================================" << endl;

  printMaxi(LR, LC);
  cout << endl;
  system("pause");
  system("cls");
  menu();
}

void menu() {

  void tambahmahasiswa();
  void tambahmatakuliah();
  void inputmahasiswa();
  void inputmatakuliah();
  void lihatmahasiswa();
  void lihatmatakuliah();
  void hapusdatamahasiswa();
  void mahasiswadanmatakuliah();
  void datamahasiswadanmatakuliah();
  void datamahasiswamatakuliahtertentu();
  void datamatakuliahmahasiswatertentu();
  void matakuliahpalingbanyak();

  cout << "\t       _____      _                       _     _____        _                    " << endl;
  cout << "\t      / ____|    | |                     | |   |  __ \\      | |                   " << endl;
  cout << "\t     | (___   ___| | __ _ _ __ ___   __ _| |_  | |  | | __ _| |_ __ _ _ __   __ _ " << endl;
  cout << "\t      \\___ \\ / _ \\ |/ _` | '_ ` _ \\ / _` | __| | |  | |/ _` | __/ _` | '_ \\ / _` |" << endl;
  cout << "\t      ____) |  __/ | (_| | | | | | | (_| | |_  | |__| | (_| | || (_| | | | | (_| |" << endl;
  cout << "\t     |_____/ \\___|_|\\__,_|_| |_| |_|\\__,_|\\__| |_____/ \\__,_|\\__\\__,_|_| |_|\\__, |" << endl;
  cout << "\t                                                                             __/ |" << endl;
  cout << "\t                                                                            |___/ " << endl;

  cout << "====================================================================================================" << endl;
  cout << "\t\t\t\t Aplikasi Data Registrasi Mahasiswa" << endl;
  cout << "====================================================================================================" << endl;

  cout << "  -- INPUT -- " << endl;
  cout << " 1.  Penambahan Data Mahasiswa" << endl;
  cout << " 2.  Penambahan Data Mata Kuliah" << endl;
  cout << " 3.  Penentuan Relasi Antara Mahasiswa dan Mata Kuliah" << endl;
  cout << endl;
  cout << "  -- DELETE -- " << endl;
  cout << " 4.  Menghapus Data Mata Kuliah Tertentu" << endl;
  cout << " 5.  Menghapus Data Mahasiswa Tertentu" << endl;
  cout << endl;
  cout << "  -- VIEW -- " << endl;
  cout << " 6.  Menampilkan Data Keseluruhan Mahasiswa Beserta Data Mata Kuliah yang Diambilnya" << endl;
  cout << " 7.  Menampilkan Data Mahasiswa yang Mengambil Matakuliah Tertentu" << endl;
  cout << " 8.  Menampilkan Data Mata Kuliah yang Diambil oleh Mahasiswa Tertentu" << endl;
  cout << " 9.  Menampilkan Data Mata Kuliah yang Memiliki Jumlah Peminat Paling Banyak dan juga Paling Sedikit" << endl;
  cout << endl;
  cout << " 0.  Exit" << endl;
  cout << endl;
  cout << " Masukkan Pilihan : ";
  cin >> pilih;

  switch (pilih) {
  case 1:
    tambahmahasiswa();
    menu();
    break;
  case 2:
    tambahmatakuliah();
    menu();
    break;
  case 3:
    lihatmahasiswa();
    cout << endl;
    lihatmatakuliah();
    cout << endl;
    mahasiswadanmatakuliah();
    menu();
    break;
  case 4:
    lihatmatakuliah();
    cout << endl;
    hapusdatamatakuliah();
    menu();
    break;
  case 5:
    lihatmahasiswa();
    cout << endl;
    hapusdatamahasiswa();
    menu();
    break;
  case 6:
    datamahasiswadanmatakuliah();
    menu();
    break;
  case 7:
    lihatmatakuliah();
    cout << endl;
    datamahasiswamatakuliahtertentu();
    menu();
    break;
  case 8:
    lihatmahasiswa();
    cout << endl;
    datamatakuliahmahasiswatertentu();
    menu();
    break;
  case 9:
    matakuliahpalingbanyak();
    cout << endl;
    menu();
    break;
  case 0:

    system("cls");

    cout << "====================================================================================================" << endl;
    cout << "\t\t\t\t     Semangat Ya Belajarnya! :)" << endl;
    cout << "====================================================================================================" << endl;

    cout << "\t\t       _______        _                 _             _ _     " << endl;
    cout << "\t\t      |__   __|      (_)               | |           (_) |    " << endl;
    cout << "\t\t         | | ___ _ __ _ _ __ ___   __ _| | ____ _ ___ _| |__  " << endl;
    cout << "\t\t         | |/ _ \\ '__| | '_ ` _ \\ / _` | |/ / _` / __| | '_ \\ " << endl;
    cout << "\t\t         | |  __/ |  | | | | | | | (_| |   < (_| \\__ \\ | | | |" << endl;
    cout << "\t\t         |_|\\___|_|  |_|_| |_| |_|\\__,_|_|\\_\\__,_|___/_|_| |_|" << endl;

    break;

  default:
    cout << "Maaf, Inputan Salah" << endl;
    cout << endl;
    system("pause");
    system("cls");
    menu();
  }

}

# endif // MENU_H_INCLUDED
