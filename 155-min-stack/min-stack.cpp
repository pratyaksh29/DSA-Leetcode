class MinStack {
public:
    /** initialize your data structure here. */
    stack<long> s;
    long me;
    MinStack() {
        
    }
    
    void push(int x) {
        if(s.empty()){
            s.push(x);
            me = x;
        }
        else{
            if(x <= me){
                // put 2*x - me into stack
                s.push(2ll*x - me);
                me = x;
            }
            else{
                s.push(x);
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        // stack top can never be smaller than me, if it is then it indicates a flag which means before popping, you have to update me
        if(s.top() < me){
            // me = 2*me - s.top()
            me = 2ll*me - s.top();
        }
        s.pop();
    }
    
    // critical part
    int top() {
        if(s.empty()) return -1;
        if(s.top() < me){
            return me;
        }
        return s.top();
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return me;
    }
};