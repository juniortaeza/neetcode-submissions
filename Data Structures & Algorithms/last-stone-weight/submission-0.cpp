class Solution {
public:

    priority_queue<int> maxHeap;

    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty()) return 0;

        for(int stone : stones)
            maxHeap.push(stone);
        
        while(!maxHeap.empty()){
            if(maxHeap.size() < 2) return maxHeap.top();

            int x = maxHeap.top(); maxHeap.pop();
            int y = maxHeap.top(); maxHeap.pop();

            if(x > y)       maxHeap.push(x-y);
            else if(x < y)  maxHeap.push(y-x);
            else if(x == y) continue;
        }

        return 0;
    }
};
