class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int popEl = -1;
        if(!s2.empty()) popEl = s2.top();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            popEl = s2.top();
        }
        s2.pop();
        return popEl;
    }
    
    int peek() {
        int front = -1;
        if(!s2.empty()) front = s2.top();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */