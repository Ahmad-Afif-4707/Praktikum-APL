#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <windows.h>
using namespace std;

// warna
#define RESET  "\033[0m"
#define HIJAU  "\033[32m"
#define KUNING "\033[33m"
#define CYAN   "\033[36m"
#define MERAH  "\033[31m"
#define TEBAL  "\033[1m"

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

//  FUNGSI
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

void bersihkanBuffer(){
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    while(_kbhit()){
        getch();
    }
}

void cetakGaris(char karakter, int panjang){
    for(int i=0; i<panjang; i++) cout<<karakter;
    cout<<endl;
}

void tampilkanJudul(string judul){
    cout<<endl;
    cout<<CYAN;
    cetakGaris('=', 40);
    cout<<" "<<KUNING<<TEBAL<<judul<<RESET<<endl;
    cout<<CYAN;
    cetakGaris('=', 40);
    cout<<RESET<<endl;
}

void tampilKartu(DataAnimasi data, int nomor){
    cout<<CYAN;
    cetakGaris('-', 40);
    cout<<KUNING<<TEBAL<<" ["<<nomor<<"] "<<data.judul<<RESET<<endl;
    cetakGaris('-', 40);
    cout<<left;
    cout<<" "<<setw(8)<<"Studio" <<": "<<data.studio<<endl;
    cout<<" "<<setw(8)<<"Tipe"   <<": "<<data.tipe<<endl;
    cout<<" "<<setw(8)<<"Rating" <<": "<<KUNING;
    for(int i=0; i<data.rating; i++)  cout<<"*";
    for(int i=data.rating; i<10; i++) cout<<".";
    cout<<RESET<<" ("<<data.rating<<"/10)"<<endl;
    cout<<" "<<setw(8)<<"Ulasan" <<": "<<data.ulasan<<endl;
    cout<<CYAN;
    cetakGaris('-', 40);
    cout<<RESET;
}

int navigasiMenu(string opsi[], int jumlahOpsi, string judul){
    int posisiKursor = 0;

    system("cls");

    cout<<endl;
    cout<<CYAN;
    cetakGaris('=', 40);
    cout<<" "<<KUNING<<TEBAL<<judul<<RESET<<endl;
    cout<<CYAN;
    cetakGaris('=', 40);
    cout<<RESET<<endl;

    int barisAwalOpsi = 6;

    for(int i=0; i<jumlahOpsi; i++){
        if(i==posisiKursor){
            cout<<HIJAU<<TEBAL<<"  >> "<<opsi[i]<<"               "<<RESET<<endl;
        }
        else{
            cout<<"     "<<opsi[i]<<"               "<<RESET<<endl;
        }
    }

    cout<<endl;
    cout<<CYAN;
    cetakGaris('-', 40);
    cout<<KUNING<<" panah atas/bawah + enter"<<RESET<<endl;
    cout<<CYAN;
    cetakGaris('-', 40);
    cout<<RESET;
    cout.flush();

    while(true){
        int inputTombol = getch();

        if(inputTombol==224){
            int arahTombol = getch();
            int posisiLama = posisiKursor;

            if(arahTombol==72 && posisiKursor>0)
                posisiKursor--;
            else if(arahTombol==80 && posisiKursor<jumlahOpsi-1)
                posisiKursor++;

            if(posisiLama != posisiKursor){

                cout<<"\033["<<(barisAwalOpsi+posisiLama)<<";1H";
                cout<<"\033[2K";
                cout<<"     "<<opsi[posisiLama]<<RESET;

                cout<<"\033["<<(barisAwalOpsi+posisiKursor)<<";1H";
                cout<<"\033[2K";
                cout<<HIJAU<<TEBAL<<"  >> "<<opsi[posisiKursor]<<RESET;

                cout.flush();
            }
        }
        else if(inputTombol==13){
            return posisiKursor;
        }
    }
}

// PROSEDUR
void login(DataUser user, bool &statusLogin){

    int jumlahPercobaan=0;

    while(jumlahPercobaan<3){
        system("cls");

        cout<<endl;
        cout<<CYAN;
        cetakGaris('=', 40);
        cout<<" "<<KUNING<<TEBAL<<"Program Koleksi Animasi"<<RESET<<endl;
        cout<<CYAN;
        cetakGaris('-', 40);
        cout<<" Login"<<endl;
        cout<<CYAN;
        cetakGaris('=', 40);
        cout<<RESET<<endl;

        if(jumlahPercobaan>0){
            cout<<MERAH<<" [X] Login gagal! sisa percobaan : "<<3-jumlahPercobaan<<RESET<<endl<<endl;
        }

        string inputNama, inputNim;

        bersihkanBuffer();
        cout<<KUNING<<" Nama : "<<RESET;
        cin>>inputNama;

        bersihkanBuffer();
        cout<<KUNING<<" NIM  : "<<RESET;
        cin>>inputNim;

        if(verifikasiLogin(user, inputNama, inputNim)){
            statusLogin=true;
            cout<<endl<<HIJAU<<TEBAL<<" [OK] Login berhasil!"<<RESET<<endl;
            cout<<endl;
            system("pause");
            break;
        }
        else{
            jumlahPercobaan++;
            system("pause");
        }
    }

    if(statusLogin==false){
        cout<<endl<<MERAH<<" [X] Terlalu banyak percobaan gagal."<<RESET<<endl;
    }
}

// POINTER
void resetRating(int &rating){
    rating = 0;
    cout<<HIJAU<<" [OK] Rating direset ke 0"<<RESET<<endl;
    cout<<KUNING<<" Alamat memori rating : "<<RESET<<&rating<<endl;
}

void updateRating(int *rating, int ratingBaru){
    cout<<KUNING<<" Alamat memori rating di fungsi : "<<RESET<<rating<<endl;
    *rating = ratingBaru;
    cout<<HIJAU<<" [OK] Rating diupdate"<<RESET<<endl;
}

void tampilAlamatMemori(DataAnimasi *animasiPtr){
    tampilkanJudul("Alamat Memori");
    cout<<KUNING<<" Alamat struct  : "<<RESET<<animasiPtr<<endl;
    cout<<KUNING<<" Alamat judul   : "<<RESET<<&animasiPtr->judul<<endl;
    cout<<KUNING<<" Alamat studio  : "<<RESET<<&animasiPtr->studio<<endl;
    cout<<KUNING<<" Alamat tipe    : "<<RESET<<&animasiPtr->tipe<<endl;
    cout<<KUNING<<" Alamat rating  : "<<RESET<<&animasiPtr->rating<<endl;
    cout<<KUNING<<" Alamat ulasan  : "<<RESET<<&animasiPtr->ulasan<<endl;
}

void menuPointer(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<MERAH<<" [X] Belum ada data"<<RESET<<endl;
        system("pause");
        return;
    }

    tampilkanJudul("Fitur Pointer");

    for(int i=0; i<jumlahData; i++){
        cout<<CYAN<<" ["<<i+1<<"] "<<RESET<<dataAnimasi[i].judul<<endl;
    }

    cout<<endl;

    try{
        int pilihanData;
        bersihkanBuffer();
        cout<<KUNING<<" Pilih nomor data : "<<RESET;
        cin>>pilihanData;

        if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            throw string("input harus angka!");
        }

        if(pilihanData<1 || pilihanData>jumlahData){
            throw string("nomor tidak valid!");
        }

        int indeks = pilihanData-1;

        DataAnimasi *animasiPtr = &dataAnimasi[indeks];
        tampilAlamatMemori(animasiPtr);

        cout<<endl;
        system("pause");

        string opsiReset[] = {"Ya, reset rating ke 0", "Tidak"};
        int pilihanReset   = navigasiMenu(opsiReset, 2, "Reset Rating?");

        system("cls");

        if(pilihanReset==0){
            cout<<endl;
            cout<<KUNING<<" Alamat rating di main : "<<RESET<<&dataAnimasi[indeks].rating<<endl;
            resetRating(dataAnimasi[indeks].rating);
        }
        else{
            cout<<endl<<KUNING<<" dibatalkan"<<RESET<<endl;
        }
    }
    catch(string pesanError){
        cout<<endl<<MERAH<<" [X] Error: "<<pesanError<<RESET<<endl;
    }

    cout<<endl;
    system("pause");
}

// SORTING
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
        if(ditukar==false) break;
    }
}

void selectionSortRatingDescending(DataAnimasi dataAnimasi[], int jumlahData){
    for(int i=0; i<jumlahData-1; i++){
        int indeksMaks = i;
        for(int j=i+1; j<jumlahData; j++){
            if(dataAnimasi[j].rating > dataAnimasi[indeksMaks].rating){
                indeksMaks = j;
            }
        }
        if(indeksMaks != i){
            DataAnimasi temp        = dataAnimasi[i];
            dataAnimasi[i]          = dataAnimasi[indeksMaks];
            dataAnimasi[indeksMaks] = temp;
        }
    }
}

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
    for(int i=0; i<jumlahData; i++){
        tampilKartu(dataAnimasi[i], i+1);
    }
}

void menuSorting(DataAnimasi dataAnimasi[], int jumlahData){

    if(jumlahData==0){
        system("cls");
        cout<<MERAH<<" [X] Belum ada data"<<RESET<<endl;
        system("pause");
        return;
    }

    string opsiSorting[] = {
        "Bubble Sort    - Judul A-Z",
        "Selection Sort - Rating 9-1",
        "Insertion Sort - Judul Z-A",
        "Kembali"
    };

    int pilihanSorting = navigasiMenu(opsiSorting, 4, "Menu Sorting");

    if(pilihanSorting==3) return;

    DataAnimasi salinanData[50];
    for(int i=0; i<jumlahData; i++){
        salinanData[i] = dataAnimasi[i];
    }

    system("cls");

    if(pilihanSorting==0){
        bubbleSortJudulAscending(salinanData, jumlahData);
        tampilkanJudul("Bubble Sort - Judul A-Z");
        tampilHasilSorting(salinanData, jumlahData);
    }
    else if(pilihanSorting==1){
        selectionSortRatingDescending(salinanData, jumlahData);
        tampilkanJudul("Selection Sort - Rating 9-1");
        tampilHasilSorting(salinanData, jumlahData);
    }
    else if(pilihanSorting==2){
        insertionSortJudulDescending(salinanData, jumlahData);
        tampilkanJudul("Insertion Sort - Judul Z-A");
        tampilHasilSorting(salinanData, jumlahData);
    }

    system("pause");
}

// SEARCHING
void binarySearchRating(DataAnimasi *dataAnimasi, int jumlahData){

    DataAnimasi salinanData[50];
    for(int i=0; i<jumlahData; i++){
        salinanData[i] = *(dataAnimasi+i);
    }

    for(int i=0; i<jumlahData-1; i++){
        for(int j=0; j<jumlahData-i-1; j++){
            if((salinanData+j)->rating > (salinanData+j+1)->rating){
                DataAnimasi temp   = *(salinanData+j);
                *(salinanData+j)   = *(salinanData+j+1);
                *(salinanData+j+1) = temp;
            }
        }
    }

    try{
        int ratingDicari;
        bersihkanBuffer();
        cout<<KUNING<<" Masukkan rating yang dicari (1-10) : "<<RESET;
        cin>>ratingDicari;

        if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            throw string("rating harus angka!");
        }

        if(ratingDicari<1 || ratingDicari>10){
            throw string("rating harus antara 1-10!");
        }

        int indeksKiri  = 0;
        int indeksKanan = jumlahData-1;
        bool ditemukan  = false;

        while(indeksKiri<=indeksKanan){
            int indeksTengah = (indeksKiri+indeksKanan)/2;

            if((salinanData+indeksTengah)->rating == ratingDicari){
                int posisiAwal = indeksTengah;
                while(posisiAwal>0 && (salinanData+posisiAwal-1)->rating==ratingDicari){
                    posisiAwal--;
                }
                tampilkanJudul("Hasil - Rating " + to_string(ratingDicari));
                for(int i=posisiAwal; i<jumlahData && (salinanData+i)->rating==ratingDicari; i++){
                    tampilKartu(*(salinanData+i), i+1);
                }
                ditemukan = true;
                break;
            }
            else if((salinanData+indeksTengah)->rating < ratingDicari){
                indeksKiri = indeksTengah+1;
            }
            else{
                indeksKanan = indeksTengah-1;
            }
        }

        if(ditemukan==false){
            cout<<MERAH<<" [X] rating "<<ratingDicari<<" tidak ditemukan"<<RESET<<endl;
        }
    }
    catch(string pesanError){
        cout<<MERAH<<" [X] Error: "<<pesanError<<RESET<<endl;
    }
}

void jumpSearchJudul(DataAnimasi *dataAnimasi, int jumlahData){

    DataAnimasi salinanData[50];
    for(int i=0; i<jumlahData; i++){
        salinanData[i] = *(dataAnimasi+i);
    }

    for(int i=0; i<jumlahData-1; i++){
        for(int j=0; j<jumlahData-i-1; j++){
            if((salinanData+j)->judul > (salinanData+j+1)->judul){
                DataAnimasi temp   = *(salinanData+j);
                *(salinanData+j)   = *(salinanData+j+1);
                *(salinanData+j+1) = temp;
            }
        }
    }

    try{
        string judulDicari;
        bersihkanBuffer();
        cout<<KUNING<<" Masukkan judul : "<<RESET;
        cin.ignore();
        getline(cin, judulDicari);

        if(judulDicari.empty()){
            throw string("judul tidak boleh kosong!");
        }

        int ukuranLompatan = (int)sqrt((double)jumlahData);
        int posisiSebelum  = 0;
        int posisiSekarang = ukuranLompatan;

        while(posisiSekarang<jumlahData && (salinanData+posisiSekarang-1)->judul < judulDicari){
            posisiSebelum  = posisiSekarang;
            posisiSekarang += ukuranLompatan;
        }

        bool ditemukan = false;
        int batasAkhir = posisiSekarang < jumlahData ? posisiSekarang : jumlahData;

        for(int i=posisiSebelum; i<batasAkhir; i++){
            if((salinanData+i)->judul == judulDicari){
                tampilkanJudul("Hasil - " + judulDicari);
                tampilKartu(*(salinanData+i), i+1);
                ditemukan = true;
            }
        }

        if(ditemukan==false){
            cout<<MERAH<<" [X] judul \""<<judulDicari<<"\" tidak ditemukan"<<RESET<<endl;
        }
    }
    catch(string pesanError){
        cout<<MERAH<<" [X] Error: "<<pesanError<<RESET<<endl;
    }
}

void menuSearching(DataAnimasi dataAnimasi[], int jumlahData){

    if(jumlahData==0){
        system("cls");
        cout<<MERAH<<" [X] Belum ada data"<<RESET<<endl;
        system("pause");
        return;
    }

    string opsiSearching[] = {
        "Binary Search - cari rating",
        "Jump Search   - cari judul",
        "Kembali"
    };

    int pilihanSearching = navigasiMenu(opsiSearching, 3, "Menu Searching");

    if(pilihanSearching==2) return;

    system("cls");

    if(pilihanSearching==0){
        tampilkanJudul("Binary Search - Rating");
        binarySearchRating(dataAnimasi, jumlahData);
    }
    else if(pilihanSearching==1){
        tampilkanJudul("Jump Search - Judul");
        jumpSearchJudul(dataAnimasi, jumlahData);
    }

    cout<<endl;
    system("pause");
}

// CREATE
void tambahData(DataAnimasi dataAnimasi[], int &jumlahData){

    system("cls");
    tampilkanJudul("Tambah Data Animasi");
    cout<<KUNING<<" (kosongkan judul untuk batal)"<<RESET<<endl<<endl;

    try{
        bersihkanBuffer();
        cout<<KUNING<<" Judul  : "<<RESET;
        getline(cin, dataAnimasi[jumlahData].judul);

        if(dataAnimasi[jumlahData].judul==""){
            throw string("tambah data dibatalkan");
        }

        bersihkanBuffer();
        cout<<KUNING<<" Studio : "<<RESET;
        getline(cin, dataAnimasi[jumlahData].studio);

        if(dataAnimasi[jumlahData].studio==""){
            throw string("studio tidak boleh kosong!");
        }

        bersihkanBuffer();
        cout<<KUNING<<" Tipe (film/serial) : "<<RESET;
        cin>>dataAnimasi[jumlahData].tipe;

        if(dataAnimasi[jumlahData].tipe!="film" && dataAnimasi[jumlahData].tipe!="serial"){
            throw string("tipe harus film atau serial!");
        }

        bersihkanBuffer();
        cout<<KUNING<<" Rating (1-10) : "<<RESET;
        cin>>dataAnimasi[jumlahData].rating;

        if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            throw string("rating harus angka!");
        }

        if(dataAnimasi[jumlahData].rating<1 || dataAnimasi[jumlahData].rating>10){
            throw string("rating harus antara 1-10!");
        }

        cin.ignore();
        bersihkanBuffer();
        cout<<KUNING<<" Ulasan : "<<RESET;
        getline(cin, dataAnimasi[jumlahData].ulasan);

        jumlahData++;

        cout<<endl<<HIJAU<<TEBAL<<" [OK] data berhasil ditambahkan!"<<RESET<<endl;
    }
    catch(string pesanError){
        cout<<endl<<MERAH<<" [X] "<<pesanError<<RESET<<endl;
    }

    cout<<endl;
    system("pause");
}

//  READ
void tampilData(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");
    tampilkanJudul("Daftar Animasi");

    if(jumlahData==0){
        cout<<KUNING<<" belum ada data animasi"<<RESET<<endl;
    }
    else{
        for(int i=0; i<jumlahData; i++){
            tampilKartu(dataAnimasi[i], i+1);
        }
        int totalData = hitungJumlahData(jumlahData);
        cout<<endl<<CYAN<<" total : "<<HIJAU<<TEBAL<<totalData<<" animasi"<<RESET<<endl;
    }

    cout<<endl;
    system("pause");
}

// UPDATE
void ubahData(DataAnimasi dataAnimasi[], int jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<MERAH<<" [X] Belum ada data"<<RESET<<endl;
        system("pause");
        return;
    }

    tampilkanJudul("Ubah Data Animasi");
    cout<<KUNING<<" (ketik 0 untuk batal)"<<RESET<<endl;
    cout<<KUNING<<" (enter = tetap nilai lama)"<<RESET<<endl<<endl;

    for(int i=0; i<jumlahData; i++){
        cout<<CYAN<<" ["<<i+1<<"] "<<RESET<<dataAnimasi[i].judul<<endl;
    }

    cout<<endl;

    try{
        int pilihanData;
        bersihkanBuffer();
        cout<<KUNING<<" Pilih nomor : "<<RESET;
        cin>>pilihanData;

        if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            throw string("input harus angka!");
        }

        if(pilihanData==0){
            throw string("ubah data dibatalkan");
        }

        if(pilihanData<1 || pilihanData>jumlahData){
            throw string("nomor tidak valid!");
        }

        int indeks = pilihanData-1;
        cin.ignore();

        cout<<endl;

        // judul
        string judulBaru;
        bersihkanBuffer();
        cout<<KUNING<<" Judul baru  (lama: "<<dataAnimasi[indeks].judul<<") : "<<RESET;
        getline(cin, judulBaru);
        if(judulBaru != "") dataAnimasi[indeks].judul = judulBaru;

        // studio
        string studioBaru;
        bersihkanBuffer();
        cout<<KUNING<<" Studio baru (lama: "<<dataAnimasi[indeks].studio<<") : "<<RESET;
        getline(cin, studioBaru);
        if(studioBaru != "") dataAnimasi[indeks].studio = studioBaru;

        // tipe
        string tipeBaru;
        bersihkanBuffer();
        cout<<KUNING<<" Tipe baru   (lama: "<<dataAnimasi[indeks].tipe<<") : "<<RESET;
        getline(cin, tipeBaru);
        if(tipeBaru != ""){
            if(tipeBaru!="film" && tipeBaru!="serial"){
                throw string("tipe harus film atau serial!");
            }
            dataAnimasi[indeks].tipe = tipeBaru;
        }

        // rating
        string ratingInput;
        bersihkanBuffer();
        cout<<KUNING<<" Rating baru (lama: "<<dataAnimasi[indeks].rating<<") : "<<RESET;
        getline(cin, ratingInput);
        if(ratingInput != ""){
            try{
                int ratingBaru = stoi(ratingInput);
                if(ratingBaru<1 || ratingBaru>10){
                    throw string("rating harus antara 1-10!");
                }
                updateRating(&dataAnimasi[indeks].rating, ratingBaru);
            }
            catch(string pesanRating){
                throw pesanRating;
            }
            catch(...){
                throw string("rating harus angka!");
            }
        }

        // ulasan
        string ulasanBaru;
        bersihkanBuffer();
        cout<<KUNING<<" Ulasan baru (lama: "<<dataAnimasi[indeks].ulasan<<") : "<<RESET;
        getline(cin, ulasanBaru);
        if(ulasanBaru != "") dataAnimasi[indeks].ulasan = ulasanBaru;

        cout<<endl<<HIJAU<<TEBAL<<" [OK] data berhasil diubah!"<<RESET<<endl;
    }
    catch(string pesanError){
        cout<<endl<<MERAH<<" [X] "<<pesanError<<RESET<<endl;
    }

    cout<<endl;
    system("pause");
}

// DELETE
void hapusData(DataAnimasi dataAnimasi[], int &jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<MERAH<<" [X] Belum ada data"<<RESET<<endl;
        system("pause");
        return;
    }

    tampilkanJudul("Hapus Data Animasi");
    cout<<KUNING<<" (ketik 0 untuk batal)"<<RESET<<endl<<endl;

    for(int i=0; i<jumlahData; i++){
        cout<<CYAN<<" ["<<i+1<<"] "<<RESET<<dataAnimasi[i].judul<<endl;
    }

    cout<<endl;

    try{
        int pilihanData;
        bersihkanBuffer();
        cout<<KUNING<<" Pilih nomor : "<<RESET;
        cin>>pilihanData;

        if(cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
            throw string("input harus angka!");
        }

        if(pilihanData==0){
            throw string("hapus data dibatalkan");
        }

        if(pilihanData<1 || pilihanData>jumlahData){
            throw string("nomor tidak valid!");
        }

        string opsiKonfirmasi[] = {
            "Ya hapus \"" + dataAnimasi[pilihanData-1].judul + "\"",
            "Tidak, batal"
        };
        int pilihanKonfirmasi = navigasiMenu(opsiKonfirmasi, 2, "Konfirmasi Hapus");

        if(pilihanKonfirmasi==1){
            throw string("hapus data dibatalkan");
        }

        for(int i=pilihanData-1; i<jumlahData-1; i++){
            dataAnimasi[i] = dataAnimasi[i+1];
        }

        jumlahData--;
        system("cls");
        cout<<endl<<HIJAU<<TEBAL<<" [OK] data berhasil dihapus!"<<RESET<<endl;
    }
    catch(string pesanError){
        system("cls");
        cout<<endl<<KUNING<<" [X] "<<pesanError<<RESET<<endl;
    }

    cout<<endl;
    system("pause");
}

//MAIN
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
    dataAnimasi[1].ulasan  = "Misteri dan humor yang seru";

    dataAnimasi[2].judul   = "The Incredibles";
    dataAnimasi[2].studio  = "Pixar";
    dataAnimasi[2].tipe    = "film";
    dataAnimasi[2].rating  = 9;
    dataAnimasi[2].ulasan  = "Film superhero keluarga yang bagus";

    jumlahData=3;

    login(user, statusLogin);

    if(statusLogin==false){
        return 0;
    }

    string opsiMenu[] = {
        "Tambah Data",
        "Lihat Data",
        "Ubah Data",
        "Hapus Data",
        "Lihat Alamat Memori",
        "Sorting",
        "Searching",
        "Keluar"
    };

    int pilihanMenu;

    do{
        pilihanMenu = navigasiMenu(opsiMenu, 8, "Program Koleksi Animasi");

        switch(pilihanMenu){
            case 0: tambahData(dataAnimasi, jumlahData);    break;
            case 1: tampilData(dataAnimasi, jumlahData);    break;
            case 2: ubahData(dataAnimasi, jumlahData);      break;
            case 3: hapusData(dataAnimasi, jumlahData);     break;
            case 4: menuPointer(dataAnimasi, jumlahData);   break;
            case 5: menuSorting(dataAnimasi, jumlahData);   break;
            case 6: menuSearching(dataAnimasi, jumlahData); break;
            case 7:
                system("cls");
                cout<<endl<<CYAN;
                cetakGaris('=', 40);
                cout<<" "<<KUNING<<"terima kasih!"<<RESET<<endl;
                cout<<CYAN;
                cetakGaris('=', 40);
                cout<<RESET<<endl<<endl;
                break;
        }

    }while(pilihanMenu!=7);

    return 0;
}