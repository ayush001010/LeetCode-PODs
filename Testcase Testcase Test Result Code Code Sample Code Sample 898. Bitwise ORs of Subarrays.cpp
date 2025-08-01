//OPTIMAL in which we dont need to calculate from the start just ussing prev 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> prev;

        for(int i = 0; i < arr.size(); i++){
            unordered_set<int> curr;
            curr.insert(arr[i]);

            for(int pr : prev){
                curr.insert(pr | arr[i]);
            }
            res.insert(curr.begin(), curr.end());
            prev = curr;
        }
        return res.size();
    }
};

//BETTER no extra space for subarray, all calculation at real time
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int>st;
        for(int i = 0; i < arr.size(); i++){
            int OR = 0;
            for(int j = i; j < arr.size(); j++){
                OR = OR | arr[j];
                st.insert(OR);
            }
        }
        return st.size();
    }
};

//BRUTE first found all subarray, separatly calculated OR for each subarrays and stored these or in the set for getting total number
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<vector<int>> subarr;
        for(int i = 0; i < arr.size(); i++){
            vector<int>temp;
            for(int j = i; j < arr.size(); j++){
                temp.push_back(arr[j]);
                subarr.push_back(temp);
            }
        }

        set<int>st;
        for(auto arry : subarr){
            int OR = 0;
            for(int ar : arry){
                OR = OR | ar;
            }
            st.insert(OR);
        }

        return st.size();
    }
};


/*
Both approaches give the same final set {1,2,3,4,6,7}.
The difference:
You: restart the OR process at each i → many redundant calculations.
Me: only extend previous results → no wasted work.
*/

