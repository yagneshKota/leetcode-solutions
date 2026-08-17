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
        ListNode *prev= NULL;
        ListNode *curr= l1;
        while(curr){
            ListNode *nextt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextt;
        }
        l1= prev;

        prev= NULL;
        curr= l2;
        while(curr){
            ListNode *nextt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextt;
        }
        l2= prev;

        ListNode *ans= NULL;
        
        int carry= 0;
        while(l1 || l2|| carry){
            int sum= carry;
            if(l1){
                sum += l1->val;
                l1= l1->next;
            }
            if(l2){
                sum += l2->val;
                l2= l2->next;
            }
            ListNode *node= new ListNode(sum%10);
            node->next= ans;
            ans= node;
            carry= sum/10;
        }
        return ans;
    }
};