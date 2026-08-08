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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr= head;
        ListNode *last= head;
        
        for(int i= 0; i<n; i++)
            last= last->next;

        if(last == NULL){
            ListNode *temp= head;
            head= head->next;
            delete temp;
            return head;
        } 

        while(last->next){
            curr= curr->next;
            last= last->next;
        }
        ListNode *temp= curr->next;
        curr->next= temp->next;
        delete temp;

        return head;
    }
};