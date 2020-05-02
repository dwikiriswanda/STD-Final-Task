#ifndef LISTMATAKULIAH_H_INCLUDED
#define LISTMATAKULIAH_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info
#define next(P) P->next

typedef string infotypeMataKuliah;
typedef struct elmListMataKuliah *addressMataKuliah;

struct elmListMataKuliah{
    addressMataKuliah prev;
    infotypeMataKuliah info;
    addressMataKuliah next;
};

struct listMataKuliah{
    addressMataKuliah first;
    addressMataKuliah last;
};

void createListMataKuliah(listMataKuliah &L);
void insertLast(listMataKuliah &L, addressMataKuliah P);
void deleteFirst(listMataKuliah &L, addressMataKuliah &P);
void deleteLast(listMataKuliah &L, addressMataKuliah &P);
void deleteAfter(listMataKuliah &L,addressMataKuliah Prec, addressMataKuliah &P);
void del(listMataKuliah &L,addressMataKuliah &P);
addressMataKuliah alokasiMataKuliah(infotypeMataKuliah x);
addressMataKuliah findElm(listMataKuliah L, infotypeMataKuliah x);
void printInfo(listMataKuliah L);

#endif // LISTMATAKULIAH_H_INCLUDED
