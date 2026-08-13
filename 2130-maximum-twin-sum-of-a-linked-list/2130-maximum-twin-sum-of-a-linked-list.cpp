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
    int pairSum(ListNode* head) {
        ListNode *slow= head;
        ListNode *fast= head->next;

        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
        }

        ListNode *prev= NULL;
        ListNode *curr= slow->next;
        slow->next= NULL;

        while(curr){
            ListNode *nextt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nextt;
        }
        curr= prev;
        int ans= INT_MIN;
        while(head && curr){
            int sum= head->val + curr->val;
            ans = max(ans, sum);
            head= head->next;
            curr= curr->next;
        }
        return ans;
    }
};