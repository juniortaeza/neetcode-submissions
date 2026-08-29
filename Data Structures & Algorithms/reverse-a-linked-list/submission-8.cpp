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
    ListNode* reverseList2(ListNode* head) {

/*
        h
   n    o -> o -> o -> o
   p    c    t

        h
   n <- o    o -> o -> o
        p    c    t

        h
   n <- o <- o    o -> o
             p    c    t

        h
   n <- o <- o <- o    o    n
                  p    c    t

        h
   n <- o <- o <- o <- o    n
                       p    c    t
*/

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;

    }

    ListNode* reverseList(ListNode* head) {

        /*
        h
        A -> B -> C -> D
        n

        h    h
        A -> B -> C -> D
             n

        h    h    h
        A -> B -> C -> D
                  n

                    <-
        A -> B -> C  X  D
                  h     n

              <-    <-
        A -> B X  C  X  D
             h          n

          <-    <-    <-
        A  X  B  X  C  X  D
        h                 n
        */

        if(!head)
            return nullptr;

        ListNode* newHead = head;
        if(head->next){
            newHead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
        }
        return newHead;

    }
};
