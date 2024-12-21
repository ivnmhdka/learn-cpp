#include"menu.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    int pilihan, jumlahData, cariK;
    infotype data;
    address p, namaPendek;
    char awal;
    string yn;
    createList_103032300055(L);
    pilihan = selectMenu_103032300055();
    while (pilihan != 0) {
        switch (pilihan) {
            case 1: 
                cout << "Jumlah data yang akan ditambahkan: ";
                cin >> jumlahData;
                for(int i = 1; i <= jumlahData; i++) {
                    cout << "Masukkan Nama Pengunjung: ";
                    cin >> data;
                    p = createNewElement_103032300055(data);
                    insertLast_103032300055(L, p);
                }
                cout << "Data berhasil ditambahkan." << endl;
                break;
            
            case 2:
                showAllData_103032300055(L);
                break;

            case 3: 
                namaPendek = shortestName_103032300055(L);
                cout << "Nama pengunjung terpendek terakhir adalah: " << info(namaPendek) << endl;
                break;

            case 4: 
                cout << "Berapa data yang anda ingin lihat: ";
                cin >> cariK;
                cout << "Huruf pertama apa yang anda ingin lihat";
                cin >> awal;
                showFirstName_103032300055(L, cariK, awal);
                break;

            default: 
                cout << "Pilihan tidak valdi. Silahkan coba lagi" << endl;
                break;
        }
        cout << "Kembali ke menu utama (y/n)";
        cin >> yn;
        if(yn == "y" || yn == "n") {
            pilihan = selectMenu_103032300055();
        } else {
            break;
        }
    }
    cout << "Anda Telah Keluar Dari Program" << endl;
    return 0;
}