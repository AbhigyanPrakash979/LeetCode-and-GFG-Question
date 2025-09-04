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

    ListNode* reverse(ListNode* &prev, ListNode* &curr){
        //Base case
        if(curr == NULL){
            return prev;
        }

        
        ListNode* forward = curr-> next;
        curr->next =prev;
        //RR
         return reverse(curr, forward);


    }

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* ans = reverse(prev,curr);
        return ans;
        
    }
};



// // Using Loop
// class Solution {
// public:

//     ListNode* reverseList(ListNode* head) {

//         //check iff LL is empty
//         if(head == NULL){
//             return head;
//         }

//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while(curr != NULL){
//             ListNode* forward = curr-> next;
//             curr-> next =prev;
//             prev= curr;
//             curr= forward;
//         }
//         return prev;
//     }
// };