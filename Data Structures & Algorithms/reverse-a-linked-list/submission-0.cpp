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

/*

                      p    c
  N <- 0 <- 1 <- 2 <- 3 -> N
       h

    - think about base cases
    - create prev and curr pointers
    - while curr has not fallen off list
        - store current's original next neighbor
        - sever attachment to next neighbor and point at prev
        - update prev
        - update curr
    - return prev -> new head of reversed list

*/

    // T: O(n) -> where n is the size of the input list
    // S: O(1) -> where no extra memory was allocated
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !head->next)
    //         return head;

    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;
    //     while(curr){
    //         ListNode* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }

    //     return prev;
    // }

    /*
        Recursive Types:
            - Head Recursion: recurse first, then process
            - Tail Recusion:  process first, then recurse

        1 -> 2 -> 3 -> NULL ->
                  ^
                  newHead

    NULL <- 1 <- 2 <- 3
                      ^
                      newHead

        3 -> done processing
        2 -> done processing
        1 -> done processing
    */
    // T: O(n) -> recursing to very end of list
    // S: O(n) -> recursive stack will be size of list
    ListNode* reverseList(ListNode* head){
        // base cases - when list is empty or current node's head is null
        if(!head)       return head;
        if(!head->next) return head;

        // head recursion - recurse first to end of list
        ListNode* newHead = reverseList(head->next);

        // unwind the stack, updating pointers
        head->next->next = head;
        head->next = nullptr;

        // return updated newHead
        return newHead;
    }
};




