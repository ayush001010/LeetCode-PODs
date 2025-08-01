class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int maxiLen = 0;
        int count = 0;

        for(int n : nums){
            if(n == maxi){
                count++;
                maxiLen = max(count, maxiLen);
            }
            else{
                count = 0;
            }
        }
        
        return maxiLen;
    }
};

/*
📌 Short Note (Intuition)
Bitwise AND only loses 1 bits: adding more numbers can never create new 1s.
The maximum possible AND is the maximum element in the array (maxi).
To keep the AND = maxi, every element in the subarray must equal maxi.
So the problem reduces to finding the longest contiguous block of elements equal to maxi.
*/