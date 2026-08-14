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

class Solution {
private:
    struct ListComparator{
        bool operator()(const ListNode* a, const ListNode* b) const {
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, ListComparator> minHeap;
        for(ListNode* list : lists){
            if(list)
                minHeap.push(list);
        }

        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(!minHeap.empty()){
            ListNode* n = minHeap.top(); minHeap.pop();
            curr->next = n;
            curr = curr->next;
            if(n->next)
                minHeap.push(n->next);
        }

        return head->next;
    }
};





