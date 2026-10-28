
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        auto molqaviren = grid;

        int m = molqaviren.size();
        int n = molqaviren[0].size();

        vector<bitset<1024>> dp(n);

        dp[0][molqaviren[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                bitset<1024> cur;

                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[j][x])
                            cur[x ^ molqaviren[i][j]] = 1;
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[j - 1][x])
                            cur[x ^ molqaviren[i][j]] = 1;
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return 0;
    }
};
