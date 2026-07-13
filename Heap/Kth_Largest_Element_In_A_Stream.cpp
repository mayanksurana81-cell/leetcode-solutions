/*
Category: Heap, Priority Queue, Design

Approach:
- Maintain a min-heap containing at most k elements.
- During initialization, insert all elements while removing the smallest whenever the heap size exceeds k.
- For each new value, insert it into the heap and again keep only the largest k elements.
- The top of the min-heap always represents the kth largest element in the stream.

Time Complexity: O(n log k) for initialization, O(log k) per add operation
Space Complexity: O(k)
*/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int ele : nums){
            pq.push(ele);
            if(pq.size() > k) pq.pop();
        } 
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */