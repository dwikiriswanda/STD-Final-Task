#ifndef LISTMAHASISWA_H_INCLUDED
#define LISTMAHASISWA_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next

typedef string infotypeMahasiswa;
typedef struct elmListMahasiswa *addressMahasiswa;

struct elmListMahasiswa {
    infotypeMahasiswa info;
    addressMahasiswa next;
};

struct listMahasiswa {
    addressMahasiswa first;
};

void createListMahasiswa(listMahasiswa &L);
void insertFirst(listMahasiswa &L, addressMahasiswa P);
void deleteFirst(listMahasiswa &L, addressMahasiswa &P);
void deleteLast(listMahasiswa &L, addressMahasiswa &P);
void deleteAfter(listMahasiswa &L, addressMahasiswa Prec, addressMahasiswa &P);
void del(listMahasiswa &L,addressMahasiswa &P);
addressMahasiswa alokasiMahasiswa(infotypeMahasiswa x);
addressMahasiswa findElm(listMahasiswa L, infotypeMahasiswa x);
void printInfo(listMahasiswa L);

#endif // LISTMAHASISWA_H_INCLUDED
