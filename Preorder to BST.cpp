// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* build(int pre[], int& idx, int lower, int upper, int N){
        if(idx == N || pre[idx] < lower || pre[idx] > upper) return NULL;
        
        Node* root = newNode(pre[idx++]);
        root->left = build(pre, idx, lower, root->data, N);
        root->right = build(pre, idx, root->data, upper, N);
        return root;
    }
    Node* Bst(int pre[], int size) {
        // code here
        int idx = 0;
        return build(pre, idx, INT_MIN, INT_MAX, size);
    }
};




Question Link : https://www.geeksforgeeks.org/problems/preorder-to-postorder4423/