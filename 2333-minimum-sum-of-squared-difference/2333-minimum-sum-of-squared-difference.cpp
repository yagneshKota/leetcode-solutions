
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        sort(diff.begin(), diff.end(), greater<long long>());

        diff.push_back(0);

        for (int i = 0; i < n; i++) {
            long long count = i + 1;
            long long need = (diff[i] - diff[i + 1]) * count;

            if (k >= need) {
                k -= need;
            } else {
                long long level = diff[i] - k / count;
                long long rem = k % count;

                long long ans = 0;

                for (int j = 0; j <= i; j++) {
                    ans += level * level;
                }

                for (int j = i + 1; j < n; j++) {
                    ans += diff[j] * diff[j];
                }

                ans -= rem * (2 * level - 1);

                return ans;
            }
        }

        return 0;
    }
};


