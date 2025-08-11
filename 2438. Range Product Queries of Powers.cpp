/*
The problem says:
1. Decompose n into the powers of 2 that sum to n;
    n = 10 i.e [2, 8] 
    n = 15 i.e [1, 2, 4, 8] ... bothering only set bits;

2. This is exactly the binary representation:
    If a bit is set → that power of 2 is part of the sum;
    If a bit is not set → that power is not part of the sum;
    
3. One more question that can frame is for all 2's power, sum should be n.
    if the 2's power;
*/
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> ans;
        vector<int> power;

        // Extract only set-bit powers of n
        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) {
                power.push_back(1 << i);
            }
        }

        // Answer queries
        for (auto &q : queries) {
            int x = q[0];
            int y = q[1];
            long long prod = 1;
            for (int i = x; i <= y; i++) {
                prod = (prod * power[i]) % MOD; 
            }
            ans.push_back(prod);
        }
        return ans;
    }
};
