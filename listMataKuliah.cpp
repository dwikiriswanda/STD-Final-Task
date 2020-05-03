#include "listMataKuliah.h"

void createListMataKuliah(listMataKuliah & L) {
  first(L) = NULL;
  last(L) = NULL;
}

addressMataKuliah alokasiMataKuliah(infotypeMataKuliah x) {
  addressMataKuliah P = new elmListMataKuliah;
  info(P) = x;
  next(P) = NULL;
  prev(P) = NULL;
  return P;
}

void insertLast(listMataKuliah & L, addressMataKuliah P) {
  addressMataKuliah q;
  if (first(L) == NULL) {
    first(L) = P;
  } else {
    q = first(L);
    while (next(q) != last(L)) {
      q = next(q);
    }
    next(q) = P;
    prev(P) = q;
  }
}

void printInfo(listMataKuliah L) {
  addressMataKuliah P = first(L);
  cout << "====================================================================================================" << endl;
  cout << "\t\t\t\t\t Data Mata Kuliah" << endl;
  cout << "====================================================================================================" << endl;

  if (first(L) != NULL) {
    do {

      cout << " - " << info(P) << endl;
      P = next(P);
    } while (P != NULL);
  } else {
    cout << " Maaf, Belum Ada Mata Kuliah yang Terdaftar" << endl;
    cout << " Silakan Input Terlebih Dahulu!" << endl;
  }

}

addressMataKuliah findElm(listMataKuliah L, infotypeMataKuliah x) {
  addressMataKuliah P = first(L);
  while ((P != NULL) && (info(P) != x)) {
    P = next(P);

  }
  return P;
}

void deleteFirst(listMataKuliah & L, addressMataKuliah & P) {
  if (first(L) == NULL) {
    cout << " List kosong" << endl;
  } else if (next(first(L)) == NULL) {
    P = first(L);
    first(L) = NULL;
  } else {
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
    prev(first(L)) == NULL;
  }
}

void deleteLast(listMataKuliah & L, addressMataKuliah & P) {
  if (first(L) == NULL) {
    cout << " List kosong" << endl;
  } else if (first(L) == last(L)) {
    P = first(L);
    first(L) = NULL;
    last(L) = NULL;
  } else {
    P = last(L);
    last(L) = prev(last(L));
    prev(P) = NULL;
    next(last(L)) = NULL;
  }
}

void deleteAfter(listMataKuliah & L, addressMataKuliah Prec, addressMataKuliah & P) {
  if (first(L) == NULL) {
    cout << " List kosong" << endl;
  } else if (next(Prec) == NULL) {
    cout << " Tidak ada data yang dihapus" << endl;
  } else if (next(next(Prec)) == NULL) {
    P = last(L);
    last(L) = Prec;
    prev(P) = NULL;
    next(Prec) = NULL;
  } else {
    P = next(Prec);
    prev(next(P)) = Prec;
    next(Prec) = next(P);
    next(P) = NULL;
    prev(P) = NULL;
  }
}

void del(listMataKuliah & L, addressMataKuliah & P) {
  addressMataKuliah q;
  addressMataKuliah Prec;
  if (first(L) == P) {
    deleteFirst(L, P);
  } else if (next(P) == first(L)) {
    deleteLast(L, P);
  } else {
    deleteAfter(L, Prec, P);
  }
}
