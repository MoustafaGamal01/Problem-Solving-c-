/* Time complexity:
O(N)

Space complexity:
O(1)
*/

class Solution {
public:
    bool IsDigit(char ch){
        return (ch >= '0' && ch <= '9');
    }

    int StringToDigit(const string& str, bool sign) {
        long long myNumber = 0;
        for (char c : str) {
            int digit = c - '0';
            myNumber = myNumber * 10 + digit;

            if (!sign && myNumber > INT_MAX) return INT_MAX; // positive overflow
            if (sign && -myNumber < INT_MIN) return INT_MIN; // negative overflow
        }
        return sign ? -myNumber : myNumber;
    }
    int myAtoi(string s) {
        string ans = "";
        bool isNegative = false;
        int i(0);
        // Ignoring white spaces
        while(s[i] == ' ') i++;
        
        // Extracting the sign
        if(s[i] == '-') isNegative = true, i++; // Negative
        else if(s[i] == '+') i++; // Positive
        else if(!IsDigit(s[i])) return 0; // Not a digit or sign
        
        // Extracting the number
        for( ; i < s.size(); i++){
            if(!IsDigit(s[i])) break; // stop if s[i] not a digit
            else ans += s[i];
        }   

        return StringToDigit(ans ,isNegative);          
    }
};