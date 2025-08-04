1st solution:
class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    bool empty() {
        return q1.empty()&&q2.empty();
    }
    
    void push(int x) {
        if(empty()){
            q1.push(x);
        }else if(q1.empty()){
            q2.push(x);
        }else{
            q1.push(x);
        }
    }
    
    int pop() {
        if(empty()) return -1;
        else if(q1.empty()){
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q2.pop();
            return ele;
        }else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q1.pop();
            return ele;
        }
    }
    
    int top() {
        if(empty()) return -1;
        else if(q1.empty()){
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int ele = q2.front();
            q1.push(ele);
            q2.pop();
            return ele;
        }else{
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int ele = q1.front();
            q2.push(ele);
            q1.pop();
            return ele;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

2nd solution:

class MyStack {
public:
    deque<int>dq;
    MyStack() {
        
    }
    
    void push(int x) {

        dq.push_back(x);
    }
    
    int pop() {
        
        if(!dq.empty()){
            int ele = dq.back();
            dq.pop_back();
            return ele;
        } 
        else return -1;
    }
    
    int top() {
        if(!dq.empty()){
            int ele = dq.back();
            return ele;
        }else return -1;
    }
    
    bool empty() {
        return dq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



Question link : https://leetcode.com/problems/implement-stack-using-queues/
