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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstI= -1;
        int prevI= -1;
        int idx= 1;
        int minDist= INT_MAX;

        ListNode *left= head;
        ListNode *curr= head->next;
        while(curr->next){
            ListNode *right= curr->next;
            if((left->val > curr->val && curr->val < right->val)||
               (left->val < curr->val && curr->val > right->val)){
                if(firstI == -1) firstI= idx;
                else minDist= min(minDist, idx-prevI);
                prevI= idx;

            }
            left= curr;
            curr= right;
            idx++;
        }
        if(firstI == prevI) return {-1, -1};
        return {minDist, prevI- firstI};
    }
};