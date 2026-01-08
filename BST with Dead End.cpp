/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool solve(Node*root, int mini, int maxi){
        if(!root) return false;
        if(!root->left && !root->right)
        return maxi - root->data == 1 && root->data - mini == 1;
        return solve(root->left, mini, root->data) ||
        solve(root->right, root->data, maxi);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return solve(root, 0, INT_MAX);
    }
};




Question Link : https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/