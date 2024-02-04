class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& Intervals, vector<int>& newInterval) {
        vector<vector<int>>ans(10001);
        vector<vector<int>>temp;
        Intervals.push_back({ -1,-1 });
        int x = Intervals.size();

        // Insert
        // Simply I used another 2D vector "temp" to push Intervals From the New Interval to the end of Intervals
        // then i Pushed intervals from the "temp" Vector to the "Intervals" Vector from where i stopped (newInterval)
        // Not from the beginning of the Intervals... 
        bool ok(false);
        int j(-1);
        for (int i = 0; i < x; i++) {
            if (newInterval[0] < Intervals[i][0] && !ok) {
                j = i;
                ok = true;
            }
            if (ok && j == i) temp.push_back({ newInterval } ), temp.push_back({ Intervals[i][0],Intervals[i][1] }), j--;
            else if (ok) temp.push_back({ Intervals[i][0],Intervals[i][1] });
        }

        int t(0);
        if (!ok) // the newInterval is the last Interval
            Intervals[x - 1][0] = newInterval[0], Intervals[x - 1][1] = newInterval[1];
        else { 
            // Not the last Interval
            j++;
            t = 0;
            
            for (int i = j; i < x; i++)
                Intervals[i][0] = temp[t][0], Intervals[i][1] = temp[t][1], t++;
        }

        //Merge
        // Just Merging The Intervals that in "Intervals" Vector
        // Like the previous Problem "Merger Intervals"
        t = 0;
        ans[t].push_back(Intervals[0][0]);
        for (int i = 0; i < x - 1; i++) {
            if (Intervals[i][1] >= Intervals[i + 1][0]) {
                if (Intervals[i][1] > Intervals[i + 1][1])
                    Intervals[i + 1][1] = Intervals[i][1];
            }
            else {
                ans[t].push_back(Intervals[i][1]);
                t++;
                ans[t].push_back(Intervals[i + 1][0]);
            }
        }
        ans[t].push_back(Intervals[x - 1][1]);
        ans.resize(t + 1);
        // Return
        return ans;
    }
};
