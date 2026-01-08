/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* build(int s, int e, vector<int>& arr){
        if(s>e)return NULL;
        int mid = s + (e - s)/2;
        Node* root = new Node(arr[mid]);
        root->left = build(s, mid-1, arr);
        root->right = build(mid+1, e, arr);
        
        return root;
    }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        if(arr.empty())return NULL;
        return build(0,arr.size()-1,arr);
    }
};



Question Link : https://www.geeksforgeeks.org/problems/array-to-bst4443/1