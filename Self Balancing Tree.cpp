#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

int height(node* T);
int BF(node* T);
node* rotate_left(node* x);
node* rotate_right(node* x);
node* LL(node* T);
node* RR(node* T);
node* LR(node* T);
node* RL(node* T);

node* insert(node* T, int x) {
    if (T == NULL) {
        T = (node*)malloc(sizeof(node));
        T->val = x;
        T->left = NULL;
        T->right = NULL;
        T->ht = 0;
        return T;
    }

    if (x < T->val) {
        T->left = insert(T->left, x);
        if (BF(T) == 2) {
            if (x < T->left->val)
                T = LL(T);
            else
                T = LR(T);
        }
    } else if (x > T->val) {
        T->right = insert(T->right, x);
        if (BF(T) == -2) {
            if (x > T->right->val)
                T = RR(T);
            else
                T = RL(T);
        }
    }

    T->ht = height(T);
    return T;
}

int height(node* T) {
    if (T == NULL) return 0;
    int lh = (T->left == NULL) ? 0 : 1 + T->left->ht;
    int rh = (T->right == NULL) ? 0 : 1 + T->right->ht;
    return (lh > rh) ? lh : rh;
}

int BF(node* T) {
    if (T == NULL) return 0;
    int lh = (T->left == NULL) ? 0 : 1 + T->left->ht;
    int rh = (T->right == NULL) ? 0 : 1 + T->right->ht;
    return (lh - rh);
}

node* rotate_left(node* x) {
    node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* rotate_right(node* x) {
    node* y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return y;
}

node* LL(node* T) {
    return rotate_right(T);
}

node* RR(node* T) {
    return rotate_left(T);
}

node* LR(node* T) {
    T->left = rotate_left(T->left);
    return rotate_right(T);
}

node* RL(node* T) {
    T->right = rotate_right(T->right);
    return rotate_left(T);
}

// Traversals for testing
void inorder(node* T) {
    if (T != NULL) {
        inorder(T->left);
        cout << T->val << "(BF=" << BF(T) << ") ";
        inorder(T->right);
    }
}

void preorder(node* T) {
    if (T != NULL) {
        cout << T->val << "(BF=" << BF(T) << ") ";
        preorder(T->left);
        preorder(T->right);
    }
}

int main() {
    int n;
    cin >> n;

    node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int new_val;
    cin >> new_val;
    root = insert(root, new_val);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;

    return 0;
}
