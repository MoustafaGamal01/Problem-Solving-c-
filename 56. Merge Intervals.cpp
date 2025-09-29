// Author: Moustafa Gamal
// Time Complexity: O(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int l(0), r(1), x = intervals.size();
        if(x == 1) return intervals;

        while(r < x){
            if(intervals[r][0] > intervals[r-1][1]) // non-overlapping intervals
                ans.push_back({intervals[l][0], intervals[r-1][1]}), l = r; // push this interval and move forward
            else if(intervals[r][0] <= intervals[r-1][1] && intervals[r][1] <= intervals[r-1][1]) // if they are overlapping and the first interval is the mutual interval ex: [[1, 5], [2, 4]]
                intervals[r][1] = intervals[r-1][1]; // change the end of the second interval: [[1,5], [2,4]] ==> [[1,5], [2,5]]
            r++;
        }
        ans.push_back({intervals[l][0], intervals[r-1][1]}); // push the last interval we have exactly before ending the "while loop"
        return ans;
    }
};