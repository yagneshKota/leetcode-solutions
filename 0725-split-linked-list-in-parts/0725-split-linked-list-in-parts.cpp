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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp= head;
        int n= 0;
        while(temp){
            temp= temp->next;
            n++;
        }
        int p= n/k;
        int q= n%k;
        vector<ListNode*> ans;
        ListNode *curr= head;
        for(int i= 0; i<k; i++){
            int size= p;
            if(i< q) size++;

            if(size == 0){
                ans.push_back(nullptr);
                continue;
            }
            ListNode *node = curr;
            for(int j=1; j<size; j++){
                curr= curr->next;
            }
            ListNode *nextt= curr->next;
            curr->next= NULL;
            ans.push_back(node);
            curr= nextt;
        }
        return ans;
    }
};