#include "keluarga.h"
#include <stdlib.h>

int main(){
    List L;
    orangtua P;
    infotypeMhs C;
    adrOrangtua S, precPr;
    adrMhs J, precCh;

    int pilihan, x;
    string yesOrno;

    createNew_List(L);

    pilihan = selectMenu();

    while (pilihan != 0) {
        switch (pilihan){
            case 1:
                {
                string input;
                cout << "Masukkan Nama Orang Tua : ";
                cin >> input;
                P.ortu = input;
                newElement_Orangtua(P, S);
                insertLast_Orangtua(L, S);
                cout << "===========================" << endl;
                cout << "Nama Berhasil Dimasukkan" << endl;
                cout << "===========================" << endl;
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 2:
                {
                string input_nama, orangtua;
                cout << "Masukkan Nama Orang tua : ";
                cin >> orangtua;
                S = search_Orangtua(L,orangtua);
                if (S != NULL){
                    cout << "Nama Anak : ";
                    cin >> input_nama;
                    C.nama = input_nama;
                    newElement_Anak(C,J);
                    insertNew_Anak(L,S,J);
                    cout << "===============================" << endl;
                    cout << "Nama Anak Berhasil Di Tambah" << endl;
                    cout << "===============================" << endl;
                }else if (S == NULL){
                    cout << "===============================" << endl;
                    cout << "Nama Anak Tidak Ditemukan" << endl;
                    cout << "===============================" << endl;
                }
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 3:
                {
                showData_Orangtua(L);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 4:
                {
                showData_Anak(L);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 5:
                {
                string orang_tua;
                cout << "Masukkan Nama Orang Tua Yang Ingin Di Hapus : ";
                cin >> orang_tua;
                adrOrangtua p;
                p = first(L);
                if (p == NULL){
                    cout << "===================================" << endl;
                    cout << "List Nama Orang Tua Kosong" << endl;
                    cout << "===================================" << endl;
                }else if (info(p).ortu == orang_tua){
                    deleteFirst_Orangtua(L);
                    cout << "===================================" << endl;
                    cout << "Nama Orang Tua " << orang_tua << " Berhasil DiHapus" << endl;
                    cout << "===================================" << endl;
                }else if (next(p)!=NULL){
                    precPr = searchBefore_Orangtua(L, orang_tua);
                    if (info(next(precPr)).ortu == orang_tua){
                      deleteAfter_Orangtua(precPr, S);
                      cout << "===================================" << endl;
                      cout << "Nama Orang Tua " << orang_tua << " Berhasil DiHapus" << endl;
                      cout << "===================================" << endl;
                    }else{
                      cout << "===================================" << endl;
                      cout << "Nama Orang Tua " << orang_tua << " TIDAK DI TEMUKAN" << endl;
                      cout << "===================================" << endl;
                    }
                }
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 6:
                {
                string orang_tua;
                cout << "Masukkan Nama Orang Tua : ";
                cin >> orang_tua;
                adrMhs c;
                adrOrangtua P;
                P = first(L);
                if (P == NULL){
                    cout << "======================" << endl;
                    cout << "Nama Orang Tua Tidak Ada" << endl;
                    cout << "======================" << endl;
                }
                while (P != NULL){
                  adrMhs Q = nextMhs(P);
                  if (info(P).ortu == orang_tua && Q != NULL){
                    deleteFirst_Anak(L, P, J);
                    cout << "======================" << endl;
                    cout << "Nama : " << info(Q).nama << endl;
                    cout << "BERHASIL DI HAPUS" << endl;
                    cout << "======================" << endl;
                  }else if (Q == NULL){
                    cout << "List Nama Anak Tidak Ada" << endl;
                  }
                  P = next(P);
                }

                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }

            case 7:
                {
                string orang_tua;
                cout << "Masukkan Nama Orang Tua Yang Ingin Di Cari: ";
                cin >> orang_tua;
                find_Orangtua(L, orang_tua);
                while (yesOrno != "y"){
                    cout << "Kembali Ke Menu Utama (y/n): "; cin >> yesOrno;
                    if (yesOrno == "y"){
                        break;
                    }
                }
                cout << endl;
                yesOrno = "n";
                system("cls");
                break;
                }



        }
        pilihan = selectMenu();
    }

    cout << "ANDA TELAH KELUAR DARI PROGRAM DATA KELUARGA" << endl << endl;
    return 0;
}
