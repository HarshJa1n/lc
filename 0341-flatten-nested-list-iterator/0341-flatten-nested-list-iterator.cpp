/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> res;
    int i=0;
public:
    void arrange(vector<NestedInteger> &list){
        for(auto e:list){
            if(e.isInteger()) res.push_back(e.getInteger());
            else arrange(e.getList());
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        arrange(nestedList);
    }
    
    int next() {
        return res[i++];
    }
    
    bool hasNext() {
        return i<res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */