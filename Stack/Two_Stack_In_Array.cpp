

#include <bits/stdc++.h>
using namespace std;
class twoStacks {
  public:

    vector<int> s1, s2;
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        s1.push_back(x);
    }
    
    // Function to push an integer into the stack2.
    void push2(int x) {
        s2.push_back(x);
    }
    
    // Function to remove an element from top of the stack1.
    int pop1() {
        int ret = s1.size() > 0 ? s1.back() : -1;
        if(s1.size())
        s1.pop_back();
        return ret;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        int ret = s2.size() > 0 ? s2.back() : -1;
        if(s2.size())
        s2.pop_back();
        return ret;
    }
};