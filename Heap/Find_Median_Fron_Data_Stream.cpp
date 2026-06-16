 /*
Category: Heap, Design

Approach:
- Maintain two heaps:
  - Max heap (left) stores the smaller half of the numbers.
  - Min heap (right) stores the larger half of the numbers.
- Insert the new number into the appropriate heap based on its value.
- Rebalance the heaps so that:
  - The size difference is at most 1.
  - The left heap is allowed to have one extra element.
- For the median:
  - If left has more elements, its top is the median.
  - Otherwise, the median is the average of the tops of both heaps.

Time Complexity: O(log n) for addNum, O(1) for findMedian
Space Complexity: O(n)
 */
class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int, vector<int> ,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        if(left.size() == right.size() + 2){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size()) return left.top();
        else{
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */