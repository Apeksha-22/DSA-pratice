/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root)return 0;
        if(root->data == key)
        return 1;
        else if(root->data > key)
        return search(root->left, key);
        else
        return search(root->right, key);
    }
};


Question Link : https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1