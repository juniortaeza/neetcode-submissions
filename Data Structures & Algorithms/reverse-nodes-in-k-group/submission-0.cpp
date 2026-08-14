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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;

        vector<ListNode*> groups;
        ListNode* curr = head;
        int cnt = 1;
        while(curr){
            if(cnt == k){
                ListNode* next = curr->next;
                curr->next = nullptr;
                groups.push_back(head);
                head = next;
                curr = head;
                cnt = 1;
            } else {
                curr = curr->next;
                cnt += 1;
            }
        }

        for(int i = 0; i < groups.size(); i++)
            groups[i] = reverseList(groups[i]);

        ListNode* merged = new ListNode();
        ListNode* ptr = merged;
        
        for(ListNode* n : groups){
            while(n){
                ptr->next = n;
                n = n->next;
                ptr = ptr->next;
            }
        }

        ptr->next = head;
        return merged->next;
    }
};
