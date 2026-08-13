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
        ListNode *ans = new ListNode;
        ListNode *dummy= ans;
        int sum = 0, carry= 0;
        while(l1 && l2){
            sum= carry;
            sum = sum + l1->val+ l2->val;
            ListNode *node= new ListNode(sum%10);
            ans->next= node;
            ans= ans->next;
            l1= l1->next;
            l2= l2->next;
            carry= sum/10;
        }
        while(l1){
            sum= carry;
            sum += l1->val;
            ListNode *node= new ListNode(sum%10);
            ans->next= node;
            ans= ans->next;
            l1= l1->next;
            carry= sum/10;
        }
        while(l2){
            sum= carry;
            sum += l2->val;
            ListNode *node= new ListNode(sum%10);
            ans->next= node;
            ans= ans->next;
            l2= l2->next;
            carry= sum/10;
        }
        if(carry != 0){
            ListNode *node = new ListNode(carry);
            ans->next= node;
        }
        return dummy->next;
    }
};