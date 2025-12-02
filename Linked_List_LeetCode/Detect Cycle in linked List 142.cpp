/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // base case
        if (head == NULL) {
            return NULL;
        }

        // relation
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL ) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }

            if (slow == fast) {
                slow = head; // slow ko phirse head se shuru krdo
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                // starting point mil gya
                return slow;
            }
        }

        return NULL; // cycle nahi mila
    }
};
