/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
[1,2,4]
[1,3,5]
[3,6]

merged list: [1,1,2,3,3,4,5,6]

approach:
- we can use a min heap to consistently grab the smallest node in k lists,
  as we traverse through each list constructing our merged list, the heap will
  keep track of the next minimum node to add each time
- need a heap -> min heap (c++ gives a max heap by default)
    - will store the k lists
    - for each iteration we will be popping the min node and adding it
      to our merged array and if it has a neighbor, pushing that to the min heap
      for updating
- complexity:
    - Time: O(N*logK)
            - where N is all the nodes in the combined K lists we are traversing
            - where pushing/popping into heap requires heapify, which takes logK
    - Space: O(K)
            - where K represents size of heap holding K nodes
                - merged list considered constant, only allocates a dummy node
                  and updates the node to point at nodes already previously
                  allocated and present amongst the K lists
*/

class Solution {
private:
    struct ListComparator{
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Base case
        if(lists.empty())
            return nullptr;

        // Create a min-heap (custom-made)
        priority_queue<ListNode*, vector<ListNode*>, ListComparator> minHeap;

        // Push the K lists into minHeap -> will preserve node order grabbing smallest node each time
        for(ListNode* list : lists){
            if(list)
                minHeap.push(list);
        }

        // Create merged node to hold merged list
        ListNode* merged = new ListNode();
        ListNode* curr = merged;

        // Construct the merged list
        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top(); minHeap.pop();
            curr->next = smallest;
            curr = curr->next;
            if(smallest->next)
                minHeap.push(smallest->next);
        }

        // Return the merged list (dummy's next)
        return merged->next;
    }
};












