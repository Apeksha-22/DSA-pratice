// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void inorder(Node*root, vector<int>&arr){
        if(!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    void maxHeap(Node*root, vector<int>&arr, int& idx){
        if(!root) return;
        maxHeap(root->left, arr, idx);
        maxHeap(root->right, arr, idx);
        root->data = arr[idx];
        idx++;

    }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int>arr;
        inorder(root, arr);
        int idx = 0;
        maxHeap(root, arr, idx);
    }
};



Question Link : https://www.geeksforgeeks.org/problems/bst-to-max-heap/