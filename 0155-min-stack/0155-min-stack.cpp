class MinStack {
public:
    stack<int> st; 
    multiset<int> s;
    MinStack() {
       
    }
    
    void push(int value) {
        st.push(value);
        s.insert(value);
    }
    
    void pop() {
        auto it=s.find(st.top());
        st.pop();
        s.erase(it);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto itr=s.begin();
        return *itr;
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