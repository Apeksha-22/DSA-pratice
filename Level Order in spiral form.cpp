/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        stack<Node*>RL,LR;
        vector<int>res;
        RL.push(root);
        while(!RL.empty() || !LR.empty()){
            if(RL.empty()){
                while(!LR.empty()){
                    Node* temp = LR.top();
                    LR.pop();
                    res.push_back(temp->data);
                    if(temp->left)RL.push(temp->left);
                    if(temp->right)RL.push(temp->right);
                    
                }
            }else{
                while(!RL.empty()){
                    Node* temp = RL.top();
                    RL.pop();
                    res.push_back(temp->data);
                    if(temp->right)LR.push(temp->right);
                    if(temp->left)LR.push(temp->left);  
                    
                }
            }
        }
        return res;
    }
};


Question Link : https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1