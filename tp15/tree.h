#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>

using namespace std;

typedef int infotype;
struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* adrNode;

adrNode newNode_103032300055(infotype x);
adrNode findNode_103032300055(adrNode root, infotype x);
void insertNode_103032300055(adrNode &root, adrNode p);
void printPreOrder_103032300055(adrNode root);
void printDescendant_103032300055(adrNode root, infotype x);
int sumNode_103032300055(adrNode root);
int countLeaves_103032300055(adrNode root);
int heightTree_103032300055(adrNode root);

#endif // TREE_H_INCLUDED
