#include "listRelasi.h"

void createListRelasi(listRelasi & L) {
  first(L) = NULL;
}

addressRelasi alokasiRelasi(addressMahasiswa P, addressMataKuliah C) {
  addressRelasi Q = new elmListRelasi;
  matakuliah(Q) = C;
  mahasiswa(Q) = P;
  next(Q) = NULL;
  return Q;
}

void insertFirst(listRelasi & L, addressRelasi P) {
  next(P) = first(L);
  first(L) = P;
}

void printInfo(listRelasi L) {
  addressRelasi P = first(L);

  cout << "====================================================================================================" << endl;
  cout << "\t\t\t    Data Mahasiswa dan Mata Kuliah yang Diambil" << endl;
  cout << "====================================================================================================" << endl;

  while (P != NULL) {
    cout << " " << info(mahasiswa(P)) << " mengambil Mata Kuliah " << info(matakuliah(P)) << endl;
    P = next(P);
  }
}

addressRelasi findElmParent(listRelasi L, addressMahasiswa P) {
  addressRelasi Q = first(L);
  while ((Q != NULL) && (mahasiswa(Q) != P)) {
    Q = next(Q);
  }
  return Q;
}

addressRelasi findElm(listRelasi L, addressMahasiswa P, addressMataKuliah C) {
  addressRelasi Q = first(L);
  while (Q != NULL) {
    if (mahasiswa(Q) == P && matakuliah(Q) == C) {
      return Q;
    }
    Q = next(Q);
  }
  return NULL;
}

addressRelasi findElmChild(listRelasi L, addressMataKuliah C) {
  addressRelasi Q = first(L);
  while (Q != NULL && matakuliah(Q) != C) {
    Q = next(Q);
  }
  return Q;
}

void delRelasiP(listRelasi & L, addressRelasi & P) {
  addressRelasi Prec;
  if (first(L) == NULL) {
    cout << "List Kosong" << endl;
  } else if (first(L) == P) {
    deleteFirst(L, P);
  } else if (next(P) == NULL) {
    deleteLast(L, P);
  } else {
    deleteAfter(L, Prec, P);
  }
}

void delRelasiC(listRelasi & L, addressRelasi & P) {
  addressRelasi Prec;
  if (first(L) == NULL) {
    cout << "List Kosong" << endl;
  } else if (first(L) == P) {
    deleteFirst(L, P);
  } else if (next(P) == NULL) {
    deleteLast(L, P);
  } else {
    deleteAfter(L, Prec, P);
  }
}

void deleteFirst(listRelasi & L, addressRelasi & P) {
  if (next(first(L)) == NULL) {
    P = first(L);
    first(L) = NULL;
  } else {
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
  }
}

void deleteLast(listRelasi & L, addressRelasi & P) {
  addressRelasi Q;
  P = first(L);
  while (next(P) != NULL) {
    Q = P;
    P = next(P);
  }
  if (first(L) == P) {
    first(L) = NULL;
  } else {
    next(Q) = NULL;
  }
}

void deleteAfter(listRelasi & L, addressRelasi Prec, addressRelasi & P) {
  P = next(Prec);
  if (next(P) == NULL) {
    next(Prec) = NULL;
  } else {
    next(Prec) = next(P);
    next(P) = NULL;
  }
}

int cariMax(listRelasi L, listMataKuliah P) {
  addressRelasi Q;
  addressMataKuliah C = first(P);
  int i;
  int maxi;
  maxi = 0;
  i = 0;
  while (C != NULL) {
    Q = first(L);
    i = 0;
    while (Q != NULL) {
      if (matakuliah(Q) == C) {
        i++;
      }
      Q = next(Q);
    }
    if (maxi < i) {
      maxi = i;
    }
    C = next(C);
  }
  return maxi;
}

void printMaxi(listRelasi L, listMataKuliah P) {
  addressMataKuliah C;
  addressMataKuliah A;
  addressRelasi Q;

  A = first(P);
  int i = 0;
  int X = 0;
  int maxi = cariMax(L, P);
  while ((A != NULL) && (X != 5)) {
    C = first(P);
    while (C != NULL) {
      Q = first(L);
      i = 0;
      while ((Q != NULL) && (X != 5)) {
        if (matakuliah(Q) == C) {
          i++;
        }
        Q = next(Q);
      }
      if (maxi == i) {
        cout << " Mata Kuliah " << info(C) << " diambil oleh " << maxi << " Mahasiswa" << endl;
        X++;
      }
      C = next(C);
    }
    A = next(A);
    maxi--;
  }
}
