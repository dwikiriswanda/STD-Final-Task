#ifndef LISTMATAKULIAH_H_INCLUDED
#define LISTMATAKULIAH_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>

#define firstMataKuliah(L) (L).firstMataKuliah
#define prevMataKuliah(P) (P)->prevMataKuliah
#define infoMataKuliah(P) (P)->infoMataKuliah
#define nextMataKuliah(P) (P)->nextMataKuliah
#define keMataKuliah(P) (P)->keMataKuliah

using namespace std;

struct MataKuliah{
    string namaMataKuliah;
    string tingkat;
    int sks;
};

typedef struct elmListMataKuliah *addressMataKuliah;

struct elmListMataKuliah{
    addressMataKuliah prevMataKuliah;
    MataKuliah infoMataKuliah;
    addressMataKuliah nextMataKuliah;
};

struct listMataKuliah{
    addressMataKuliah firstMataKuliah;
};

void createListMataKuliah(listMataKuliah &L);
addressMataKuliah alokasiMataKuliah(MataKuliah x);
void dealokasiMataKuliah(addressMataKuliah &P);
void insertFirstMataKuliah(listMataKuliah &L, addressMataKuliah P);
void insertLastMataKuliah(listMataKuliah &L, addressMataKuliah P);
addressMataKuliah findElmMataKuliah(listMataKuliah L, string x);
void deleteFirstMataKuliah(listMataKuliah &L, addressMataKuliah &P);
void deleteLastMataKuliah(listMataKuliah &L, addressMataKuliah &P);
void printInfoMataKuliah(listMataKuliah L);
void insertAfterMataKuliah(addressMataKuliah Prec, addressMataKuliah P);
void deleteAfterMataKuliah(addressMataKuliah Prec, addressMataKuliah &P);
addressMataKuliah inputMataKuliah();
void editInfoMataKuliah(listMataKuliah L, addressMataKuliah &P);
void dataMataKuliah(listMataKuliah &L);
void deleteSearchMataKuliah(listMataKuliah &L, addressMataKuliah &P);

#endif // LISTMATAKULIAH_H_INCLUDED
