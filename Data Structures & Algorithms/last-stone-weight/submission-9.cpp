class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone: stones)
            maxHeap.push(stone);

        while(!maxHeap.empty()){
            if(maxHeap.size() < 2)
                return maxHeap.top();

            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();

            if(x == y)      continue;
            if(x < y)       maxHeap.push(y-x);
            // if(x > y)       maxHeap.push(x-y);
        }

        return 0;
    }
};
