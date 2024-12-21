#include "menu.h"
#include <iostream>

using namespace std;

void createList_103032300055(List &L) {
    first(L) = NULL;
}
address createNewElement_103032300055(infotype x) {
    address p = new elmList;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void insertLast_103032300055(List &L, address p) {
    address q;
    if(first(L) == NULL) {
        first(L) = p;
    } else {
        q = first(L);
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = p;
    }
}

void showAllData_103032300055(List L) {
    address p = first(L);
    cout << "Data pengunjung: " << endl;
    while (p != NULL) {
        cout << info(p) << endl;
        p = next(p);
    }
    cout << endl;
}

address shortestName_103032300055(List L) {
    address p = first(L);
    address namaPendek = p;
    while (p != NULL) {
        if(info(p).length() <= info(namaPendek).length()) {
            namaPendek = p;
        }
        p = next(p);
    }
    return namaPendek;
}

void showFirstName_103032300055(List L, int k, char c) {
    address p;
    int h;
    p = first(L);
    h = 0;
    while (p != NULL && h < k) {
        if(info(p) [0] == c) {
            cout << info(p) << endl;
            h++;
        }
        p = next(p);
    }
    if(h == 0) {
        cout << "Tidak ada pengunjung yang memiliki nama berawalan" << c << "." << endl;
    } else if (h < k) {
        cout << "Hanya ada" << h << "pengunjung dengan nama berawalan" << c << "." << endl;
    }
}

int selectMenu_103032300055() {
    cout << "-----MENU----" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Menampilkan nama terpendek" << endl;
    cout << "4. Menampilkan nama berawalan pilihan" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan Menu: ";
    int input;
    cin >> input;
    cout << endl;
    return input;
}