#include <iostream>
#include <iomanip>
#include <cstdlib>

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

int main(){

    DataUser user;
    user.nama = "afif";
    user.nim = "047";

    DataAnimasi dataAnimasi[50];

    int jumlahData = 0;
    int pilihanMenu;
    int percobaanLogin = 0;
    bool statusLogin = false;

    string inputNama;
    string inputNim;

    // LOGIN
    while(percobaanLogin < 3){

        system("cls");

        cout << "===== LOGIN =====" << endl;

        cout << "Nama : ";
        cin >> inputNama;

        cout << "NIM  : ";
        cin >> inputNim;

        if(inputNama == user.nama && inputNim == user.nim){
            statusLogin = true;
            break;
        }
        else{
            cout << "Login gagal!" << endl;
            percobaanLogin++;
            system("pause");
        }
    }

    if(!statusLogin){
        cout << "Gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }

    do{

        system("cls");

        cout << "===== MENU UTAMA =====" << endl;
        cout << "1. Tambah Data Animasi" << endl;
        cout << "2. Tampilkan Data Animasi" << endl;
        cout << "3. Ubah Data Animasi" << endl;
        cout << "4. Hapus Data Animasi" << endl;
        cout << "5. Keluar" << endl;
        cout << endl;
        cout << "Pilih menu : ";
        cin >> pilihanMenu;
        cin.ignore();

        switch(pilihanMenu){

        // CREATE
        case 1: {

            system("cls");

            cout << "=== Tambah Data Animasi ===" << endl;
            cout << "(ketik 0 pada judul untuk batal)" << endl;
            cout << endl;

            cout << "Judul  : ";
            getline(cin, dataAnimasi[jumlahData].judul);

            if(dataAnimasi[jumlahData].judul == "0"){
                cout << "Tambah data dibatalkan." << endl;
                system("pause");
                break;
            }

            cout << "Studio : ";
            getline(cin, dataAnimasi[jumlahData].studio);

            while(true){

                cout << "Tipe (film/serial) : ";
                cin >> dataAnimasi[jumlahData].tipe;

                if(dataAnimasi[jumlahData].tipe == "film" || dataAnimasi[jumlahData].tipe == "serial"){
                    break;
                }
                else{
                    cout << "Input salah! hanya boleh film atau serial." << endl;
                }
            }

            while(true){

                cout << "Rating (1-10) : ";
                cin >> dataAnimasi[jumlahData].rating;

                if(dataAnimasi[jumlahData].rating >= 1 && dataAnimasi[jumlahData].rating <= 10){
                    break;
                }
                else{
                    cout << "Rating harus antara 1 sampai 10." << endl;
                }
            }

            cin.ignore();

            cout << "Ulasan : ";
            getline(cin, dataAnimasi[jumlahData].ulasan);

            jumlahData++;

            cout << endl;
            cout << "Data berhasil ditambahkan." << endl;

            system("pause");
            break;
        }

        // READ
        case 2: {

            system("cls");

            cout << "=== Data Animasi ===" << endl;
            cout << endl;

            if(jumlahData == 0){
                cout << "Belum ada data." << endl;
            }
            else{

                cout << setw(5)  << "No"
                     << setw(30) << "Judul"
                     << setw(20) << "Studio"
                     << setw(10) << "Tipe"
                     << setw(10) << "Rating"
                     << setw(25) << "Ulasan" << endl;

                cout << "--------------------------------------------------------------------------------------" << endl;

                for(int i = 0; i < jumlahData; i++){

                    cout << setw(5)  << i+1
                         << setw(30) << dataAnimasi[i].judul
                         << setw(20) << dataAnimasi[i].studio
                         << setw(10) << dataAnimasi[i].tipe
                         << setw(10) << dataAnimasi[i].rating
                         << setw(25) << dataAnimasi[i].ulasan
                         << endl;
                }
            }

            cout << endl;
            system("pause");
            break;
        }

        // UPDATE
        case 3: {

            system("cls");

            if(jumlahData == 0){
                cout << "Belum ada data untuk diubah." << endl;
                system("pause");
                break;
            }

            cout << "=== Data Animasi ===" << endl;

            for(int i = 0; i < jumlahData; i++){
                cout << i+1 << ". " << dataAnimasi[i].judul << endl;
            }

            int nomorUbah;

            cout << endl;
            cout << "Pilih nomor data (0 untuk batal) : ";
            cin >> nomorUbah;
            cin.ignore();

            if(nomorUbah == 0){
                cout << "Perubahan dibatalkan." << endl;
                system("pause");
                break;
            }

            if(nomorUbah <= jumlahData){

                cout << "Judul baru  : ";
                getline(cin, dataAnimasi[nomorUbah-1].judul);

                cout << "Studio baru : ";
                getline(cin, dataAnimasi[nomorUbah-1].studio);

                while(true){

                    cout << "Tipe baru (film/serial) : ";
                    cin >> dataAnimasi[nomorUbah-1].tipe;

                    if(dataAnimasi[nomorUbah-1].tipe == "film" || dataAnimasi[nomorUbah-1].tipe == "serial"){
                        break;
                    }
                    else{
                        cout << "Input salah!" << endl;
                    }
                }

                while(true){

                    cout << "Rating baru (1-10) : ";
                    cin >> dataAnimasi[nomorUbah-1].rating;

                    if(dataAnimasi[nomorUbah-1].rating >= 1 && dataAnimasi[nomorUbah-1].rating <= 10){
                        break;
                    }
                    else{
                        cout << "Rating harus 1-10." << endl;
                    }
                }

                cin.ignore();

                cout << "Ulasan baru : ";
                getline(cin, dataAnimasi[nomorUbah-1].ulasan);

                cout << endl;
                cout << "Data berhasil diubah." << endl;
            }
            else{
                cout << "Data tidak ditemukan." << endl;
            }

            system("pause");
            break;
        }

        // DELETE
        case 4: {

            system("cls");

            if(jumlahData == 0){
                cout << "Belum ada data untuk dihapus." << endl;
                system("pause");
                break;
            }

            cout << "=== Data Animasi ===" << endl;

            for(int i = 0; i < jumlahData; i++){
                cout << i+1 << ". " << dataAnimasi[i].judul << endl;
            }

            int nomorHapus;

            cout << endl;
            cout << "Pilih nomor data yang ingin dihapus (0 untuk batal) : ";
            cin >> nomorHapus;

            if(nomorHapus == 0){
                cout << "Penghapusan dibatalkan." << endl;
                system("pause");
                break;
            }

            if(nomorHapus <= jumlahData){

                char konfirmasi;

                cout << "Yakin ingin menghapus? (y/n) : ";
                cin >> konfirmasi;

                if(konfirmasi == 'y' || konfirmasi == 'Y'){

                    for(int i = nomorHapus-1; i < jumlahData-1; i++){
                        dataAnimasi[i] = dataAnimasi[i+1];
                    }

                    jumlahData--;

                    cout << "Data berhasil dihapus." << endl;
                }
                else{
                    cout << "Penghapusan dibatalkan." << endl;
                }

            }
            else{
                cout << "Data tidak ditemukan." << endl;
            }

            system("pause");
            break;
        }

        case 5:
            cout << "Program selesai." << endl;
            break;

        default:
            cout << "Menu tidak tersedia." << endl;
            system("pause");
        }

    }while(pilihanMenu != 5);

}