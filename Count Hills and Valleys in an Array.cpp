/*
Think/s i have learned 
how to deal with the question in which it has been asked to ignore equal element and compare with un-equal nums 
*/
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        
        for(int i = 1; i < nums.size()-1; i++){
            if(nums[i-1] ==  nums[i]) continue;
            
            int left = i - 1;
            while(left >= 0 && nums[left] == nums[i]) left--;
            int right = i + 1;
            while(right < nums.size() && nums[right] == nums[i]) right++;

            if(left >= 0 && right < nums.size()){
                if(nums[left] < nums[i] && nums[i] > nums[right]) count++;
                else if(nums[left] > nums[i] && nums[i] < nums[right]) count++;
            }

        }
        return count;
    }
};