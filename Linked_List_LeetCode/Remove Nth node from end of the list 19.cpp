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
    int position(ListNode* &head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* solve(ListNode* head, int del){
        if(head == NULL) return NULL;

        // Case 1: delete head
        if(del == 1){
            ListNode* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            // always remember to return head
            return head;
        }

        // Case 2: delete non-head node
        int i = 1;
        ListNode* prev = head;
        while(i < del - 1){
            prev = prev->next;
            i++;
        }

        ListNode* curr = prev->next;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        // always remember to return head;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int pos = position(head);
        int del = pos + 1 - n;  // main cheez yahi hai
        return solve(head, del);
    }
};
