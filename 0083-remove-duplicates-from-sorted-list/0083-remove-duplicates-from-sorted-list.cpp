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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        int num= head->val;
        ListNode *curr= head;
        ListNode *prev= head;
        curr= curr->next;
        while(curr){
            if(curr->val == num){
                ListNode *temp= curr;
                curr= curr->next;
                prev->next= curr;
                delete temp;
            }
            else{
                num= curr->val;
                curr= curr->next;
                prev= prev->next;
            }
        }
        return head;
    }
};