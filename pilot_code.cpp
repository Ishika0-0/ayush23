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
        ListNode* d = new ListNode(0, NULL);
        ListNode* temp = d;
        int sum = 0;
        int carry = 0;
        while(l1 || l2){
            if(l1 && l2){
                sum = carry + l1->val + l2->val;
                l1=l1->next;
                l2=l2->next;
            }
            else if(!l1 && l2){
                sum = carry + l2->val;
                l2=l2->next;
            }
            else if(l1 && !l2){
                sum = carry + l1->val;
                l1=l1->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode* curr = new ListNode(sum, NULL);
            temp -> next = curr;
            temp = temp->next;
        }
        if(carry){
            ListNode* curr = new ListNode(carry, NULL);
            temp -> next = curr;
            temp = temp->next;
        }
        return d->next;
    }
};
