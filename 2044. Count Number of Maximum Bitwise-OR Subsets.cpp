/* 
My intuition is that i create all subarrays and for all find maximum OR val and for that maxi val counting how many have that maxi val
1. using backtracking - creating all subsets
2. finding maximum OR value in all subsets
3. counting for that maximum OR value
 */
class Solution {
private:
    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int start){
        res.push_back(temp);
        for(int i = start; i < nums.size(); i++){
            temp.push_back(nums[i]);
            helper(nums, temp, res, i+1);
            temp.pop_back();
        }
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        vector<vector<int>> res;
        vector<int>temp;
        helper(nums, temp, res, 0);
        for(auto num : res){
            int OR = 0;
            for(int n : num){
               OR |= n; 
            }
            maxi = max(OR, maxi);
        }
        int count = 0;
        for(auto num : res){
            int OR = 0;
            for(int n : num){
               OR |= n; 
            }
            if(OR == maxi) count++;
        }
        return count;
        
    }
};

/*  
👉 Instead of explicitly building subsets, we simulate "inclusion/exclusion" decisions while carrying forward the OR value. At the end of each path, we check if it equals the global maximum OR.
*/

class Solution {
private:
    int maxOr = 0;
    int count = 0;

    void dfs(vector<int>& nums, int index, int curOr) {
        if (index == nums.size()) {
            if (curOr == maxOr) count++;
            return;
        }
        // choice 1: include nums[index]
        dfs(nums, index + 1, curOr | nums[index]);
        // choice 2: exclude nums[index]
        dfs(nums, index + 1, curOr);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        for (int x : nums) maxOr |= x; // Step 1: compute max OR
        dfs(nums, 0, 0);               // Step 2: DFS
        return count;                  // Step 3: return result
    }
};
