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
// reference: https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80146/Real-iterator-in-Python-Java-C++?page=1
class NestedIterator {
private:
    // since the sublist would be pushed later when we traverse throught it
    // we need to use LIFO data structure.
    stack< vector<NestedInteger>::iterator > begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList){
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
   
    int next() {
        hasNext();
        return (begins.top()++) -> getInteger();
      
    }
    // find an integer then return
    bool hasNext() {
        while(begins.size()){
            // the current sub list has ended
            if(begins.top() == ends.top()){
                begins.pop();
                ends.pop();
            }else{
                // check if current element is integer or list
                auto x = begins.top();
                if( x -> isInteger()) return true;
                // if current element is list, move the iterator to the next element first
                // so that after the current list is ended. the pointer point to the next element.
                ++begins.top();
                // and push the the list to the stack
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            } 
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
