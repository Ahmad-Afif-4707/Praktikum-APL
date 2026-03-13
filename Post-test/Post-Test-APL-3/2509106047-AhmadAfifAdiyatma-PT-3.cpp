#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

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

int hitungJumlahData(int jumlahData){
    if(jumlahData==0)
        return 0;
    else
        return 1 + hitungJumlahData(jumlahData-1);
}

bool verifikasiLogin(DataUser user,string inputNama,string inputNim){
    if(inputNama==user.nama && inputNim==user.nim)
        return true;
    else
        return false;
}

void login(DataUser user,bool &statusLogin){

    int jumlahPercobaan=0;
    string inputNama,inputNim;

    while(jumlahPercobaan<3){
        system("cls");

        cout<<"===== LOGIN ====="<<endl;
        cout<<"Nama : ";
        cin>>inputNama;

        cout<<"NIM  : ";
        cin>>inputNim;

        if(verifikasiLogin(user,inputNama,inputNim)){
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
    cout<<"5. Keluar"<<endl;

    cout<<"Pilih menu : ";
}


// CREATE
void tambahData(DataAnimasi dataAnimasi[],int &jumlahData){

    system("cls");
    cout<<"=== Tambah Data Animasi ==="<<endl;
    cout<<"(Kosongkan judul untuk batal)"<<endl<<endl;

    cout<<"Judul  : ";
    getline(cin,dataAnimasi[jumlahData].judul);

    if(dataAnimasi[jumlahData].judul==""){
        cout<<"Tambah data dibatalkan"<<endl;
        system("pause");
        return;
    }

    cout<<"Studio : ";
    getline(cin,dataAnimasi[jumlahData].studio);

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
    getline(cin,dataAnimasi[jumlahData].ulasan);

    jumlahData++;

    cout<<"Data berhasil ditambahkan"<<endl;
    system("pause");
}


// READ
void tampilData(DataAnimasi dataAnimasi[],int jumlahData){

    system("cls");

    cout<<"=== Daftar Animasi ==="<<endl;
    cout<<"====================================="<<endl;

    if(jumlahData==0){
        cout<<"Belum ada data animasi"<<endl;
    }
    else{

        for(int i=0;i<jumlahData;i++){

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
void ubahData(DataAnimasi dataAnimasi[],int jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<"Belum ada data"<<endl;
        system("pause");
        return;
    }

    cout<<"=== Ubah Data Animasi ==="<<endl;
    cout<<"(Ketik 0 untuk batal)"<<endl<<endl;

    for(int i=0;i<jumlahData;i++){
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
        getline(cin,dataAnimasi[indeks].judul);

        cout<<"Studio baru (lama: "<<dataAnimasi[indeks].studio<<") : ";
        getline(cin,dataAnimasi[indeks].studio);

        while(true){
            cout<<"Tipe baru (lama: "<<dataAnimasi[indeks].tipe<<") : ";
            cin>>dataAnimasi[indeks].tipe;

            if(dataAnimasi[indeks].tipe=="film" || dataAnimasi[indeks].tipe=="serial")
                break;

            cout<<"Input salah!"<<endl;
        }

        while(true){
            cout<<"Rating baru (lama: "<<dataAnimasi[indeks].rating<<") : ";
            cin>>dataAnimasi[indeks].rating;

            if(dataAnimasi[indeks].rating>=1 && dataAnimasi[indeks].rating<=10)
                break;

            cout<<"Rating harus 1 sampai 10"<<endl;
        }

        cin.ignore();

        cout<<"Ulasan baru (lama: "<<dataAnimasi[indeks].ulasan<<") : ";
        getline(cin,dataAnimasi[indeks].ulasan);

        cout<<"Data berhasil diubah"<<endl;
    }
    else{
        cout<<"Data tidak ditemukan"<<endl;
    }

    system("pause");
}


// DELETE
void hapusData(DataAnimasi dataAnimasi[],int &jumlahData){

    system("cls");

    if(jumlahData==0){
        cout<<"Belum ada data"<<endl;
        system("pause");
        return;
    }

    cout<<"=== Hapus Data Animasi ==="<<endl;
    cout<<"(Ketik 0 untuk batal)"<<endl<<endl;

    for(int i=0;i<jumlahData;i++){
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

        for(int i=pilihanData-1;i<jumlahData-1;i++){
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


int main(){

    DataUser user;
    user.nama="afif";
    user.nim="047";

    DataAnimasi dataAnimasi[50];

    int jumlahData=0;
    bool statusLogin=false;

    login(user,statusLogin);

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
                tambahData(dataAnimasi,jumlahData);
                break;

            case 2:
                tampilData(dataAnimasi,jumlahData);
                break;

            case 3:
                ubahData(dataAnimasi,jumlahData);
                break;

            case 4:
                hapusData(dataAnimasi,jumlahData);
                break;

            case 5:
                cout<<"Program selesai"<<endl;
                break;

            default:
                cout<<"Menu tidak valid"<<endl;
                system("pause");
        }

    }while(pilihanMenu!=5);

    return 0;
}