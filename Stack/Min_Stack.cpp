 /*
Category: Stack, Design

Approach:
- Use two stacks:
  - st     -> stores all elements
  - minst  -> stores minimum elements
- During push:
  - Insert value into the main stack.
  - Push into minst only if it is smaller than or equal to the current minimum.
- During pop:
  - If the top element of the main stack matches the minimum stack top,
    remove it from minst as well.
- top() returns the latest inserted element.
- getMin() always returns the current minimum in constant time.

Time Complexity: O(1)
Space Complexity: O(n)
 */
class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || val <= minst.top()) minst.push(val);
        
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() == minst.top()){
            minst.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minst.empty()) return -1;
        return minst.top();
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