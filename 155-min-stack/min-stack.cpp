class MinStack {
public:
    stack<int>st;
    stack<int>ss; //support stack
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(ss.size()==0 || ss.top()>=val){ //use >= not only >
            ss.push(val);
        }
    }
    
    void pop() {
        int ans = st.top();
        st.pop();
        if(ans == ss.top()){
            ss.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if(ss.size()==0){
            return -1;
        }
        return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */