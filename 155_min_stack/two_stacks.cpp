class MinStack {
private:
    vector<int> origin;
    vector<int> min;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        origin.push_back(x);
        if(!min.size() || x <= min.back()) min.push_back(x);
    }
    
    void pop() {
        int last = origin.back();
        if(last == min.back()) min.pop_back();
        origin.pop_back();
    }
    
    int top() {
        return origin.back();
    }
    
    int getMin() {
        return min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
