class Solution {
  public:
  stack<int>st1,st2;
    Solution() {
        // code here
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        
        // code here
        st1.push(x);
        if(!st2.empty()){
            st2.push(min(st2.top(), x));
        }else st2.push(x);
    }

    // Remove the top element from the Stack
        
    void pop() {
        // code here
        if(st1.empty()) return;
        else{
            st1.pop();
            st2.pop();
        }
    }

        
    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st1.empty()) return st1.top();
        else return -1;
    }
        

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(!st2.empty()) return st2.top();
        else return -1;
    }
};



question link https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
