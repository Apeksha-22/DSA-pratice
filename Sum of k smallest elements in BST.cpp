// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void cal(Node*root, int& k, int& sum){
    if(!root)return;
    
    cal(root->left,k,sum);
    if(k<=0)return;
    sum += root->data;
    k--;
    cal(root->right, k, sum);
}
int sum(Node* root, int k) {

    // Your code here
    int sum=0;
    cal(root, k, sum);
    return sum;
}



Question Link : https://www.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/