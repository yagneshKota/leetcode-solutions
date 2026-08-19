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
    ListNode* removeNodes(ListNode* head) {
    if(!head || !head->next) return head;
        ListNode *prev= NULL;
        ListNode *curr= head;
        while(curr){
            ListNode *nextt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextt;
        }
        head= prev;
        int maxi= prev->val;
        curr= prev;
        while(curr && curr->next){
            if(curr->next->val < maxi)
                curr->next= curr->next->next;
            else{
                curr= curr->next;
                maxi= curr->val;
            }
        }
        prev= NULL;
        curr= head;
        while(curr){
            ListNode *nextt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextt;
        }
        return prev;
    }
};