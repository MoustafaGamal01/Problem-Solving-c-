class Solution {
private: 
    void BackTracking(string digits, vector<string>&ans, vector<string>&phone, string str,
    int i){
        if(i == digits.size()){
            ans.push_back(str);
            return;
        }

        int x = digits[i] - '0';
        string temp = phone[x];

         for(char ch : temp){
            str += ch;
            BackTracking(digits, ans, phone, str, i+1);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        int x = digits.size();
        if(!x) return ans;

        BackTracking(digits, ans, phone, "", 0);
        return ans;
    }
};