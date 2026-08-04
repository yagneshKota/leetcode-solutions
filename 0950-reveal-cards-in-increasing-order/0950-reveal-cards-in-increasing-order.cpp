class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        sort(deck.begin(), deck.end(), greater<int>());

        deque<int> dp;
        dp.push_front(deck[0]);
        for(int i= 1; i<n; i++){
            dp.push_front(dp.back());
            dp.pop_back();
            dp.push_front(deck[i]);
        }

        vector<int> ans(n);
        for(int i= 0; i<n; i++){
            ans[i]= dp.front();
            dp.pop_front();
        }
        return ans;
    }
};