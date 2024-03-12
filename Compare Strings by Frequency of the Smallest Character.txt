class Solution {
private:
    int FindFrqOfSmallestChar(string str) {
        int frq[26] = { 0 };
        int mn(INT_MAX);
        
        // finding smallest char
        // and frq for all chars in str
        for (int i = 0; i < str.size(); i++) {
            mn = min(mn, str[i] - 'a');
            frq[str[i] - 'a']++;
        }
        return frq[mn];
    }

public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int x(queries.size()), y(words.size());
        vector<int> wordsFunction, queriesFunction, ans;

        for (int i = 0; i < y; ++i) 
            wordsFunction.push_back(FindFrqOfSmallestChar(words[i]));

        for (int i = 0; i < x; ++i) 
            queriesFunction.push_back(FindFrqOfSmallestChar(queries[i]));

        sort(wordsFunction.begin(), wordsFunction.end());
        for (int i = 0; i < queriesFunction.size(); ++i) {
            auto it = upper_bound(wordsFunction.begin(), wordsFunction.end(), queriesFunction[i]) - wordsFunction.begin();
            ans.push_back(wordsFunction.size() - it);
        }
        return ans;
    }
};