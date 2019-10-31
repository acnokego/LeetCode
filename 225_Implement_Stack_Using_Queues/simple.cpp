class MyStack {
private:
    queue<int>q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    // O(n), push the new element and pop all the old one and then push back
    // again so that the new element would be the first.
    void push(int x) {
        int ori_size = q.size();
        q.push(x);
        for(int i = 0; i < ori_size; ++i){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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
