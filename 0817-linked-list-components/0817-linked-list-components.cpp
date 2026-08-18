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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans= 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int count= 0;
        while(head){
            if(s.count(head->val)){
                count++;
            }else if(count>0){
                ans++;
                count= 0;
            }
            head= head->next;
        }
        if(count>0) ans++;
        return ans;
    }
};