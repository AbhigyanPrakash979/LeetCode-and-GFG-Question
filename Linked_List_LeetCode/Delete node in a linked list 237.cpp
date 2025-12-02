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
            void deleteNode(ListNode* node) {

            node->val = node->next->val;             //  Copy value from next node
            ListNode* temp = node->next;             // Step 2: Store pointer to next node
            node->next = node->next->next;           // Step 3: Skip over the next node
            delete temp;                             // Step 4: Free memory of skipped node
        }

    };