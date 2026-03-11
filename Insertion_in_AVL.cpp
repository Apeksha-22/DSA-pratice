#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
    public:
    int data,height;
    Node* left, *right;
    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        height = 1;
    }
};

int getHeight(Node*root){
    if(!root)
    return 0;
    return root->height;
}
int getBalance(Node* root){
    if(!root)
    return 0;
    return getHeight(root->left) - getHeight(root->right);
}
Node* leftRotate(Node* root){
    // perform left rotation
    Node* child = root->right;
    // store the left child of child before rotation
    Node* childLeft = child->left;
    // perform rotation
    child->left = root;
    // update the right child of root
    root->right=childLeft;
    // update the height of nodes
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    // update the height of child
    child->height = 1 + max(getHeight(child->left),getHeight(child->right));
    return child;
}

Node* rightRotate(Node* root){
    // perform right rotation
    Node* child = root->left;
    Node* childRight = child->right;
    // perform rotation
    child->right = root;
    // update the left child of root
    root->left=childRight;
    // update the height of nodes
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    // update the height of child
    child->height = 1 + max(getHeight(child->left),getHeight(child->right));
    return child;
}
Node* insert(int key, Node*root){
    if(!root)
    return new Node(key);
    if(key<root->data)
    root->left = insert(key,root->left);
    else if(key>root->data)
    root->right = insert(key,root->right);
    else
    return root;

    // update the height of node
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));

    int balancingFactor = getHeight(root->left) - getHeight(root->right);

    // left left case
    if(balancingFactor>1 && key<root->left->data)
    return rightRotate(root);
    // right right case
    if(balancingFactor<-1 && key>root->right->data)
    return leftRotate(root);
    // left right case
    if(balancingFactor>1 && key>root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left case
    if(balancingFactor<-1 && key<root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root){
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int n;
    cout<<"Enter the number of elements in AVL Tree: "<<endl;
    cin>>n;
    Node* root = NULL;
    cout<<"Enter the elements to be inserted: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        root = insert(x,root);
    }

    cout<<"Elements in AVL Tree: "<<endl;
    // perform inorder traversal to print the elements in sorted order
    inorder(root);
    return 0;
}