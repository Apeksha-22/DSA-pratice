/*struct Node
{
    int data;
    Node *left, *right;
};*/

Node* build(int post[], int& idx, int lower, int upper){
    if(idx < 0 || post[idx] <= lower || post[idx] >= upper) return NULL;
    
    Node* root = new Node(post[idx--]);
    root->right = build(post, idx, root->data, upper);
    root->left = build(post, idx, lower, root->data);
    return root;
}
Node *constructTree(int post[], int size) {
    // code here
    int idx = size-1;
    return build(post, idx, INT_MIN, INT_MAX);
}



Question Link : https://www.geeksforgeeks.org/problems/construct-bst-from-post-order/