class MyStack {
public:
    queue<int> q;
    int n;
    MyStack() {
        n=0;
    }
    
    void push(int x) {
        q.push(x);
        n++;
    }
    
    int pop() {
        int i=n-1;
        while(i--){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        int b=q.front();
        q.pop();
        n--;
        return b;
    }
    
    int top() {
        int i=n-1;
        while(i--){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        int b=q.front();
        q.pop();
        q.push(b);
        return b;
    }
    
    bool empty() {
        return n==0;
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