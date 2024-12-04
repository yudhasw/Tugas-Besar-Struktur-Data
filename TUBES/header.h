#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define adrAtlet(P) P->adrAtlet
#define adrTurnamen(P) P->adrTurnamen
using namespace std;

typedef struct elemenListAtlet *adr_atlet;
typedef struct elemenListTurnamen *adr_turnamen;
typedef struct elemenListPesertaTurnamen *adr_PT;

struct dataAtlet {
    int NIK;
    string nama_atlet;
    string tanggal_lahir;
    string asal_daerah;
    string cabang_olahraga;
};
struct elemenListAtlet {
    dataAtlet info;
    adr_atlet next;
};
struct ListAtlet {
    adr_atlet first;
};
struct dataTurnamen {
    int ID_turnamen;
    string nama_turnamen;
    string deskripsi;
    string cabang_olahraga;
    string tingkat;
};
struct elemenListTurnamen {
    dataTurnamen info;
    adr_turnamen next;
};
struct ListTurnamen {
    adr_turnamen first;
};

struct dataPesertaTurnamen {
    int ID_peserta;
    string peringkat;
    string statusKeikutsertaan;
};
struct elemenListPesertaTurnamen {
    dataPesertaTurnamen info;
    adr_PT prev, next;
    adr_atlet adrAtlet;
    adr_turnamen adrTurnamen;
};
struct ListPesertaTurnamen {
    adr_PT first, last;
};

//Menambahkan data PesertaTurnamen dari depan/belakang
void tambahPesertaTurnamen(ListAtlet A, ListTurnamen T, ListPesertaTurnamen &PT, adr_PT newPesertaTurnamen);
//Menampilkan seluruh data PesertaTurnamen beserta data Atlet dan Turnamen yang diikutinya
void show_pesertaTurnamen(ListPesertaTurnamen PT);
//Menghapus data PesertaTurnamen, dan data Atlet dan Turnamen didalamnya
void hapusPesertaTurnamen(ListPesertaTurnamen &PT, adr_PT delPesertaTurnamen);

// Mencari data PesertaTurnamen
adr_PT findPesertaTurnamen(ListAtlet A, ListTurnamen T, ListPesertaTurnamen PT);

// Menambahkan/Menghapus data Atlet
void tambahHapusDataAtlet(ListAtlet &A, adr_atlet delDataAtlet);

// Menambahkan/Meghapus data Turnamen


//Menambahkan data relasi Atlet dan Turnamen ke data PesertaTurnamen
adr_PT createElemenPesertaTurnamen(ListAtlet A, ListTurnamen T, ListPesertaTurnamen &PT);
//Menampilkan seluruh data Atlet
void show_dataAtlet(ListAtlet A);
//Menampilkan seluruh data Turnamen
void show_dataTurnamen(ListTurnamen T);


#endif // HEADER_H_INCLUDED
