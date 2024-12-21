#ifndef dll_H_INCLUDED
#define dll_H_INCLUDED
#include <iostream>
#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info

using namespace std;

typedef string infotype;

typedef struct elmtList *address;

struct elmtList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

bool isEmpty_103032300055(List L);
void createList_103032300055(List &L);
address createNewElmt_103032300055(infotype X);
void insertFirst_103032300055(List &L, address P);
void insertAfter_103032300055(List &L, address Prec, address P);
void insertLast_103032300055(List &L, address P);
void deleteFirst_103032300055(List &L, address &P);
void deleteAfter_103032300055(address Prec, address &P);
void deleteLas_103032300055(List &L, address &P);
void concat_103032300055(List L1, List L2, List &L3);
address findSong_103032300055(infotype judul, List L);
void removeSong_103032300055(infotype judul, List &L);


#endif // dll_H_INCLUDED