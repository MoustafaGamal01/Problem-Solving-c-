class Solution {
public:
    bool IsValid(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch<='9');
    }
    bool isPalindrome(string s) {
        int x(s.size());
        int i(0),j(x-1);
        while(i < j){
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            
            if(IsValid(s[i])){
                if(IsValid(s[j])){
                    if(s[i] == s[j])i++,j--;
                    else return false;
                }
                else j--;
            }
            else i++;
        }
        return true;
    }
};