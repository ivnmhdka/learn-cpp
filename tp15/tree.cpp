#include "tree.h"

adrNode newNode_103032300055(infotype x) {
    adrNode p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

adrNode findNode_103032300055(adrNode root, infotype x) {
    if (root == NULL || root->info == x) {
        return root;
    }
    if (x < root->info) {
        return findNode_103032300055(root->left, x);
    } else {
        return findNode_103032300055(root->right, x);
    }
}

void insertNode_103032300055(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else if (p->info < root->info) {
        insertNode_103032300055(root->left, p);
    } else {
        insertNode_103032300055(root->right, p);
    }
}

void printPreOrder_103032300055(adrNode root) {
    if (root != NULL) {
        cout << root->info << " ";
        printPreOrder_103032300055(root->left);
        printPreOrder_103032300055(root->right);
    }
}

void printDescendant_103032300055(adrNode root, infotype x) {
    adrNode target = findNode_103032300055(root, x);
    if (target != NULL) {
        printPreOrder_103032300055(root->left);
        printPreOrder_103032300055(root->right);
    }
}

int sumNode_103032300055(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + sumNode_103032300055(root->left) + sumNode_103032300055(root->right);
}

int countLeaves_103032300055(adrNode root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves_103032300055(root->left) + countLeaves_103032300055(root->right);
}

int heightTree_103032300055(adrNode root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = heightTree_103032300055(root->left);
    int rightHeight = heightTree_103032300055(root->right);
    return 1 + max(leftHeight, rightHeight);
}
