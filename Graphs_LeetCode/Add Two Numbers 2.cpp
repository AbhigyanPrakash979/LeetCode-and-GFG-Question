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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //base case 1
        //if list1 is empty
        if(l1 == NULL){
            return l2;
        }
        //base case 2
        if(l2== NULL){
            return l1;
        }
        // iss questions mein alerady reverse krra hua hai//
        // isliye yahn reverse ki need nhi hai
        
        // create a pointer to store answer
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        //ab loop chalo carry, sum, add aur traverse krne ke liye
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int sum = carry + l1->val +l2 ->val;
            int digit = sum%10;
            carry = sum/10;

            //ab digit ki newNode bnana hai
            ListNode* newNode = new ListNode(digit);

            //check ki pehli node hai add krne ko
            if(ansHead == NULL){
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                // ansTail ke end mein lgado
                ansTail->next = newNode;
                ansTail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        // for list1 if it remains
        while(l1 != NULL){
            int sum = carry + l1->val;
            int digit = sum%10;
            carry = sum/10;

            //ab digit ki newNode bnana hai
            ListNode* newNode = new ListNode(digit);

            //check ki pehli node hai add krne ko
            if(ansHead == NULL){
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                // ansTail ke end mein lgado
                ansTail->next = newNode;
                ansTail = newNode;
            }
            //list 1 ko aage badha do
            l1 = l1->next;
        }
        //for list2 if it remains
        while(l2 != NULL){
            int sum = carry + l2->val;
            int digit = sum%10;
            carry = sum/10;

            //ab digit ki newNode bnana hai
            ListNode* newNode = new ListNode(digit);

            //check ki pehli node hai add krne ko
            if(ansHead == NULL){
                ansHead = newNode;
                ansTail = newNode;
            }
            else{
                // ansTail ke end mein lgado
                ansTail->next = newNode;
                ansTail = newNode;
            }
            // list 2 ko aage badha do
            l2 = l2->next;
        }
        // agar mein agar carry reh gya ho
        while(carry != 0){
            int sum = carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* newNode = new ListNode(digit);
            ansTail -> next = newNode;
            ansTail = newNode;
        }
        return ansHead;
    }
};