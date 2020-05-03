#include "listMahasiswa.h"

void createListMahasiswa(listMahasiswa & L) {
  first(L) = NULL;
}

addressMahasiswa alokasiMahasiswa(infotypeMahasiswa x) {
  addressMahasiswa P;
  P = new elmListMahasiswa;
  info(P) = x;
  next(P) = NULL;
  return P;
}

void insertFirst(listMahasiswa & L, addressMahasiswa P) {
  addressMahasiswa Q;
  if (first(L) == NULL) {
    first(L) = P;
    next(P) = P;
  } else {
    Q = first(L);
    while (next(Q) != first(L)) {
      Q = next(Q);
    }
    next(P) = first(L);
    next(Q) = P;
    first(L) = P;
  }
}

void deleteLast(listMahasiswa & L, addressMahasiswa & P) {
  addressMahasiswa Q;
  if (first(L) == NULL) {
    cout << " List kosong" << endl;
  } else if (next(first(L)) == first(L)) {
    first(L) = NULL;
  } else {
    P = first(L);
    do {
      P = next(P);
    } while (next(P) != first(L));
    Q = first(L);
    do {
      Q = next(Q);
    } while (next(Q) != P);
    next(Q) = first(L);
    next(P) = NULL;
  }
}

void del(listMahasiswa & L, addressMahasiswa & P) {
  addressMahasiswa q;
  addressMahasiswa Prec;
  if (first(L) == P) {
    deleteFirst(L, P);
  } else if (next(P) == first(L)) {
    deleteLast(L, P);
  } else {
    deleteAfter(L, Prec, P);
  }
}

void deleteAfter(listMahasiswa & L, addressMahasiswa Prec, addressMahasiswa & P) {
  Prec = first(L);
  do {
    Prec = next(Prec);
  } while (next(Prec) != P);
  next(Prec) = next(P);
  next(P) = NULL;
}
void printInfo(listMahasiswa L) {
  addressMahasiswa P = first(L);
  cout << "====================================================================================================" << endl;
  cout << "\t\t\t\t\t  Data Mahasiswa" << endl;
  cout << "====================================================================================================" << endl;

  if (first(L) != NULL) {
    do {

      cout << " - " << info(P) << endl;
      P = next(P);
    } while ((P) != first(L));
  } else {
    cout << " Maaf, Belum Ada Mahasiswa yang Terdaftar" << endl;
    cout << " Silakan Input Terlebih Dahulu!" << endl;
  }
}

addressMahasiswa findElm(listMahasiswa L, infotypeMahasiswa x) {
  addressMahasiswa P = first(L);
  if (P == NULL) {
    return NULL;
  } else if (info(P) == x) {
    return P;
  } else {
    P = next(P);
    while ((P != first(L)) && (info(P) != x)) {
      P = next(P);
    }
    if (P == first(L)) {
      return NULL;
    } else {
      return P;
    }
  }
}

void deleteFirst(listMahasiswa & L, addressMahasiswa & P) {
  addressMahasiswa Q;
  if (first(L) == NULL) {
    cout << " List kosong" << endl;
  } else if (next(first(L)) == first(L)) {
    first(L) = NULL;
  } else {
    P = first(L);
    Q = first(L);
    do {
      Q = next(Q);
    } while (next(Q) != first(L));
    first(L) = next(P);
    next(Q) = next(P);
    next(P) = NULL;
  }
}
