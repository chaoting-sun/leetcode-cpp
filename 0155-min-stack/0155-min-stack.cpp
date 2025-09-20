// Approach1: One Stack. For each pushed element, store { value, minimum value }
// Time: O(1) for push, pop, top, and getMin
// Space: O(n)

// class MinStack {
// public:
//     stack<pair<int,int>> st;
//     MinStack() {}
    
//     void push(int val) {
//         if (!st.empty()) {
//             int min_val = st.top().second;
//             st.push(make_pair(val, min(val, min_val)));
//         } else {
//             st.push(make_pair(val, val));
//         }
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

// Approach2.1: Two Stacks. One stores the element and another stores the minimum value
// Time: O(1) for push, pop, top, and getMin
// Space: O(n)
// class MinStack {
// public:
//     stack<int> st;
//     stack<int> min_st;
//     MinStack() {}
    
//     void push(int val) {
//         st.push(val);
//         // if the value has been the minimum value, we still need to store it in min_st
//         // because if not, once it get removed, we are not sure if the value exists before it.
//         if (min_st.empty() || val <= min_st.top()) {
//             min_st.push(val);
//         }
//     }
    
//     void pop() {
//         int top = st.top();
//         st.pop();
//         if (top == min_st.top())
//             min_st.pop();
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return min_st.top();
//     }
// };

// Approach2.1. Two Stacks, One stores the element and another stores the minimum value and the number of appearances
// Time: O(1) for push, pop, top, and getMin
// Space: O(n)
// class MinStack {
// public:
//     stack<int> st;
//     stack<pair<int, int>> min_st;
//     MinStack() {}
    
//     void push(int val) {
//         st.push(val);
//         if (min_st.empty()) {
//             min_st.push({ val, 1 });
//             return;
//         }

//         if (val < min_st.top().first) {
//             min_st.push({ val, 1 });
//         } else if (val == min_st.top().first) {
//             min_st.top().second++;
//         }
//     }
    
//     void pop() {
//         int top = st.top();
//         st.pop();
//         if (top == min_st.top().first) {
//             min_st.top().second--;
//             if (min_st.top().second == 0) min_st.pop();
//         }
//     }
    
//     int top() {
//         return st.top();
//     }
    
//     int getMin() {
//         return min_st.top().first;
//     }
// };

// Used for next practice

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack {
private:
    stack<pair<int,int>> stk;

public:
    MinStack() {}
    
    void push(int val) {
        int minVal = val;
        if (!stk.empty() && stk.top().second < minVal) {
            minVal = stk.top().second;
        }
        stk.push({ val, minVal });
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
