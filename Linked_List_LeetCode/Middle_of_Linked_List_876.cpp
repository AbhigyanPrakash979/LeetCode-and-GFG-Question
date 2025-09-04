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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        //edge case 1
        if(head == NULL){
            return head;
        }
        // edge case 2
        if(head->next ==NULL){
            return head;
        }

        
        while(slow != NULL && fast != NULL){
            fast = fast-> next;
            if(fast != NULL) {
                fast = fast -> next;
                slow = slow->next;
            }
        }

        return slow;
    }
};