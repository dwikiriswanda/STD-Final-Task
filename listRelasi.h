#ifndef LISTRELASI_H_INCLUDED
#define LISTRELASI_H_INCLUDED

#include "listMahasiswa.h"
#include "listMataKuliah.h"

#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iostream>

#define firstRelasi(L) (L).firstRelasi
#define prevRelasi(P) (P)->prevRelasi
#define nextRelasi(P) (P)->nextRelasi

using namespace std;

typedef struct elmListRelasi *addressRelasi;

struct elmListRelasi{
    addressRelasi prevRelasi;
    addressMahasiswa keMahasiswa;
    addressMataKuliah keMataKuliah;
    addressRelasi nextRelasi;
};

struct ListRelasi{
    addressRelasi firstRelasi;
};

void createListRelasi(listRelasi &L);
addressRelasi alokasiRelasi();
void dealokasiRelasi(addressRelasi &P);
void insertFirstRelasi(listRelasi &L, addressRelasi P);
void insertLastRelasi(listRelasi &L, addressRelasi P);
addressRelasi findRelasi(listRelasi L, string x, string y);
void deleteFirst(listRelasi &L, addressRelasi &P);
void deleteLast(listRelasi &L, addressRelasi &P);
void printRelasi(listRelasi L);
void insertAfterRelasi(addressRelasi Prec, addressRelasi P);
void deleteAfterRelasi(addressRelasi Prec, addressRelasi &P);
void menu(listMahasiswa LM, listMataKuliah LMK, listRelasi LR);
void inputRelasi(listMahasiswa LM, listMataKuliah LMK, listRelasi &LR);
void deleteSearchRelasi(listRelasi &L, addressRelasi &P);
void deleteMahasiswa(listRelasi &LR, listMahasiswa &LM, addressMahasiswa &PM);
void deleteMataKuliah(listRelasi &LR, listMataKuliah &LMK, addressMataKuliah &PMK);
void searchMahasiswa(listMahasiswa LM, listRelasi LR, addressMahasiswa P);
void searchMataKuliah(listMataKuliah LMK, listRelasi LR, addressMataKuliah PMK);
void dataRelasi(listRelasi &L, listMahasiswa LM, listMataKuliah LMK);
void deleteRelasi(listRelasi &L, addressRelasi &P);

#endif // LISTRELASI_H_INCLUDED
