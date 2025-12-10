/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) 
        return head;

        // Step 1: prev ko left ke just piche rkhna hai
        ListNode* prev = NULL;
        ListNode* curr = head;
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Step 2: Reverse sublist from left to right
        ListNode* subPrev = NULL;
        ListNode* subTail = curr; // will become tail of reversed sublist
        // HUm yahi pr right-left tak reverse krdenge
        for (int i = 0; i <= right - left; i++) {
            ListNode* temp = curr->next;
            curr->next = subPrev;
            subPrev = curr;
            curr = temp;
        }

        // Step 3: Reconnect krne pedga prev ke next se 
        // aur curr->next to curr se
        if (prev != NULL) {
            prev->next = subPrev;   // connect node before 'left' to new head of sublist
        }
        else {
            // agr left alaerady head pr khada ho
            head = subPrev;         // if left == 1, update head
        }
        subTail->next = curr;       // connect tail of reversed sublist to node after 'right'

        return head;
    }
};