/*
capacity greater than or equal to the quantity 
fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
*/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(baskets[j] >= fruits[i]){
                    baskets[j] = -1;
                    count++;
                    break;
                }
            }
        }

        return n - count;
    }
};
