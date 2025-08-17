/*Complete the function below
Node is as follows:
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
class Solution {
  public:
    // Function to check if two nodes are cousins in a tree
    bool parent(Node* root, int x, int y){
        if(!root)return false;
        if((root->left && root->right) && 
        ((root->left->data == x && root->right->data == y) ||
        (root->left->data == y && root->right->data == x))) return true;
        
        return parent(root->left, x, y) || parent(root->right, x, y);
    }
    bool isCousins(Node* root, int x, int y) {
        // write code here
        queue<Node*>q;
        int l1=-1, l2=-1, lvl=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node* temp = q.front();
                q.pop();
                if(temp->data == x) l1 = lvl;
                if(temp->data == y) l2 = lvl;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }lvl++;
            if(l1 != l2)
            return false;
            if(l1 != -1 && l2 !=-1) break;
        }
        return !parent(root,x,y);
    }
};


Question Link : https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1