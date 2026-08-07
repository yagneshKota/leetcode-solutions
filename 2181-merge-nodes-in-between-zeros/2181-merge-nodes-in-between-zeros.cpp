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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr= head->next;
        ListNode *ans= new ListNode;
        ans->val = -1;
        ListNode *temp= ans;
        int sum= 0;
        while(curr){
            if(curr->val == 0){
                if(ans->val == -1)
                    ans->val = sum;
                else{
                    ListNode *ptr= new ListNode;
                    ptr->val= sum;
                    ptr->next= NULL;
                    temp->next= ptr;
                    temp= ptr;
                }
                sum = 0;
            }
            sum += curr->val;
            curr= curr->next;
        }
        return ans;
    }
};