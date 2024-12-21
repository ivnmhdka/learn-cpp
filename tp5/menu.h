#ifndef menu_H_INCLUDED
#define menu_H_INCLUDED
#include <iostream>
#define first(L) (L).first
#define next(p) (p)->next
#define info(p) (p)->info

using namespace std;

typedef string infotype;

typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList_103032300055(List &L);
address createNewElement_103032300055(infotype x);
void insertLast_103032300055(List &L, address p);
void showAllData_103032300055(List L);
address shortestName_103032300055(List L);
void showFirstName_103032300055(List L, int k, char c);
int selectMenu_103032300055();

#endif // menu_H_INCLUDED