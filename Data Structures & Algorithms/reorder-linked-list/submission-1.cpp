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
public:
    /*          (1)  (2)   (3)    (4)    (5)
        Time : O(F + F/2 + F/2 + (F/2 + F/2)) = O(F+F+F) = O(3F) = O(3N) = O(N)
            - (1) - fast pointer iterating over length of entire list
            - (2) - slow pointer only getting to half of where fast pointer was
            - (3) - slow pointer traverses rest of list, reversing nodes
            - (4) - weaving together first half of list and second reversed half of list

        Space: O(1)
            - no extra memory created, no allocation happening
            - only pointers that point to existing nodes are created (constant)
    */
    void reorderList(ListNode* head) {
        // Base cases: empty list and single node, nothing to reorder
        if(!head || !head->next)
            return;

        // Get to middle part of list using fast and slow runners
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half of list
        ListNode* prev = nullptr; // severs attachment with first half of list after curr node
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Weave together original list with reversed list in alternating order
        ListNode* curr = head;
        while(prev && prev->next){
            ListNode* currNext = curr->next;        // save curr's neighbor
            curr->next = prev;                      // update curr's next
            curr = prev;                            // update curr
            prev = currNext;                        // update prev
        }
    }
};
