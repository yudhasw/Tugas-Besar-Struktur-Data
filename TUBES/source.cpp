#include "header.h"

//Menambahkan data PesertaTurnamen dari depan/belakang
void tambahPesertaTurnamen(ListAtlet A, ListTurnamen T, ListPesertaTurnamen &PT, adr_PT newPesertaTurnamen) {
    //jika data peserta turnamen tidak valid/null
    if (newPesertaTurnamen == NULL) {
        cout << "Peserta turnamen tidak valid." << endl;
        return; //procedure langsung keluar
    }

    int pilihan; //variabel untuk memasukkan inputan pilihan menambahkan peserta dari depan/belakang
    bool validInput = false; //untuk mengecek inputan valid atau tidak (antara integer 1 dan 2)

    //loop sampai inputannya valid
    while (!validInput) {
        cout << "Pilih opsi:" << endl;
        cout << "1. Tambah data Peserta Turnamen dari depan" << endl;
        cout << "2. Tambah data Peserta Turnamen dari belakang" << endl;
        cout << "Pilihan anda: ";
        cin >> pilihan;

        if (pilihan == 1) { //tambah peserta turnamen dari depan
            next(newPesertaTurnamen) = first(PT);
            if (first(PT) != NULL) {
                prev(first(PT)) = newPesertaTurnamen;
            } else {
                last(PT) = newPesertaTurnamen;
            }
            first(PT) = newPesertaTurnamen;
            validInput = true; //loop berhenti
        } else if (pilihan == 2) { //tambah peserta turnamen dari depan
            if (last(PT) == NULL) {
                first(PT) = last(PT) = newPesertaTurnamen;
            } else {
                next(last(PT)) = newPesertaTurnamen;
                prev(newPesertaTurnamen) = last(PT);
                last(PT) = newPesertaTurnamen;
            }
            validInput = true; //loop berhenti
        } else {
            cout << "Pilihan tidak valid. Silakan input ulang!" << endl;
        }
    }
    cout << "Peserta turnamen berhasil ditambahkan." << endl;
}

//Menampilkan seluruh data PesertaTurnamen beserta data Atlet dan Turnamen yang diikutinya
void show_pesertaTurnamen(ListPesertaTurnamen PT) {
    adr_PT P = first(PT);
    //jika data peserta turnamen tidak ada/null
    if (P == NULL) {
        cout << "Tidak ada peserta turnamen." << endl;
        return;
    }

    // Header Tabel
    cout << "==========================================================================================================================" << endl;
    cout << "| ID Peserta | Peringkat | Status Keikutsertaan |       Atlet        |            Turnamen            |" << endl;
    cout << "|            |           |                      | NIK - Nama Atlet  | ID - Nama Turnamen - Cabang     |" << endl;
    cout << "==========================================================================================================================" << endl;

    while (P != NULL) {
        // Data Peserta Turnamen
        cout << "| " << info(P).ID_peserta
             << " | " << info(P).peringkat
             << " | " << info(P).statusKeikutsertaan;

        // Data Atlet
        if (adrAtlet(P) != NULL) {
            cout << " | " << info(adrAtlet(P)).NIK << " - "
                 << info(adrAtlet(P)).nama_atlet;
        } else {
            cout << " | Data Atlet Tidak Tersedia";
        }

        // Data Turnamen
        if (adrTurnamen(P) != NULL) {
            cout << " | " << info(adrTurnamen(P)).ID_turnamen << " - "
                 << info(adrTurnamen(P)).nama_turnamen << " - "
                 << info(adrTurnamen(P)).cabang_olahraga;
        } else {
            cout << " | Data Turnamen Tidak Tersedia";
        }

        cout << " |" << endl;
        P = next(P);
    }

    cout << "==========================================================================================================================" << endl;
}

//Menghapus data PesertaTurnamen, dan data Atlet dan Turnamen didalamnya
void hapusPesertaTurnamen(ListPesertaTurnamen &PT, adr_PT delPesertaTurnamen) {
    //jika data peserta turnamen tidak ada/null
    if (delPesertaTurnamen == NULL) {
        cout << "Peserta tidak ditemukan." << endl;
        return;
    }

    if (delPesertaTurnamen == first(PT)) { //menghapus data peserta turnamen dari depan (delete first)
        first(PT) = next(delPesertaTurnamen);
        if (first(PT) != NULL) {
            prev(first(PT)) = NULL;
        } else {
            last(PT) = NULL;
        }
    } else if (delPesertaTurnamen == last(PT)) { //menghapus data peserta turnamen dari belakang (delete last)
        last(PT) = prev(delPesertaTurnamen);
        if (last(PT) != NULL) {
            next(last(PT)) = NULL;
        } else {
            first(PT) = NULL;
        }
    } else { //menghapus data peserta turnamen setelah (delete after)
        prev(next(delPesertaTurnamen)) = prev(delPesertaTurnamen);
        next(prev(delPesertaTurnamen)) = next(delPesertaTurnamen);
    }

    cout << "Peserta turnamen berhasil dihapus." << endl;
}

// Mencari data PesertaTurnamen
adr_PT findPesertaTurnamen(ListAtlet A, ListTurnamen T, ListPesertaTurnamen PT){

}

// Menambahkan/Menghapus data Atlet
void tambahHapusDataAtlet(ListAtlet &A, adr_atlet P){
    int pilihan;
    bool validInput = false;

    //Loop sampai mendapatkan input yang valid
    while (!validInput) {
        cout << "Pilih opsi:" << endl;
        cout << "1. Tambah data atlet" << endl;
        cout << "2. Hapus data atlet" << endl;
        cout << "Pilihan anda: ";
        cin >> pilihan;

        if (pilihan == 1){

        }else if (pilihan == 2){

        } else {
            cout << "Pilihan tidak valid. Silakan input ulang!" << endl;
        }
    }
}



//Menambahkan elemen baru data relasi Atlet dan Turnamen ke data PesertaTurnamen
adr_PT createElemenPesertaTurnamen(adr_atlet A, adr_turnamen T, dataPesertaTurnamen data){
/*I.S List atlet A dan list turnamen T terisi data, dan terdefinisi data/
/*F.S adrAtlet terisi alamat list atlet, dan adrTurnamen terisi alamat list turnamen. info PT terisi data */
    adr_PT PT = new elemenListPesertaTurnamen;
    info(PT) = data;
    adrAtlet(PT) = A;
    adrTurnamen(PT) = T;
    next(PT) = NULL;
    prev(PT) = NULL;
    return PT;
};

//Menampilkan seluruh data Atlet
void show_dataAtlet(ListAtlet A){
//I.S terdefinisi T berisi data turnamen
//F.S menampilkan semua data turnamen
    adr_atlet pointer = first(A);
    cout << "Daftar Atlet:" << endl;
    if (first(A) == NULL){
        cout << "Tidak ada atlet yang terdaftar" << endl;
    } else {
        printf("%16f %15s %10s %15s %15s\n", "NIK", "Nama", "TglLahir", "Asal Daerah", "Cabor");
        while (pointer != NULL){
            printf("%16f %15s %10s %15s %15s\n", info(pointer).NIK, info(pointer).nama_atlet, info(pointer).tanggal_lahir, info(pointer).asal_daerah, info(pointer).cabang_olahraga);
            pointer = next(pointer);
        }
    }
};

//Menampilkan seluruh data Turnamen
void show_dataTurnamen(ListTurnamen T){
    adr_turnamen pointer = first(T);
    cout << "Daftar Turnamen:" << endl;
    if (first(T) == NULL){
        cout << "Tidak ada turnamen yang tersedia" << endl;
    } else {
        printf("%16f %15s %10s %15s %15s\n", "ID Turnamen", "Nama", "Tingakt", "Cabor", "Deskripsi");
        while (pointer != NULL){
            printf("%16f %15s %10s %15s %15s\n", info(pointer).ID_turnamen, info(pointer).nama_turnamen, info(pointer).tingkat, info(pointer).cabang_olahraga, info(pointer).deskripsi);
            pointer = next(pointer);
        }
    }
};
