#include <iostream>
#include "tree.h"

using namespace std;

int main() {
    int x[9] = {5, 3, 9, 10, 4, 7, 1, 8, 6};
    adrNode root = NULL;

    for (int i = 0; i < 9; i++) {
        cout << x[i] << " ";
    }

    for (int i = 0; i < 9; i++) {
        adrNode p = newNode_103032300055(x[i]);
        insertNode_103032300055(root, p);
    }

    cout << "\n\nPre Order\t: ";
    printPreOrder_103032300055(root);

    cout << "\n\nDescendent of Node 9\t: ";
    adrNode node9 = findNode_103032300055(root, 9);
    if (node9 != NULL) {
        printPreOrder_103032300055(node9->left);
        printPreOrder_103032300055(node9->right);
    } else {
        cout << "Node 9 not found";
    }

    cout << "\n\nSum of BST Info\t: " << sumNode_103032300055(root);

    cout << "\nNumber of Leaves\t: " << countLeaves_103032300055(root);

    cout << "\nHeight of Tree\t\t: " << heightTree_103032300055(root) << endl;

    return 0;
}
