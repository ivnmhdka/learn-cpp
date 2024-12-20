#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    int x[9] = {5, 3, 9, 10, 4, 7, 1, 8, 6};
    adrNode root = NULL;

    cout << "Array x: ";
    for (int i = 0; i < 9; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    adrNode root = NULL;
    for (int i = 0; i < 9; i++) {
        adrNode newNodePointer = newNode_103032300055(x[i]);
        insertNode_103032300055(root, newNodePointer);
    }

    cout << "\n\nPre Order\t: ";
    printPreOrder_103032300055(root);

    cout << "\n\nDescendent of Node 9\t: ";
    printDescendant_103032300055(root, 9);
    cout << endl;

    cout << "\n\nSum of BST Info\t: ";
    cout << sumNode_103032300055(root) << endl;

    cout << "\nNumber of Leaves\t: ";
    cout  << countLeaves_103032300055(root) << endl;

    cout << "\nHeight of Tree\t\t: ";
    cout  << heightTree_103032300055(root) << endl;

    return 0;
}