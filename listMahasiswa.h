#ifndef LISTMAHASISWA_H_INCLUDED
#define LISTMAHASISWA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

#define firstMahasiswa(L) (L).firstMahasiswa
#define prevMahasiswa(P) (P)->prevMahasiswa
#define infoMahasiswa(P) (P)->infoMahasiswa
#define nextMahasiswa(P) (P)->nextMahasiswa
#define mataKuliah(P) (P)->mataKuliah
#define keMahasiswa(P) (P)->keMahasiswa

using namespace std;

struct Mahasiswa{
    string nama;
    int nim;
    string kelas;
    string jurusan;
    string fakultas;
};

typedef struct elmListMahasiswa *;

struct elmListMahasiswa{
    prevMahasiswa;
    Mahasiswa infoMahasiswa;
    nextMahasiswa;
};

struct listMahasiswa{
    addressMahasiswa firstMahasiswa;
};

void createListMahasiswa(listMahasiswa &L);
alokasiMahasiswa(Mahasiswa x);
void dealokasiMahasiswa(&P);
void insertFirstMahasiswa(listMahasiswa &L, addressMahasiswa P);
void insertLastMahasiswa(listMahasiswa &L, addressMahasiswa P);
addressMahasiswa findElmMahasiswa(listMahasiswa L, string x);
void deleteFirstMahasiswa(listMahasiswa &L, addressMahasiswa &P);
void deleteLastMahasiswa(listMahasiswa &L, addressMahasiswa &P);
void printInfoMahasiswa(listMahasiswa L);
void insertAfterMahasiswa(addressMahasiswa Prec, addressMahasiswa P);
void deleteAfterMahasiswa(addressMahasiswa Prec, addressMahasiswa &P);
void editInfoMahasiswa(listMahasiswa L, addressMahasiswa &P);
addressMahasiswa inputMahasiswa();
void deleteSearchMahasiswa(listMahasiswa &LM, addressMahasiswa &P);
void dataMahasiswa(listMahasiswa &L);

#endif // LISTMAHASISWA_H_INCLUDED
