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
    void reorderList(ListNode* head) {
        // Base cases: empty list and single node
        if(!head || !head->next)
            return;

        // Get to middle part of list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }

        // Reverse second half of list
        ListNode* prev = nullptr; // severs attachment with first half of list
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
            curr = prev;
            prev = currNext;
        }
    }
};
