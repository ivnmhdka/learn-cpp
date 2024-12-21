#include "dll.h"
#include <iostream>

using namespace std;

bool isEmpty_103032300055(List L) {
    if (first(L) == NULL && last(L) == NULL) {
        return true;
    }else {
        return false;
    }
}

void createList(List &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElmt_103032300055(infotype X) {
    address P = new elmtList;
    if (P != NULL) {
        info(P) = X;
        next(P) = NULL;
        prev(P) = NULL;
    }
    return P;
}

void insertFirst_103032300055(List &L, address P) {
    if (isEmpty_103032300055(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter_103032300055(List &L, address Prec, address P) {
    if (Prec != NULL) {
        next(P) = next(Prec);
        prev(P) = Prec;
        if (next(Prec) != NULL) {
            prev(next(Prec)) = P;
        } else {
            last(L) = P;
        }
        next(Prec) = P;
    }
}

void insertLast_103032300055(List &L, address P) {
    if (isEmpty_103032300055(L)) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst_103032300055(List &L, address &P) {
    if (!isEmpty_103032300055(L)) {
        P = first(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            prev(first(L)) = NULL;
        }
        next(P) = NULL;
    }
}

void deleteAfter_103032300055(address Prec, address &P) {
    if (Prec != NULL && next(Prec) != NULL) {
        P = next(Prec);
        next(Prec) = next(P);
        if (next(P) != NULL) {
            prev(next(P)) = Prec;
        }
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteLast_103032300055(List &L, address &P) {
    if (!isEmpty_103032300055(L)) {
        P = last(L);
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(P);
            next(last(L)) = NULL;
        }
        prev(P) = NULL;
    }
}

void concat_103032300055(List L1, List L2, List &L3) {
    createList(L3);

    address P = first(L1);
    while (P != NULL) {
        address newNode = createNewElmt_103032300055(info(P));
        insertLast_103032300055(L3, newNode);
        P = next(P);
    }

    P = first(L2);
    while (P != NULL) {
        address newNode = createNewElmt_103032300055(info(P));
        insertLast_103032300055(L3, newNode);
        P = next(P);
    }
}

address findSong_103032300055(infotype judul, List L) {
    address P = first(L);
    while (P != NULL) {
        if (info(P) == judul) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void removeSong_103032300055(infotype judul, List &L) {
    address P = findSong_103032300055(judul, L);
    if (P != NULL) {
        if (P == first(L)) {
            deleteFirst_103032300055(L, P);
        } else if (P == last(L)) {
            deleteLast_103032300055(L, P);
        } else {
            address Prec = prev(P);
            deleteAfter_103032300055(Prec, P);
        }
    }
}