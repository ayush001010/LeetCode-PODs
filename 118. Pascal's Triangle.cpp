/*
what i have used is the, 
1. first i have created res 2d vector
2. prev vector that stores prev stored value
3. using prev, I will calculate the current(temp) sequence
ans updating the prev by temp 
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev = {1};
        res.push_back(prev);
        if(numRows == 1){
            return {{1}};
        }
        else {
            for(int i = 0; i < numRows-1; i++){
                vector<int>temp;
                temp.push_back(1);
                for(int j = 0; j < prev.size()-1; j++){
                    temp.push_back(prev[j] + prev[j+1]);
                }
                temp.push_back(1);
                prev = temp;
                res.push_back(prev);
            }
            return res;
        }
    }
};
