class Solution {
public:
    string customSortString(string order, string s) {
        int arr2[26] = {0};
        int arr1[26] = {0};
        for(int i = 0; i < s.size(); i++) arr2[s[i]-'a']++;
        for(int i = 0; i < order.size(); i++) arr1[order[i]-'a']++;

        string ans="", temp="";
        for(int i = 0; i < order.size(); i++){
            while(arr2[order[i]-'a']--)
                ans+=order[i];
        }

        for(int i = 0; i < s.size(); i++)
            if(arr1[s[i]-'a'] == 0) temp+=s[i];

        return ans+=temp;
    }
};