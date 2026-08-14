class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int Kth;

    KthLargest(int k, vector<int>& nums) : Kth(k) {
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > Kth)
            minHeap.pop();
        return minHeap.top();
    }
};
