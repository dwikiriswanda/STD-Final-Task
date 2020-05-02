#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include "listMahasiswa.h"
#include "listMataKuliah.h"

#include <iostream>
using namespace std;

#define first(L) L.first
#define mahasiswa(P) P->mahasiswa
#define matakuliah(P) P->matakuliah
#define next(P) P->next

typedef struct elmListRelasi *addressRelasi;

struct elmListRelasi{
    addressMahasiswa mahasiswa;
    addressMataKuliah matakuliah;
    addressRelasi next;
};

struct listRelasi{
    addressRelasi first;
};

void createListRelasi(listRelasi &L);
void insertFirst(listRelasi &L, addressRelasi P);
void deleteFirst(listRelasi &L, addressRelasi &P);
void deleteLast(listRelasi &L, addressRelasi &P);
void deleteAfter(listRelasi &L,addressRelasi Prec, addressRelasi &P);
void delRelasiP(listRelasi &L, addressRelasi &P);
void delRelasiC(listRelasi &L,addressRelasi &P);
int cariMax(listRelasi L,listMataKuliah P);
void printMaxi(listRelasi L,listMataKuliah P);
addressRelasi alokasiRelasi( addressMahasiswa P, addressMataKuliah C);
addressRelasi findElmParent(listRelasi L, addressMahasiswa P) ;
addressRelasi findElmChild(listRelasi L, addressMataKuliah C) ;
void printInfo(listRelasi L);

#endif // LISTRELASI_H_INCLUDED
