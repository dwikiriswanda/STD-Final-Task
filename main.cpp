#include "menu.h"

using namespace std;

int main() {

  listMahasiswa LP;
  listMataKuliah LC;
  listRelasi LR;
  addressMataKuliah C;
  addressMahasiswa P;
  addressRelasi R;

  createListMahasiswa(LP);
  createListMataKuliah(LC);
  createListRelasi(LR);

  menu();

  return 0;
}
