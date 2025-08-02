/*
📘 Rearranging Fruits — Intuition (Short Note)
Check feasibility: Every fruit must appear an even number of times → else return -1.
Target count: Each fruit → half of its total count per basket.
Find extras: Collect leftovers from both baskets → extra1 (asc), extra2 (desc).

Globally cheapest fruit:
minFruit = min(all fruits);

Two swap options per pair (a,b):
Direct: min(a,b)
Indirect (bridge via minFruit): 2*minFruit

Formula:
cost += min(min(a,b), 2*minFruit);
Intuition: Use the cheapest fruit as a bridge when direct swaps are too costly.
*/

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for(int b : basket1)
           freq[b]++; 
        for(int b : basket2)
            freq[b]++;

        for(auto [fruit, cost] : freq){
            if(cost % 2 != 0)
                return -1;
        }

        unordered_map<int, int> need;
        for(auto [fruit, cost] : freq){
            need[fruit] = cost / 2; 
        }

        unordered_map<int, int> need1 = need;
        unordered_map<int, int> need2 = need;
        vector<int> extra1;
        vector<int> extra2;
        for(auto b : basket1){
            if(need1[b] > 0){
                need1[b]--;
            }
            else{
                extra1.push_back(b);
            }
        }
        for(auto b : basket2){
            if (need2[b] > 0){
                need2[b]--;
            }
            else{
                extra2.push_back(b);
            }
        }
        
        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());

    
        int minFruit = INT_MAX;
        for (auto [fruit, _] : freq) {
            minFruit = min(minFruit, fruit);
        }

        long long cost = 0;
        int m = extra1.size(); 
        for (int i = 0; i < m; i++) {
            int a = extra1[i];
            int b = extra2[i];
            cost += min((long long)min(a, b), 2LL * minFruit);
        }

        return cost;

    }
};

//BRUTE AND WORKABLE
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        long long cost = INT_MAX;
        set<int> st1;
        set<int> st2;
        for(int b: basket1){
            st1.insert(b);
        }
        for(int b: basket2){
            st2.insert(b);
        }
        
        if(st1.size() == st2.size() && st1 != st2){
            return -1;
        }
        else{
            for(auto x : st1){
                long long mini;
                if(st2.find(x) == st2.end()){
                    mini = x;
                    cost = min(mini, cost);
                }
            }
            for(auto x : st2){
                long long mini;
                if(st1.find(x) == st1.end()){
                    mini = x;
                    cost = min(mini, cost);
                }
            }

            return cost;
        }
    }
};

//[4,4,4,4,3] [5,5,5,5,3]
