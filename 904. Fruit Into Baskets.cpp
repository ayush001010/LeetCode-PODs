/*
📌 Key Intuition
Use a sliding window with l and r.
Expand r to include new fruits.
If we exceed 2 types, shrink from the left until we’re back to ≤2.
Track the maximum window size.
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> basket;
        int l = 0;
        int maxi = 0;

        for(int r = 0; r < n; r++){
            basket[fruits[r]]++;

            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};
