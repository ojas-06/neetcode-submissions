class MinStack {
public:
int i;
stack<int> st;
stack<int> pref;
    MinStack() {
        i = -1;
    }
    
    void push(int val) {
        st.push(val);
        if(pref.empty() || val<pref.top()) pref.push(val);
        else pref.push(pref.top());
        i++;
    }
    
    void pop() {
        st.pop();
        pref.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return pref.top();
    }
};
