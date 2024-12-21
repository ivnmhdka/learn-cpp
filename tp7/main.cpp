#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack S;
    createStack_103032300055(S);

    push_103032300055(S, 'G');
    push_103032300055(S, 'N');
    push_103032300055(S, 'U');
    push_103032300055(S, 'D');
    push_103032300055(S, 'N');
    push_103032300055(S, 'A');
    push_103032300055(S, 'B');
    push_103032300055(S, 'O');
    push_103032300055(S, 'L');
    push_103032300055(S, 'A');
    push_103032300055(S, 'H');

    cout << "isi stack awal: " << endl;
    printInfo_103032300055(S);

    pop_103032300055(S);
    pop_103032300055(S);
    pop_103032300055(S);
    pop_103032300055(S);

    cout << "isi stack sesudah pop: " << endl;
    printInfo_103032300055(S);

    return 0;
}