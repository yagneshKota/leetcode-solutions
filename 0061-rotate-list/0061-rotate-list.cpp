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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode *last= head;
        ListNode *curr= head;
        int count= 1;

        while(last->next){
            last= last->next;
            count++;
        }
        k %= count;

        if(k == 0) return head;
        last->next= head;
        for(int i= 1; i< (count-k); i++)
            curr= curr->next;

        ListNode *temp= curr->next;
        curr->next= NULL;
        return temp;
    }
};