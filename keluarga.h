#ifndef KELUARGA_H_INCLUDED
#define KELUARGA_H_INCLUDED

#include <iostream>
using namespace std;

#define info(Q) (Q)->info
#define next(Q) (Q)->next
#define first(L) (L).first
#define nextMhs(J) (J)->nextMhs

struct anak{
  string nama;
};
typedef anak infotypeMhs;
typedef struct elmMhs *adrMhs;
typedef struct elmOrangtua *adrOrangtua;

struct orangtua{
  string ortu;
};

struct elmOrangtua{
  orangtua info;
  adrOrangtua next;
  adrMhs nextMhs;
};

struct elmMhs{
  infotypeMhs info;
  adrMhs next;
};

struct List{
  adrOrangtua first;
};

void createNew_List(List &ListMhs);
void newElement_Orangtua(orangtua info, adrOrangtua &S);
void newElement_Anak(infotypeMhs info, adrMhs &J);
void insertNew_Anak(List &ListOrtu, adrOrangtua S, adrMhs J);
void insertLast_Orangtua(List &ListOrtu, adrOrangtua S);
void deleteFirst_Anak(List &ListOrtu, adrOrangtua &S, adrMhs &J);
void deleteAfter_Anak(List &ListMhs, adrMhs Prec, adrMhs J);
adrMhs searchBefore_Anak(List ListOrtu, string ortu);
void deleteFirst_Orangtua(List &ListOrtu);
void deleteAfter_Orangtua(adrOrangtua Prec, adrOrangtua P);
adrOrangtua searchBefore_Orangtua(List ListOrtu, string ortu);
void showData_Orangtua(List ListOrtu);
void showData_Anak(List ListOrtu);
adrOrangtua search_Orangtua(List ListMhs, string ortu);
void find_Orangtua(List ListOrtu, string ortu);
void cari_Anak(List ListOrt);
int selectMenu();

#endif // KELUARGA_H_INCLUDED


