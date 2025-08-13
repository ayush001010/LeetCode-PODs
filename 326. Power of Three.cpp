/*
1. using loop condition... O(n)
2. dividing largert number with n if == 0, its x exist;
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n > 1){
            if(n % 3 != 0) return false;
            n = n / 3;
        }
        return true;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && (int)pow(3, 19) % n == 0; 
    }
};
