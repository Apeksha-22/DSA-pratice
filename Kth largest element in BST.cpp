/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void large(Node*root, int& k, int& lar){
        if(!root) return;
        large(root->right, k, lar);
        k--;
        if(k==0){
            lar = root->data;
            return;
        }
        large(root->left, k, lar);
    }
    int kthLargest(Node *root, int k) {
        // Your code here
        int lar = 0;
        large(root, k, lar);
        return lar;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1