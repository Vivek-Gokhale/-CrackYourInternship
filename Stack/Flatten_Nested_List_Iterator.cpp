

 class NestedInteger {
  public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
 


#include <bits/stdc++.h>
using namespace std;
class NestedIterator {
    vector<int> flatList;
    int iterator;
public:
    NestedIterator(std::vector<NestedInteger>& nestedList) {
        iterator = 0;
        flattenList(nestedList);
    }
    
    void flattenList(std::vector<NestedInteger>& nestedList) {
        for (NestedInteger ele : nestedList) {
            if (ele.isInteger()) {
                flatList.push_back(ele.getInteger());
            } else {
                flattenList(ele.getList());
            }
        }
    }
    
    int next() {
        if (hasNext()) {
            return flatList[iterator++];
        } else {
            return NULL;
        }
    }
    
    bool hasNext() {
        return iterator < flatList.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */