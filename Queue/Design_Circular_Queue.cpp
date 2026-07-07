/*
Category: Queue / Design
Approach:
Implement circular queue using an array with front and back pointers.
Use modulo-style wraparound when pointers reach array end, and maintain current size
to efficiently support enqueue, dequeue, front, rear, empty, and full operations.
Time Complexity: O(1)
Space Complexity: O(k)
Where k is capacity of the circular queue
*/
class MyCircularQueue {
public:
    int f,b,c,s;
    vector<int> arr;
    MyCircularQueue(int k) {
    f = 0;
    b = 0;
    c = k;
    s = 0;
    vector<int> v(k);
    arr = v;
    }
    
    bool enQueue(int val) {
    if(s==c) return false;
    arr[b] = val;
    b++;
    if(b==c) b = 0;
    s++;
    return true;   
    }
    
    bool deQueue() {
    if(s==0) return false;
    f++;
    if(f==c) f = 0;
    s--;
    return true;   
    }
    
    int Front() {
    if(s==0) return -1;
    return arr[f]; 
    }
    
    int Rear() {
    if(s==0) return -1;
    if(b==0) return arr[c-1];
    return arr[b-1];
    }
    
    bool isEmpty() {
      if(s == 0) return true;
      else return false;  
    }
    
    bool isFull() {
    if(s == c) return true;
      else return false;    
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
