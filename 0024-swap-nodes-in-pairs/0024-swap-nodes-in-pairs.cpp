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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *odd= head;
        ListNode *even= head->next;
        head= head->next;
        ListNode *prev= NULL;
        while(even){
            odd->next= even->next;
            even->next= odd;

            if(prev) prev->next= even;

            prev= odd;
            odd= odd->next;
            if(odd== NULL || odd->next== NULL) break;
            even= odd->next;

        }
        return head;
    }
};