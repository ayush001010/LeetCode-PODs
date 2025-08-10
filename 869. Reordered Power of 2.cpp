/*
Rearranging a number only changes the order of its digits.
To make n into a power of 2, its digits must match some power of 2’s digits exactly.
We don’t need to try every rearrangement — just compare the digits directly.
There are only about 31 powers of 2 under 10^9, so it’s quick to check all of them.
If the digits match for any power of 2, the answer is true.
*/

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());

        for(int i = 0; i < 31; i++){
            int power = 1 << i;
          
            string p = to_string(power);
            sort(p.begin(), p.end());
            if(p == s) return true;
        }
        return false;
    }
};
