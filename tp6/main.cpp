#include <iostream>
#include "dll.h"

using namespace std;

int main() {
    List L;
    createList_103032300055(L);

    address P1 = createNewElmt_103032300055("Foster_The_People-Imagination");
    address P2 = createNewElmt_103032300055("The_Corrs-Radio");
    address P3 = createNewElmt_103032300055("Maroon_5-Sugar");

    insertFirst_103032300055(L, P1);
    insertAfter_103032300055(L, P1, P2);
    insertLast_103032300055(L, P3);

    cout << "Daftar lagu yang tersedia: " << endl;
    address P = first(L);
    while (P != NULL) {
        cout << info(P) << endl;
        P = next(P);
    }
    cout << endl;

    string judulHapus;
    cout << "Masukkan judul lagu yang ingin dihapus (gunakan tanda _ sebagai pengganti spasi): ";
    cin >> judulHapus;

    address DeleteSong = findSong_103032300055(judulHapus, L);

    if (DeleteSong != NULL) {
        removeSong_103032300055(judulHapus, L);
        cout << "Lagu '" << judulHapus << "' berhasil dihapus!" << endl;
    } else {
        cout << "Lagu dengan judul '" << judulHapus << "' tidak ditemukan." << endl;
    }

    cout << "Daftar lagu setelah penghapusan: " << endl;
    P = first(L);
    while (P != NULL) {
        cout << info(P) << endl;
        P = next(P);
    }

    return 0;
}