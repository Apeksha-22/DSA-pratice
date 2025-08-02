class twoStacks {
  public:
    int arr[100];
    int top1,top2;
    int n=100;
    twoStacks() {
        top1 = -1;
        top2 = n;
    }
    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(top1 + 1 == top2){
            return;
        }
        top1++;
        arr[top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        
        // code here
        if(top2 - 1 == top1){
            return;
        }
        top2--;
        arr[top2] = x;
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(top1 == -1)return -1;
        
        int e=arr[top1];
        top1--;
        return e;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(top2 == n) return -1;
        
        int e=arr[top2];
        top2++;
        return e;
    }
};

question link https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
