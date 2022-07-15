#include "keluarga.h"

void createNew_List(List &ListMhs){
  first(ListMhs) = NULL;
}

void newElement_Orangtua(orangtua info, adrOrangtua &S){
  S = new elmOrangtua;
  info(S) = info;
  next(S) = NULL;
  nextMhs(S) = NULL;
}

void newElement_Anak(infotypeMhs info, adrMhs &J){
  J = new elmMhs;
  info(J) = info;
  next(J) = NULL;
}

void insertNew_Anak(List &ListOrtu, adrOrangtua S, adrMhs J){
  if (nextMhs(S) == NULL){
    nextMhs(S) = J;
  }else{
    adrMhs P = nextMhs(S);
    while(next(P) != NULL){
      P = next(P);
    }
    next(P) = J;
  }
}

void insertLast_Orangtua(List &ListOrtu, adrOrangtua S){
  if (first(ListOrtu) == NULL){
    first(ListOrtu) = S;
  }else{
    adrOrangtua P = first(ListOrtu);
    while(next(P) != NULL){
      P = next(P);
    }
    next(P) = S;
  }
}

void deleteFirst_Anak(List &ListOrtu, adrOrangtua &S, adrMhs &J){
  adrMhs P = nextMhs(S);
  J = nextMhs(S);
  if (next(P) == NULL){
    nextMhs(S) = NULL;
  }else{
    nextMhs(S) = next(P);
    next(P) = NULL;
  }
}

void deleteAfter_Mahasiswa(List &ListMhs, adrMhs Prec, adrMhs J){
  cout << "======================" << endl;
  cout << "Nama : " << info(next(Prec)).nama << endl;

  cout << "++BERHASIL DI HAPUS++" << endl;
  cout << "======================" << endl;
  J = next(Prec);
  next(Prec) = next(J);
  next(J) = NULL;
}

adrMhs searchBefore_Anak(List ListOrtu, string ortu){
  adrOrangtua R = first(ListOrtu);
  while(R != NULL){
    if (info(R).ortu == ortu){
      adrMhs P = next(nextMhs(R));
    }
    R = next(R);
  }
}

void deleteFirst_Orangtua(List &ListOrtu){
  adrOrangtua P;
  if (first(ListOrtu) == NULL){
    cout << "List Nama Orang Tua Tidak Ada" << endl;
  }else{
    P = first(ListOrtu);
    first(ListOrtu) = next(P);
    next(P) = NULL;
  }
}

void deleteAfter_Orangtua(adrOrangtua Prec, adrOrangtua P){
  P = next(Prec);
  next(Prec) = next(P);
  next(P) = NULL;
}

adrOrangtua searchBefore_Orangtua(List ListOrtu, string ortu){
  adrOrangtua P = next(first(ListOrtu));
  adrOrangtua Q = first(ListOrtu);
  while(next(P) != NULL){
    if (info(P).ortu == ortu){
      return Q;
    }
    Q = P;
    P = next(P);
  }
  return Q;
}

void showData_Orangtua(List ListOrtu){
  int i = 1;
  if (first(ListOrtu) == NULL){
    cout << "Orang Tua Tidak Ada" << endl;
  }else{
    adrOrangtua P = first(ListOrtu);
    while(P != NULL){
      adrMhs Q = nextMhs(P);
      cout << i << ". " << info(P).ortu << endl;
      i = i + 1;
      P = next(P);
    }
  }
  cout << endl;
}

void showData_Anak(List ListOrtu){
  string input;
  int i = 1;
  int j = 1;
  if (first(ListOrtu) == NULL){
    cout << "Nama Anak Tidak Ada" << endl;
  }else{
    adrOrangtua P = first(ListOrtu);
    cout << "List Nama Orang tua :" << endl;
    while (P != NULL){
      cout<< i << ". " << info(P).ortu << endl;
      i = i + 1;
      P = next(P);
    }
    cout << "Masukkan Nama Orang tua Yang Ingin Di Tampilkan : ";
    cin >> input;
    P = first(ListOrtu);
    while(P != NULL){
      adrMhs Q = nextMhs(P);
      if (info(P).ortu == input){
        while(Q != NULL){
          cout << j << ". " << "Nama : " << info(Q).nama << endl;
          cout << endl;
          Q = next(Q);
          j++;
        }
      }
      P = next(P);
    }
  }
}

adrOrangtua search_Orangtua(List ListMhs, string ortu){
  adrOrangtua P = first(ListMhs);
  while(P != NULL){
    if (info(P).ortu == ortu){
      return P;
    }
    P = next(P);
  }
  return NULL;
}

void find_Orangtua(List ListOrtu, string ortu){
  adrOrangtua P = first(ListOrtu);
  if (first(ListOrtu) == NULL){
    cout << "Nama Orang Tua Tidak Ada" << endl;
  }else if(P != NULL){
    while(P != NULL){
      if (info(P).ortu == ortu){
        cout << "Nama Orang Tua " << info(P).ortu << " Di Temukan" << endl;
        adrMhs Q = nextMhs(P);
        int j = 0;
        while(Q != NULL){
          cout << endl;
          Q = next(Q);
          j++;
        }
        cout << "Dengan Jumlah Anak :  " << j << endl;
      }
      adrMhs Q = nextMhs(P);
      P = next(P);
    }
  }
  cout << endl;
}

void cari_Anak(List ListOrtu){
  adrOrangtua P = first(ListOrtu);
  if (first(ListOrtu) == NULL){
    cout << "Nama Anak Tidak Ada" << endl;
  }else if(P != NULL){
    P = first(ListOrtu);
    while(P != NULL){
      adrMhs Q = nextMhs(P);
        while(Q != NULL){
      P = next(P);
    }
  }
  }
}

int selectMenu(){
    cout << "TUGAS BESAR STRUKTUR DATA : " << endl;
    cout << "Oleh : " << endl;
    cout << "Muhammad Sulthan Fahrein : 1302200121 " << endl;
    cout << "Jahfal Mudrik Ramadhan : 1302204034 " << endl;
    cout << "\n" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\t\tData Keluarga (Orang Tua Dan Anak)" << endl;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "1. Tambahkan Nama Orang Tua" << endl;
    cout << "2. Tambahkan Nama Anak" << endl;
    cout << "3. Tampilkan Nama Orang Tua" << endl;
    cout << "4. Tampilkan Nama Anak" << endl;
    cout << "5. Hapus Nama Orang Tua" << endl;
    cout << "6. Hapus Nama Anak" << endl;
    cout << "7. Mencari Nama Orang Tua" << endl;
    cout << "0. Keluar" << endl << endl;
    cout << "Pilihan menu : " ;

    int input;
    cin >> input;
    cout << endl;

    return input;
}

