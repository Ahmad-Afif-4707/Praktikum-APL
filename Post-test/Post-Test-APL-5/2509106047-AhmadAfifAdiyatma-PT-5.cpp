#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

// STRUCT
struct DataUser{
    string nama;
    string nim;
};

struct DataAnimasi{
    string judul;
    string studio;
    string tipe;
    int rating;
    string ulasan;
};

// FUNGSI
int hitungJumlahData(int jumlahData){
    if(jumlahData==0)
        return 0;
    else
        return 1 + hitungJumlahData(jumlahData-1);
}

bool verifikasiLogin(DataUser user, string inputNama, string inputNim){
    if(inputNama==user.nama && inputNim==user.nim)
        return true;
    else
        return false;
}

// PROSEDUR
void login(DataUser user, bool &statusLogin){

    int jumlahPercobaan=0;
    string inputNama, inputNim;

    while(jumlahPercobaan<3){
        system("cls");

        cout<<"===== LOGIN ====="<<endl;
        cout<<"Nama : ";
        cin>>inputNama;

        cout<<"NIM  : ";
        cin>>inputNim;

        if(verifikasiLogin(user, inputNama, inputNim)){
            statusLogin=true;
            cout<<"Login berhasil!"<<endl;
            system("pause");
            break;
        }
        else{
            jumlahPercobaan++;
            cout<<"Login gagal!"<<endl;
            cout<<"Sisa percobaan : "<<3-jumlahPercobaan<<endl;
            system("pause");
        }
    }
}

void tampilMenu(){
    system("cls");

    cout<<"===== MENU UTAMA ====="<<endl;
    cout<<"1. Tambah Data Animasi"<<endl;
    cout<<"2. Lihat Data Animasi"<<endl;
    cout<<"3. Ubah Data Animasi"<<endl;
    cout<<"4. Hapus Data Animasi"<<endl;
    cout<<"5. Lihat Alamat Memori Data"<<endl;
    cout<<"6. Sorting Data"<<endl;
    cout<<"7. Keluar"<<endl;

    cout<<"Pilih menu : ";
}

// POINTER
void resetRating(int &rating){
    rating = 0;
    cout<<"Rating telah direset!"<<endl;
    cout<<"Alamat memori rating : "<<&rating<<endl;
}

void updateRating(int *rating, int ratingBaru){
    cout<<"Alamat memori rating di fungsi : "<<rating<<endl;
    *rating = ratingBaru;
    cout<<"Rating berhasil diupdate!"<<endl;
}

void tampilAlamatMemori(DataAnimasi *animasiPtr){
    cout<<"=== Alamat Memori Data Animasi ==="<<endl;
    cout<<"Alamat struct  : "<<animasiPtr<<endl;
    cout<<"Alamat judul   : "<<&animasiPtr->judul<<endl;
    cout<<"Alamat studio  : "<<&animasiPtr->studio<<endl;
    cout<<"Alamat tipe    : "<<&animasiPtr->tipe<<endl;
    cout<<"Alamat rating  : "<<&animasiPtr->rating<<endl;
    cout<<"Alamat ulasan  : "<<&animasiPtr->ulasan<<endl;
}

void menuPointer(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<"Belum ada data"<<endl;
        system("pause");
        return;
    }

    cout<<"=== Fitur Pointer ==="<<endl<<endl;

    for(int i=0; i<jumlahData; i++){
        cout<<i+1<<". "<<dataAnimasi[i].judul<<endl;
    }

    int pilihanData;

    cout<<"Pilih nomor data : ";
    cin>>pilihanData;

    if(pilihanData>=1 && pilihanData<=jumlahData){

        int indeks = pilihanData-1;

        DataAnimasi *animasiPtr = &dataAnimasi[indeks];
        tampilAlamatMemori(animasiPtr);

        cout<<endl;
        cout<<"Apakah ingin reset rating ke 0? (y/n) : ";
        char pilih;
        cin>>pilih;

        if(pilih=='y' || pilih=='Y'){
            cout<<"Alamat memori rating di main : "<<&dataAnimasi[indeks].rating<<endl;
            resetRating(dataAnimasi[indeks].rating);
        }
    }
    else{
        cout<<"Data tidak ditemukan"<<endl;
    }

    system("pause");
}

// SORTING

// Bubble Sort - sorting judul ascending (A-Z)
void bubbleSortJudulAscending(DataAnimasi dataAnimasi[], int jumlahData){
    bool ditukar;
    for(int i=0; i<jumlahData-1; i++){
        ditukar = false;
        for(int j=0; j<jumlahData-i-1; j++){
            if(dataAnimasi[j].judul > dataAnimasi[j+1].judul){
                DataAnimasi temp = dataAnimasi[j];
                dataAnimasi[j]   = dataAnimasi[j+1];
                dataAnimasi[j+1] = temp;
                ditukar = true;
            }
        }
        if(ditukar==false)
            break;
    }
}

// Selection Sort - sorting rating descending
void selectionSortRatingDescending(DataAnimasi dataAnimasi[], int jumlahData){
    for(int i=0; i<jumlahData-1; i++){
        int indeksMaks = i;
        for(int j=i+1; j<jumlahData; j++){
            if(dataAnimasi[j].rating > dataAnimasi[indeksMaks].rating){
                indeksMaks = j;
            }
        }
        if(indeksMaks != i){
            DataAnimasi temp       = dataAnimasi[i];
            dataAnimasi[i]         = dataAnimasi[indeksMaks];
            dataAnimasi[indeksMaks] = temp;
        }
    }
}

// Insertion Sort - sorting judul descending (Z-A)
void insertionSortJudulDescending(DataAnimasi dataAnimasi[], int jumlahData){
    for(int i=1; i<jumlahData; i++){
        DataAnimasi kunci = dataAnimasi[i];
        int j = i-1;
        while(j>=0 && dataAnimasi[j].judul < kunci.judul){
            dataAnimasi[j+1] = dataAnimasi[j];
            j = j-1;
        }
        dataAnimasi[j+1] = kunci;
    }
}

void tampilHasilSorting(DataAnimasi dataAnimasi[], int jumlahData){
    cout<<left;
    for(int i=0; i<jumlahData; i++){
        cout<<"[ "<<i+1<<" ]"<<endl;
        cout<<setw(10)<<"Judul"<<": "<<dataAnimasi[i].judul<<endl;
        cout<<setw(10)<<"Studio"<<": "<<dataAnimasi[i].studio<<endl;
        cout<<setw(10)<<"Tipe"<<": "<<dataAnimasi[i].tipe<<endl;
        cout<<setw(10)<<"Rating"<<": "<<dataAnimasi[i].rating<<"/10"<<endl;
        cout<<setw(10)<<"Ulasan"<<": "<<dataAnimasi[i].ulasan<<endl;
        cout<<"-------------------------------------"<<endl;
    }
}

void menuSorting(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<"Belum ada data"<<endl;
        system("pause");
        return;
    }

    cout<<"=== Menu Sorting ==="<<endl<<endl;
    cout<<"1. Bubble Sort  - Judul Ascending  (A-Z)"<<endl;
    cout<<"2. Selection Sort - Rating Descending (9-1)"<<endl;
    cout<<"3. Insertion Sort - Judul Descending (Z-A)"<<endl;
    cout<<"4. Kembali"<<endl<<endl;
    cout<<"Pilih metode sorting : ";

    int pilihanSorting;
    cin>>pilihanSorting;

    DataAnimasi salinanData[50];
    for(int i=0; i<jumlahData; i++){
        salinanData[i] = dataAnimasi[i];
    }

    system("cls");

    if(pilihanSorting==1){
        bubbleSortJudulAscending(salinanData, jumlahData);
        cout<<"=== Hasil Bubble Sort - Judul Ascending (A-Z) ==="<<endl;
        cout<<"====================================="<<endl;
        tampilHasilSorting(salinanData, jumlahData);
    }
    else if(pilihanSorting==2){
        selectionSortRatingDescending(salinanData, jumlahData);
        cout<<"=== Hasil Selection Sort - Rating Descending (9-1) ==="<<endl;
        cout<<"====================================="<<endl;
        tampilHasilSorting(salinanData, jumlahData);
    }
    else if(pilihanSorting==3){
        insertionSortJudulDescending(salinanData, jumlahData);
        cout<<"=== Hasil Insertion Sort - Judul Descending (Z-A) ==="<<endl;
        cout<<"====================================="<<endl;
        tampilHasilSorting(salinanData, jumlahData);
    }
    else if(pilihanSorting==4){
        return;
    }
    else{
        cout<<"Pilihan tidak valid"<<endl;
    }

    system("pause");
}

// CREATE
void tambahData(DataAnimasi dataAnimasi[], int &jumlahData){

    system("cls");
    cout<<"=== Tambah Data Animasi ==="<<endl;
    cout<<"(Kosongkan judul untuk batal)"<<endl<<endl;

    cout<<"Judul  : ";
    getline(cin, dataAnimasi[jumlahData].judul);

    if(dataAnimasi[jumlahData].judul==""){
        cout<<"Tambah data dibatalkan"<<endl;
        system("pause");
        return;
    }

    cout<<"Studio : ";
    getline(cin, dataAnimasi[jumlahData].studio);

    while(true){
        cout<<"Tipe (film / serial) : ";
        cin>>dataAnimasi[jumlahData].tipe;

        if(dataAnimasi[jumlahData].tipe=="film" || dataAnimasi[jumlahData].tipe=="serial")
            break;

        cout<<"Input salah!"<<endl;
    }

    while(true){
        cout<<"Rating (1-10) : ";
        cin>>dataAnimasi[jumlahData].rating;

        if(dataAnimasi[jumlahData].rating>=1 && dataAnimasi[jumlahData].rating<=10)
            break;

        cout<<"Rating harus 1 sampai 10"<<endl;
    }

    cin.ignore();

    cout<<"Ulasan : ";
    getline(cin, dataAnimasi[jumlahData].ulasan);

    jumlahData++;

    cout<<"Data berhasil ditambahkan"<<endl;
    system("pause");
}

// READ
void tampilData(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");

    cout<<"=== Daftar Animasi ==="<<endl;
    cout<<"====================================="<<endl;

    if(jumlahData==0){
        cout<<"Belum ada data animasi"<<endl;
    }
    else{
        for(int i=0; i<jumlahData; i++){

            cout<<"[ "<<i+1<<" ]"<<endl;
            cout<<left;
            cout<<setw(10)<<"Judul"<<": "<<dataAnimasi[i].judul<<endl;
            cout<<setw(10)<<"Studio"<<": "<<dataAnimasi[i].studio<<endl;
            cout<<setw(10)<<"Tipe"<<": "<<dataAnimasi[i].tipe<<endl;
            cout<<setw(10)<<"Rating"<<": "<<dataAnimasi[i].rating<<"/10"<<endl;
            cout<<setw(10)<<"Ulasan"<<": "<<dataAnimasi[i].ulasan<<endl;
            cout<<"-------------------------------------"<<endl;
        }

        int totalData = hitungJumlahData(jumlahData);
        cout<<"Total animasi : "<<totalData<<endl;
    }

    system("pause");
}

// UPDATE
void ubahData(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<"Belum ada data"<<endl;
        system("pause");
        return;
    }

    cout<<"=== Ubah Data Animasi ==="<<endl;
    cout<<"(Ketik 0 untuk batal)"<<endl<<endl;

    for(int i=0; i<jumlahData; i++){
        cout<<i+1<<". "<<dataAnimasi[i].judul<<endl;
    }

    int pilihanData;

    cout<<"Pilih nomor data : ";
    cin>>pilihanData;
    cin.ignore();

    if(pilihanData==0){
        cout<<"Ubah data dibatalkan"<<endl;
        system("pause");
        return;
    }

    if(pilihanData>=1 && pilihanData<=jumlahData){

        int indeks = pilihanData-1;

        cout<<"Judul baru (lama: "<<dataAnimasi[indeks].judul<<") : ";
        getline(cin, dataAnimasi[indeks].judul);

        cout<<"Studio baru (lama: "<<dataAnimasi[indeks].studio<<") : ";
        getline(cin, dataAnimasi[indeks].studio);

        cout<<"Tipe baru (lama: "<<dataAnimasi[indeks].tipe<<") : ";
        cin>>dataAnimasi[indeks].tipe;

        int ratingBaru;
        cout<<"Rating baru (lama: "<<dataAnimasi[indeks].rating<<") : ";
        cin>>ratingBaru;
        updateRating(&dataAnimasi[indeks].rating, ratingBaru);

        cin.ignore();

        cout<<"Ulasan baru (lama: "<<dataAnimasi[indeks].ulasan<<") : ";
        getline(cin, dataAnimasi[indeks].ulasan);

        cout<<"Data berhasil diubah"<<endl;
    }
    else{
        cout<<"Data tidak ditemukan"<<endl;
    }

    system("pause");
}

// DELETE
void hapusData(DataAnimasi dataAnimasi[], int &jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<"Belum ada data"<<endl;
        system("pause");
        return;
    }

    cout<<"=== Hapus Data Animasi ==="<<endl;
    cout<<"(Ketik 0 untuk batal)"<<endl<<endl;

    for(int i=0; i<jumlahData; i++){
        cout<<i+1<<". "<<dataAnimasi[i].judul<<endl;
    }

    int pilihanData;

    cout<<"Pilih nomor data : ";
    cin>>pilihanData;

    if(pilihanData==0){
        cout<<"Hapus data dibatalkan"<<endl;
        system("pause");
        return;
    }

    if(pilihanData>=1 && pilihanData<=jumlahData){

        cout<<"Yakin hapus \""<<dataAnimasi[pilihanData-1].judul<<"\"? (y/n) : ";
        char konfirmasi;
        cin>>konfirmasi;

        if(konfirmasi=='n' || konfirmasi=='N'){
            cout<<"Hapus data dibatalkan"<<endl;
            system("pause");
            return;
        }

        for(int i=pilihanData-1; i<jumlahData-1; i++){
            dataAnimasi[i] = dataAnimasi[i+1];
        }

        jumlahData--;
        cout<<"Data berhasil dihapus"<<endl;
    }
    else{
        cout<<"Data tidak ditemukan"<<endl;
    }

    system("pause");
}

// MAIN
int main(){

    DataUser user;
    user.nama="afif";
    user.nim="047";

    DataAnimasi dataAnimasi[50];
    int jumlahData=0;
    bool statusLogin=false;

    // data dummy
    dataAnimasi[0].judul   = "Avatar The Last Airbender";
    dataAnimasi[0].studio  = "Nickelodeon";
    dataAnimasi[0].tipe    = "serial";
    dataAnimasi[0].rating  = 10;
    dataAnimasi[0].ulasan  = "Serial animasi terbaik";

    dataAnimasi[1].judul   = "Gravity Falls";
    dataAnimasi[1].studio  = "Disney Television";
    dataAnimasi[1].tipe    = "serial";
    dataAnimasi[1].rating  = 10;
    dataAnimasi[1].ulasan  = "Misteri dan humor yang sangat seru";

    dataAnimasi[2].judul   = "The Incredibles";
    dataAnimasi[2].studio  = "Pixar";
    dataAnimasi[2].tipe    = "film";
    dataAnimasi[2].rating  = 9;
    dataAnimasi[2].ulasan  = "Film superhero keluarga yang sangat bagus";
    jumlahData=3;

    login(user, statusLogin);

    if(statusLogin==false){
        cout<<"Program berhenti karena gagal login"<<endl;
        return 0;
    }

    int pilihanMenu;

    do{
        tampilMenu();

        cin>>pilihanMenu;
        cin.ignore();

        switch(pilihanMenu){

            case 1:
                tambahData(dataAnimasi, jumlahData);
                break;

            case 2:
                tampilData(dataAnimasi, jumlahData);
                break;

            case 3:
                ubahData(dataAnimasi, jumlahData);
                break;

            case 4:
                hapusData(dataAnimasi, jumlahData);
                break;

            case 5:
                menuPointer(dataAnimasi, jumlahData);
                break;

            case 6:
                menuSorting(dataAnimasi, jumlahData);
                break;

            case 7:
                cout<<"Program selesai"<<endl;
                break;

            default:
                cout<<"Menu tidak valid"<<endl;
                system("pause");
        }

    }while(pilihanMenu!=7);

    return 0;
}