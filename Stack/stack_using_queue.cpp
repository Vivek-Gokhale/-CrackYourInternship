#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
    deque<int> d;
    MyStack() {
        
    }
    
    void push(int x) {
        d.push_back(x);
    }
    
    int pop() {
        int ret = d.back();
        d.pop_back();
        return ret;
    }
    
    int top() {
        return d.back();
    }
    
    bool empty() {
        return d.size() == 0;
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