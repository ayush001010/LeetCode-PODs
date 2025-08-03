class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int left = 0, ans = 0;
        long long sum = 0;

        // sliding window
        for (int right = 0; right < n; right++) {
            sum += fruits[right][1];

            // shrink window if it's not reachable within k steps
            while (left <= right && min(abs(startPos - fruits[left][0]), abs(startPos - fruits[right][0])) + 
            (fruits [right][0] - fruits[left][0]) > k) {
                sum -= fruits[left][1];
                left++;
            }

            ans = max(ans, (int)sum);
        }

        return ans;
    }
};
