class MedianFinder {
  /*
   * Complexity: O(lgn), O(1)
   * Space: O(n)
   * Reference:
   * https://leetcode.com/problems/find-median-from-data-stream/discuss/74062/Short-simple-JavaC++Python-O(log-n)-+-O(1)
   */
private: 
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(min_heap.size() >= max_heap.size()){
            max_heap.push(num);
            if(min_heap.size() && max_heap.top() > min_heap.top()){
                max_heap.push(min_heap.top());
                min_heap.push(max_heap.top());
                max_heap.pop();
                min_heap.pop();
            }
        }
        else {
            min_heap.push(num);
            if(max_heap.size() && max_heap.top() > min_heap.top()){
                max_heap.push(min_heap.top());
                min_heap.push(max_heap.top());
                max_heap.pop();
                min_heap.pop();
            }
        }
    }
    
    double findMedian() {
        return (max_heap.size() > min_heap.size() ? max_heap.top() :( min_heap.top() + max_heap.top()) / 2.0);
    }
};

