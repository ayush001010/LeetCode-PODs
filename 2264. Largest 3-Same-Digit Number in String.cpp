class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        vector<char>ch;
        for(int i = 0; i < num.size()-2; i++){
            char f = num[i];
            char s = num[i+1];
            char t = num[i+2];

            if(f == s && s == t && f == t){
                ch.push_back(f);
            }
        }
        if (ch.empty()) return res;
        sort(ch.begin(), ch.end());
        res = string(3, ch.back());
        return res;
    }
};
