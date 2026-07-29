class MinStack {
public:
    vector<int> stack;
    vector<int> minstack;
    MinStack() {
        
    }
    
    void push(int value) {
        stack.push_back(value);
        if(minstack.empty() || value <= minstack.back())
        minstack.push_back(value);
    }
    
    void pop() {
        if(minstack.back()==stack.back()){
            minstack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */