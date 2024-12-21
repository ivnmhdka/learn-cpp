#include <iostream>
#include "stack.h"

using namespace std;

void createStack_103032300055(stack &S) {
    S.Top = 0;
}

bool isEmpty_103032300055(stack S) {
    if (S.Top == 0) {
        return true;
    }else {
        return false;
    }
}

bool isFull_103032300055(stack S) {
    if (S.Top == 15) {
        return true;
    }else {
        return false;
    }
}

void push_103032300055(stack &S, infotype x) {
    if (isFull_103032300055(S) == false) {
        S.Top = S.Top + 1;
        S.info[S.Top] = x;
    }
}

infotype pop_103032300055(stack &S) {
    infotype x;
    x = S.info[S.Top];
    S.Top = S.Top - 1;
    return x;
}

void printInfo_103032300055(stack S) {
    for (int i = S.Top; i > 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}